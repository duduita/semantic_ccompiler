* TINY Compilation to TM Code
* File: teste4.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> VoidK
  2:    pad  0,0(5) 	void func();
* -> IntK
  3:     LD  0,1(5) 	int var;
* <- IntK
* <- FunK
* -> VoidK
  4:   main  0,2(5) 	void func();
* -> IntK
  5:     LD  0,3(5) 	int var;
* <- IntK
* -> assign
* -> Id
  6:     LD  0,0(5) 	load id value
* <- Id
  7:     ST  0,3(5) 	assign: store value
* <- assign
* <- FunK
* End of execution.
  8:   HALT  0,0,0 	
