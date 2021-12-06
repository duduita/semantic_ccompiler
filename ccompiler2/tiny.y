/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/


%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static int savedDec;
static char * savedName; /* for use in assignments */
static ExpType savedExpType;
static StmtType savedStmtType;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}

%token IF ELSE ASSIGN RETURN WHILE INT  VOID
%token EQ LT PLUS LTE GT GTE DIFF MINUS TIMES OVER  
%token ID NUM
%token LPAREN RPAREN LBRACES RBRACES LBRACK RBRACK
%token COMMA SEMI
%token ERROR

%% /* Grammar for TINY */

// programa → declaração-lista
programa            : declaracao_lista
                        { savedTree = $1; } 
                    ;

// declaração-lista → declaração-lista declaração | declaração
declaracao_lista    : declaracao_lista declaracao
                        { 
                          YYSTYPE t = $1;
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                          } else $$ = $2;
                        }
                    | declaracao
                        { $$ = $1; }
                    ;

// declaração → var-declaração | fun-declaração
declaracao          : var_declaracao
                        { $$ = $1; }
                    | fun_declaracao
                        { $$ = $1; }
                    | error
                        { $$ = NULL; }
                    ;

id                  : ID
                        { 
                          savedName = copyString(tokenString);
                          savedLineNo = lineno; 
                        }
                    ;

num                 : NUM
                        {
                          savedDec = atoi(tokenString);
                          savedLineNo = lineno; 
                        }
                    ;

// tipo-especificador → int | void
tipo_especificador  : INT 
                        { 
                          $$ = newStmtNode(IntK);
                          savedExpType = Integer;
                         }
                    | VOID
                        { 
                          $$ = newStmtNode(VoidK); 
                          savedExpType = Void;  
                        }
                    ;
                    

// var-declaração → tipo-especificador ID ; | tipo-especificador ID [ NUM ] ;
var_declaracao      : tipo_especificador id
                        { 
                          $$ = $1;
                          $$->child[0] = newExpNode(IdK);
                          $$->child[0]->attr.name = savedName;
                          $$->child[0]->type = savedExpType;
                          $$->child[0]->stmtType = Variable;
                          $$->lineno = savedLineNo;
                        } SEMI
                    | tipo_especificador id
                        {
                          $$ = $1;
                          $$->child[0] = newExpNode(IdK);
                          $$->child[0]->attr.name = savedName;
                          $$->child[0]->type = savedExpType;
                          $$->child[0]->stmtType = Variable;
                          $$->lineno = savedLineNo;
                        }
                      LBRACK
                        {
                          $$ = $1->child[0];
                          $$->child[0] = newExpNode(OpK);
                          $$->child[0]->attr.op = LBRACK;
                        }
                      num
                        {
                          $$ = $1->child[0];
                          $$->child[1] = newExpNode(ConstK);
                          $$->child[1]->attr.val = savedDec;
                        }
                      RBRACK
                        {
                          $$ = $1->child[0];
                          $$->child[0] = newExpNode(OpK);
                          $$->child[0]->attr.op = RBRACK;
                        }  
                      SEMI
                    ;

// fun-declaração → tipo-especificador ID ( params ) composto-decl
fun_declaracao      : tipo_especificador id
                        {
                          $$ = $1;
                          $$->lineno = savedLineNo;
                          $$->child[0] = newExpNode(IdK);
                          $$->child[0]->attr.name = savedName;
                          $$->child[0]->type = savedExpType;
                          $$->child[0]->stmtType = Function;
                        } 
                      LPAREN params RPAREN composto_decl
                        {
                          $$ = $3;
                          $$->child[0]->child[0] = $5;
                          $$->child[0]->child[1] = $7;
                        }
                    ;

// params → param-lista | void
params              : param_lista
                        { $$ = $1; }
                    | VOID
                        { $$ = NULL; }
                    ;

// param-lista → param-lista, param | param
param_lista         : param_lista COMMA param
                        { 
                          YYSTYPE t = $1;
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $3;
                            $$ = $1;
                          } else $$ = $3;
                        }
                    | param
                        { $$ = $1; }
                    ;

// param → tipo-especificador ID | tipo-especificador ID [ ]
param               : tipo_especificador id 
                        {
                          $$ = $1;
                          $$->lineno = savedLineNo;
                          $$->child[0] = newExpNode(IdK);
                          $$->child[0]->attr.name = savedName;
                          $$->child[0]->type = savedExpType;
                          $$->child[0]->stmtType = Variable;
                        }
                    | tipo_especificador id 
                        {
                          $$ = $1;
                          $$->lineno = savedLineNo;
                          $$->child[0] = newExpNode(IdK);
                          $$->child[0]->attr.name = savedName;
                          $$->child[0]->type = savedExpType;
                          $$->child[0]->stmtType = Variable;
                        }
                      LBRACK RBRACK  
                    ;

// composto-decl → { local-declarações statement-lista }
composto_decl       : LBRACES local_declaracoes statement_lista RBRACES
                        {
                          YYSTYPE t = $2;
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $3;
                            $$ = $2;
                          } else $$ = $3;
                        }   
                    ;  

// local-declarações → local-declarações var-declaração | vazio
local_declaracoes   : local_declaracoes var_declaracao
                        { 
                          YYSTYPE t = $1;
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                          } else $$ = $2;
                        }
                    | { $$ = NULL; }
                    ;

