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

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

// Procedure st_remove removes lines in level K
void st_remove(int level)
{
  for (int i = 0; i < SIZE; i++)
  {
    if (hashTable[i] == NULL)
      continue;

    BucketList newHead = hashTable[i];
    while (newHead && newHead->level == level)
    {
      newHead = newHead->next;
    }

    BucketList prev = (BucketList)malloc(sizeof(struct BucketListRec));
    prev->next = hashTable[i];
    while (hashTable[i] != NULL)
    {
      if (hashTable[i]->level == level)
      {
        BucketList aux = hashTable[i];
        hashTable[i] = hashTable[i]->next;
        prev->next = hashTable[i];
        free(aux);
      }
      else
      {
        prev = hashTable[i];
        hashTable[i] = hashTable[i]->next;
      }
    }

    hashTable[i] = newHead;
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

int st_declared(char *name, int level)
{
  int h = hash(name);
  BucketList l = hashTable[h];
  while ((l != NULL) && (strcmp(name, l->name) != 0))
    l = l->next;
  if (l == NULL || l->level != level)
    return 0;
  return 1;
}

BucketList st_search(char *name)
{
  int h = hash(name);
  BucketList l = hashTable[h];
  while ((l != NULL) && (strcmp(name, l->name) != 0))
    l = l->next;
  return l;
}

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE *listing)
{
  int i;
  fprintf(listing, "Variable Name (ID)   Statement Type   Type    Scope\n");
  fprintf(listing, "------------------   --------------   ----   -------\n");
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
        fprintf(listing, "\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
