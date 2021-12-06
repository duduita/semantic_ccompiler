/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash(char *key)
{
  int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  {
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source
 * code in which a variable is referenced
 */
typedef struct LineListRec
{
  int lineno;
  struct LineListRec *next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
{
  char *name;
  LineList lines;
  int val;
  ExpType type;
  StmtType stmtType;
  int level;
  int memloc; /* memory location for variable */
  struct BucketListRec *next;
} * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

void st_set_attribute(int level) // need finish (p1f)
{
  
}

// Procedure st_remove removes lines in level K
void st_remove(int level) // need finish (p1f)
{
  for (int i = 0; i < SIZE; i++)
  {
    if (hashTable[i] == NULL)
      continue;

    printf("%s\n", hashTable[i]->name);

    BucketList prev;
    prev = (BucketList)malloc(sizeof(struct BucketListRec));
    prev->next = hashTable[i];
    while (hashTable[i] != NULL)
    {
      if (hashTable[i]->level == level)
      {
        hashTable[i] = hashTable[i]->next;
        prev->next = hashTable[i];
      }
      else
      {
        prev = hashTable[i];
        hashTable[i] = hashTable[i]->next;
      }
    }
  }
}

void st_insert(char *name, ExpType type, StmtType stmtType, int val, int lineno, int loc, int level)
{
  int h = hash(name);
  BucketList l = hashTable[h];
  while ((l != NULL) && (strcmp(name, l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  {
    l = (BucketList)malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->val = val;
    l->level = level;
    l->type = type;
    l->stmtType = stmtType;

    l->lines = (LineList)malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l;
  }
  else /* found in table, so just add line number */
  {
    LineList t = l->lines;
    while (t->next != NULL)
      t = t->next;
    t->next = (LineList)malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory
 * location of a variable or -1 if not found
 */
int st_lookup(char *name)
{
  int h = hash(name);
  BucketList l = hashTable[h];
  while ((l != NULL) && (strcmp(name, l->name) != 0))
    l = l->next;
  if (l == NULL)
    return -1;
  else
    return l->memloc;
}

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE *listing)
{
  int i;
  fprintf(listing, "Variable Name (ID)   Statement Type   Type    Scope    Value   Location   Line Numbers\n");
  fprintf(listing, "------------------   --------------   ----   -------   -----   --------   ------------\n");
  for (i = 0; i < SIZE; ++i)
  {
    if (hashTable[i] != NULL)
    {
      BucketList l = hashTable[i];
      while (l != NULL)
      {
        LineList t = l->lines;
        fprintf(listing, "%-21s ", l->name);
        fprintf(listing, "%-16d ", l->stmtType);
        fprintf(listing, "%-5d ", l->type);
        fprintf(listing, "%-9d ", l->level);
        fprintf(listing, "%-8d ", 1000);
        fprintf(listing, "%-11d  ", l->memloc);
        // while (t != NULL)
        // {
        //   fprintf(listing, "%3d ", t->lineno);
        //   t = t->next;
        // }
        fprintf(listing, "\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
