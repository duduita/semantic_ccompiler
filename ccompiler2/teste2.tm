* TINY Compilation to TM Code
* File: teste2.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> IntK
  2:   funA  0,0(5) 	int func();
* -> IntK
  3:     LD  0,1(5) 	int var;
* <- IntK
* <- FunK
* -> IntK
  4:   funB  0,2(5) 	int func();
* -> IntK
  5:     LD  0,3(5) 	int var;
* <- IntK
* <- FunK
* -> VoidK
  6:   main  0,4(5) 	void func();
* -> IntK
  7:     LD  0,1(5) 	int var;
* <- IntK
* -> assign
* -> Id
  8:     LD  0,-1(5) 	load id value
* <- Id
  9:     ST  0,1(5) 	assign: store value
* <- assign
* <- FunK
* End of execution.
 10:   HALT  0,0,0 	
