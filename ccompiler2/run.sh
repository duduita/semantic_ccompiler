bison -d tiny.y
flex tiny.l
gcc -c main.c lex.yy.c tiny.tab.c util.c analyze.c symtab.c cgen.c code.c
gcc -o tiny *.o -ll