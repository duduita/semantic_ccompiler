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
* -> Op
* -> Id
  6:     LD  0,4(5) 	load id value
* <- Id
  7:     ST  0,0(6) 	op: push left
* -> Const
  8:    LDC  0,1(0) 	load const
* <- Const
  9:     LD  1,0(6) 	op: load left
 10:    ADD  0,1,0 	op +
* <- Op
 11:     ST  0,4(5) 	assign: store value
* <- assign
* <- FunK
* End of execution.
 12:   HALT  0,0,0 	
