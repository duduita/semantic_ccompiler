#bison --debug -d tiny.y
bison -d tiny.y
flex tiny.l
gcc -c main.c lex.yy.c tiny.tab.c util.c analyze.c symtab.c
gcc -o tiny *.o -ll