// statement-lista → statement-lista statement | vazio
statement_lista     : statement_lista statement
                        { 
                          YYSTYPE t = $1;
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $2;
                            $$ = $1;
                          } else $$ = $2;
                        }
                    | { $$ = NULL; }
                    ;

// statement → expressão-decl | composto-decl | seleção-decl | iteração-decl | retorno-decl
statement           : expressao_decl
                        { $$ = $1; }
                    | composto_decl
                        { $$ = $1; }
                    | selecao_decl
                        { $$ = $1; }
                    | iteracao_decl
                        { $$ = $1; }
                    | retorno_decl
                        { $$ = $1; }
                    ;

// expressão-decl → expressão ; | ;
expressao_decl      : expressao SEMI 
                        { $$ = $1; }
                    | SEMI
                        { $$ = NULL; }
                    ;
                    

// seleção-decl → if ( expressão ) statement | if ( expressão ) statement else statement
selecao_decl        : IF LPAREN expressao RPAREN statement
                        { 
                          $$ = newStmtNode(IfK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                        }
                    | IF LPAREN expressao RPAREN statement ELSE statement
                        { 
                          $$ = newStmtNode(IfK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                          $$->child[2] = $7;
                        }
                    ;

// iteração-decl → while ( expressão ) statement
iteracao_decl       : WHILE LPAREN expressao RPAREN statement
                        {
                          $$ = newStmtNode(WhileK);
                          $$->child[0] = $3;
                          $$->child[1] = $5;
                        }
                    ;

// retorno-decl → return ; | return expressão;
retorno_decl        : RETURN SEMI
                        {        
                          $$ = newStmtNode(ReturnK);
                        }
                    | RETURN expressao SEMI
                        {
                          $$ = newStmtNode(ReturnK);
                          $$->child[0] = $2;
                        }
                    ;

// expressão → var = expressão | simples-expressão
expressao           :  var ASSIGN expressao 
                        {
                          $$ = newExpNode(OpK); 
                          $$->attr.op = ASSIGN; 
                          $$->child[0] = $1; 
                          $$->child[1] = $3; 
                        }
                    |  simples_expressao
                        { $$ = $1; }
                    ;

// var → ID | ID [ expressão ]
var                 : id 
                        { 
                          $$ = newExpNode(IdK);
                          $$->lineno = savedLineNo;
                          $$->attr.name = savedName;
                        }
                    | id
                        {
                          $$ = newExpNode(IdK);
                          $$->lineno = savedLineNo;
                          $$->attr.name = savedName;
                        }
                      LBRACK
                        {
                          $$ = $2;
                          $$->child[0] = newExpNode(OpK);
                          $$->child[0]->attr.op = LBRACK;
                        }
                      expressao
                        {
                          $$ = $2;
                          $$->child[1] = $5;
                        }
                      RBRACK
                        {
                          $$ = $2;
                          $$->child[2] = newExpNode(OpK);
                          $$->child[2]->attr.op = RBRACK;
                        }
                    ;

// simples-expressão → soma-expressão relacional soma-expressão | soma-expressão
simples_expressao   : soma_expressao LT soma_expressao 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = LT;
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao LTE soma_expressao 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = LTE;
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao GT soma_expressao 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = GT;
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao GTE soma_expressao 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = GTE;    
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao EQ soma_expressao
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = EQ;  
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao DIFF soma_expressao
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = DIFF;  
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao
                        { $$ = $1; }
                    ;

// soma-expressão → soma-expressão soma termo | termo
soma_expressao      : soma_expressao PLUS termo
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = PLUS;  
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | soma_expressao MINUS termo
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = MINUS; 
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                          
                        }
                    | termo
                        { $$ = $1; }
                    ;      

// termo → termo mult fator | fator
termo               : termo TIMES fator 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = TIMES; 
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                        }
                    | termo OVER fator 
                        {
                          $$ = newExpNode(OpK);
                          $$->attr.op = OVER; 
                          $$->child[0] = $1;
                          $$->child[1] = $3;
                        }
                    | fator
                        { $$ = $1; }
                    ;      

// fator → ( expressão ) | var | ativação | NUM                    
fator               : LPAREN expressao RPAREN
                        { $$ = $2; }
                    | var
                        { $$ = $1; }
                    | ativacao
                        { $$ = $1; }
                    | num
                        {
                          $$ = newExpNode(ConstK);
                          $$->attr.val = savedDec;
                        }
                    | error
                        { $$ = NULL; }
                    ;

// ativação → ID ( args )                
ativacao            : id
                        {
                          $$ = newExpNode(IdK);
                          $$->attr.name = savedName;
                          $$->lineno = savedLineNo;
                        }
                      LPAREN args RPAREN
                        {
                          $$ = $2;
                          $$->child[0] = $4;
                        }
                    ;

// args → arg-lista | vazio                    
args                : args_lista
                        { $$ = $1; }
                    | { $$ = NULL; }
                    ;

// arg-lista → arg-lista , expressão | expressão                    
args_lista          : args_lista COMMA expressao
                        { 
                          YYSTYPE t = $1;
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = $3;
                            $$ = $1;
                          } else $$ = $3;
                        }
                    | expressao 
                        { $$ = $1; }
                    ;

                    
%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ 
  yyparse();
  return savedTree;
}

