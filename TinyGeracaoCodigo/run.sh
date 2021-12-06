#bison --debug -d tiny.y
bison -d tiny.y
flex tiny.l
gcc -c *.c
gcc -o tiny *.o -ll