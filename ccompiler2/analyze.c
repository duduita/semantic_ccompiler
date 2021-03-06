/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the C- compiler                              */
/* CES41 - Instituto Tecnológico de Aeronáutica     */
/* Alunos:                                          */
/* Eduardo Menezes, Matheus Martins e Rodrigo Souza */
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
		preProc(t);
		if (t->composto == 1)
		{
			level++;
		}
		{
			int i;
			for (i = 0; i < MAXCHILDREN; i++)
				traverse(t->child[i], preProc, postProc);
		}
		postProc(t);
		if (t->composto == 1)
		{
			printf("%s removido\n", t->attr.name);
			// st_remove(level);
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
		case IntK:
		{
			BucketList p = st_search(t->child[0]->attr.name);
			if (p && p->stmtType != Function && level == p->level)
				printf("ERRO SEMÂNTICO CASO 4: %s, LINHA: %d\n", t->attr.name, t->lineno);
			break;
		}
		default:
			break;
		}
		break;
	case ExpK:
		switch (t->kind.exp)
		{
		case IdK:
			printf("analisando nó %s\n", t->attr.name);
			if (st_lookup(t->attr.name) == -1) /* not yet in table, so treat as new definition */
			{
				printf("nó %s não encontrado. Adicionando...\n", t->attr.name);
				{
					// CASO 3: Declaração de variável tipo void
					if (t->type == 0 && t->stmtType == 0)
						printf("ERRO SEMÂNTICO CASO 3: %s, LINHA: %d\n", t->attr.name, t->lineno);
					else
						st_insert(t->attr.name, t->type, t->stmtType, t->attr.val, t->lineno, location++, level);
				}
				printf("level: %d, adicionou?: %d\n", level, st_lookup(t->attr.name) != -1);
			}
			else
			{
				printf("nó %s presente na tabela\n", t->attr.name);
				// CASO 7: Declaração inválida! Nome já foi declarado como nome de função
				BucketList l = st_search(t->attr.name);
				if (t->type == Integer && l->stmtType == Function)
					printf("ERRO SEMÂNTICO CASO 7: %s, LINHA: %d\n", t->attr.name, t->lineno);
			}
			break;
			/* already in table, so ignore location,
		 add line number of use only */
		case OpK:
			if (t->attr.op == ASSIGN)
			{
				// CASO 5: Chamada de função não declarada
				if (t->child[1]->type != Integer)
				{
					BucketList l = st_search(t->child[1]->attr.name);
					if (l == NULL)
					{

						printf("ERRO SEMÂNTICO CASO 5: %s, LINHA: %d\n", t->child[1]->attr.name, t->child[1]->lineno);
					}
				}

				if (st_lookup(t->child[0]->attr.name) == -1) /* not yet in table, so treat as new definition */
					printf("ERRO SEMÂNTICO CASO 1: %s, LINHA: %d\n", t->child[0]->attr.name, t->child[0]->lineno);
				else
				{
					int is_declared = st_declared(t->child[0]->attr.name, level);
					if (level == 0 || st_declared(t->child[0]->attr.name, level))
					{
						if (t->child[0]->type == t->child[1]->type)
						{
							BucketList p = st_search(t->child[0]->attr.name);
						}
						else
							printf("ERRO SEMÂNTICO CASO 2: %s, LINHA: %d\n", t->child[0]->attr.name, t->child[0]->lineno);
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
	BucketList l = st_search("main");
	if (l == NULL || (l == NULL && l->stmtType == 0))
	{
		// CASO 6: Função main() não declarada
		printf("ERRO SEMÂNTICO CASO 6: Função main não declarado\n");
	}
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
			if (t->child[0] && (t->child[0]->type == Integer) && (t->child[1] && t->child[1]->type == Integer))
			{
				if (t->child[0]->child[0] != NULL ^ t->child[1]->child[0] != NULL)
					typeError(t, "Op applied to non-integer");
			}
			else
				typeError(t, "Op applied to non-integer");
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
