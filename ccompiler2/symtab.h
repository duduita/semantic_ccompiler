/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

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
void st_insert(char *name, ExpType type, StmtType stmtType, int val, int lineno, int loc, int level);

// Procedure st_remove removes lines in level K
void st_remove(int level);

/* Function st_lookup returns the memory
 * location of a variable or -1 if not found
 */
int st_lookup(char *name);

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE *listing);

void st_set_attribute(char *name, int val);

int st_declared(char *name, int level);

BucketList st_search(char *name);

#endif
