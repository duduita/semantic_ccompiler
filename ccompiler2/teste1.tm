* TINY Compilation to TM Code
* File: teste1.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> VoidK
  2:   main  0,0(5) 	void func();
* -> IntK
  3:     LD  0,1(5) 	int var;
* <- IntK
* -> IntK
  4:     LD  0,2(5) 	int var;
* <- IntK
* <- FunK
* End of execution.
  5:   HALT  0,0,0 	
