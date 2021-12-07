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
* -> assign
* -> Const
  4:    LDC  0,0(0) 	load const
* <- Const
  5:     ST  0,1(5) 	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> Op
* -> Id
  6:     LD  0,1(5) 	load id value
* <- Id
  7:     ST  0,0(6) 	op: push left
* -> Const
  8:    LDC  0,1(0) 	load const
* <- Const
  9:     LD  1,0(6) 	op: load left
 10:    SUB  0,1,0 	op ==
 11:    JEQ  0,2(7) 	br if true
 12:    LDC  0,0(0) 	false case
 13:    LDA  7,1(7) 	unconditional jmp
 14:    LDC  0,1(0) 	true case
* <- Op
* -> assign
* -> Const
 15:    LDC  0,2(0) 	load const
* <- Const
 16:     ST  0,1(5) 	assign: store value
* <- assign
 17:    JEQ  0,-12(7) 	while: jmp back to body
* <- while
* <- FunK
* End of execution.
 18:   HALT  0,0,0 	
