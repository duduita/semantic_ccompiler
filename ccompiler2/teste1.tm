* TINY Compilation to TM Code
* File: teste1.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* -> Id
  2:     LD  0,1(5) 	load id value
* <- Id
* -> IntK
  3:     LD  0,1(5) 	int var;
* <- Id
* -> Id
  4:     LD  0,1(5) 	load id value
* <- Id
* -> Const
  5:    LDC  0,0(0) 	load const
* <- Const
* -> Op
* -> Id
  6:     LD  0,1(5) 	load id value
* <- Id
  7:     ST  0,0(6) 	op: push left
* -> Const
  8:    LDC  0,0(0) 	load const
* <- Const
  9:     LD  1,0(6) 	op: load left
* BUG: Unknown operator
* <- Op
* -> Id
 10:     LD  0,0(5) 	load id value
* <- Id
* -> IntK
 11:     LD  0,0(5) 	int func();
* <- Id
* End of execution.
 12:   HALT  0,0,0 	
