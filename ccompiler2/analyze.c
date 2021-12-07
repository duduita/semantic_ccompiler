/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;
static int level = 0;

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by t
 */

static void traverse(TreeNode *t,
                     void (*preProc)(TreeNode *),
                     void (*postProc)(TreeNode *))
{
  if (t != NULL)
  {
    // printf("level: %d\n", level);
    // printf("kindstmt: %d, level: %d\n", t->kind.stmt, level);
    if (t->stmtType == Comp_decl || t->kind.stmt == WhileK || t->kind.stmt == IfK)
    {
      level++;
    }
    preProc(t);
    {
      int i;
      for (i = 0; i < MAXCHILDREN; i++)
        traverse(t->child[i], preProc, postProc);
    }
    postProc(t);
    if (t->stmtType == Comp_decl || t->kind.stmt == WhileK || t->kind.stmt == IfK)
    {
        st_remove(level);
      level--;
    }
    traverse(t->sibling, preProc, postProc);
  }
}

/* nullProc is a do-nothing procedure to
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode *t)
{
  if (t == NULL)
    return;
  else
    return;
}

/* Procedure insertNode inserts
 * identifiers stored in t into
 * the symbol table
 */
static void insertNode(TreeNode *t)
{
  switch (t->nodekind)
  {
  case StmtK:
    switch (t->kind.stmt)
    {
    // case AssignK:
    //   if (st_lookup(t->attr.name) == -1)
    //     /* not yet in table, so treat as new definition */
    //     st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, lineno, location++, level);
    //   else
    //     /* already in table, so ignore location,
    //        add line number of use only */
    //     st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, t->lineno, 0, level);
    //   break;
    default:
      break;
    }
    break;
  case ExpK:
    switch (t->kind.exp)
    {
    // case AssignK:
    //   st_set_attribute(t->attr.name, level, t->lineno);
    //   break;
    case IdK:
      if (st_lookup(t->attr.name) == -1) /* not yet in table, so treat as new definition */
      {
        // CASO 3: Declaração de variável tipo void
        if (t->type == 0 && t->stmtType == 0)
          printf("ERRO SEMÂNTICO: %s, LINHA: %d\n", t->attr.name, t->lineno);
        else
          st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, t->lineno, location++, level);
      }
      else
        /* already in table, so ignore location,
           add line number of use only */
        st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, t->lineno, 0, level);
      break;
    case OpK:
      if (t->attr.op == ASSIGN)
      {
        // CASO 5: Chamada de função não declarada
        if (t->child[1]->stmtType == Function && st_lookup(t->child[1]->attr.name) == -1)
        {
          printf("ERRO SEMÂNTICO [Chamada de função não declarada!]");
        }

        if (st_lookup(t->child[0]->attr.name) == -1) /* not yet in table, so treat as new definition */
          printf("ERRO SEMÂNTICO: %s, LINHA: %d\n", t->child[0]->attr.name, t->child[0]->lineno);
        else
        {
          // printf("tipo filho[0]: %s, tipo filho[1]: %s\n", t->child[0]->attr.name, t->child[1]->attr.name);

          if (level == 0 || st_declared(t->child[0]->attr.name, level))
          {
            // printf("tipo filho[0]: %d, tipo filho[1]: %d\n", t->child[0]->type, t->child[1]->type);
            // tipo do filho 0 = obtem_atributo(filho0, tipo);
            // tipo do filho 1 = obtem_atributo(filho1, tipo);
            // tipo do filho 0 = tipo do filho 1? se for, brazil, se nao for, tomou
            if (t->child[0]->type == t->child[1]->type)
            {
              // printf("tipo filho[0]: %d, tipo filho[1]: %d\n", t->child[0]->type, t->child[1]->type);
              // st_set_attributeKC(t->child[0]->attr.name, t->child[1]->attr.val);
            }
            else
            {
              // printf("tipo filho[0]: %d, tipo filho[1]: %d\n", t->child[0]->type, t->child[1]->type);
              printf("ERRO SEMÂNTICO: %s, LINHA: %d\n", t->child[0]->attr.name, t->child[0]->lineno);
            }
          }
        }
      }
      /* already in table, so ignore location,
         add line number of use only */
      // st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, t->lineno, 0, level);
      break;
    default:
      break;
    }
    break;
  default:
    break;
  }
}

/* Function buildSymtab constructs the symbol
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode *syntaxTree)
{
  traverse(syntaxTree, insertNode, nullProc);
  if (TraceAnalyze)
  {
    fprintf(listing, "\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode *t, char *message)
{
  fprintf(listing, "Type error at line %d: %s\n", t->lineno, message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode *t)
{
  switch (t->nodekind)
  {
  case ExpK:
    switch (t->kind.exp)
    {
    case OpK:
      if ((t->child[0]->type != Integer) ||
          (t->child[1]->type != Integer))
        typeError(t, "Op applied to non-integer");
      if ((t->attr.op == EQ) || (t->attr.op == LT))
        t->type = Boolean;
      else
        t->type = Integer;
      break;
    case ConstK:
    case IdK:
      t->type = Integer;
      break;
    default:
      break;
    }
    break;
  case StmtK:
    switch (t->kind.stmt)
    {
    case IfK:
      if (t->child[0]->type == Integer)
        typeError(t->child[0], "if test is not Boolean");
      break;
    case AssignK:
      if (t->child[0]->type != Integer)
        typeError(t->child[0], "assignment of non-integer value");
      break;
    // case WriteK:
    //   if (t->child[0]->type != Integer)
    //     typeError(t->child[0],"write of non-integer value");
    //   break;
    // case RepeatK:
    //   if (t->child[1]->type == Integer)
    //     typeError(t->child[1],"repeat test is not Boolean");
    //   break;
    default:
      break;
    }
    break;
  default:
    break;
  }
}

/* Procedure typeCheck performs type checking
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode *syntaxTree)
{
  traverse(syntaxTree, nullProc, checkNode);
}
