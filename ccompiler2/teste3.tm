* TINY Compilation to TM Code
* File: teste3.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> VoidK
  2:   main  0,0(5) 	void func();
* -> IntK
  3:     LD  0,1(5) 	int var;
* <- IntK
* -> assign
* -> Const
  4:    LDC  0,3(0) 	load const
* <- Const
  5:     ST  0,1(5) 	assign: store value
* <- assign
* <- FunK
* End of execution.
  6:   HALT  0,0,0 	
