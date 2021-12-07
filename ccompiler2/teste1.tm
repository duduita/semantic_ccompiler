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
  4:    LDC  0,10(0) 	load const
* <- Const
  5:     ST  0,1(5) 	assign: store value
* <- assign
* -> if
* -> Op
* -> Const
  6:    LDC  0,1(0) 	load const
* <- Const
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
* if: jump to else belongs here
* -> IntK
 16:     LD  0,2(5) 	int var;
* <- IntK
* -> assign
* -> Const
 17:    LDC  0,20(0) 	load const
* <- Const
 18:     ST  0,2(5) 	assign: store value
* <- assign
* -> if
* -> Op
* -> Const
 19:    LDC  0,1(0) 	load const
* <- Const
 20:     ST  0,0(6) 	op: push left
* -> Const
 21:    LDC  0,1(0) 	load const
* <- Const
 22:     LD  1,0(6) 	op: load left
 23:    SUB  0,1,0 	op ==
 24:    JEQ  0,2(7) 	br if true
 25:    LDC  0,0(0) 	false case
 26:    LDA  7,1(7) 	unconditional jmp
 27:    LDC  0,1(0) 	true case
* <- Op
* if: jump to else belongs here
* -> IntK
 29:     LD  0,3(5) 	int var;
* <- IntK
* -> assign
* -> Op
* -> Op
* -> Id
 30:     LD  0,1(5) 	load id value
* <- Id
 31:     ST  0,0(6) 	op: push left
* -> Const
 32:    LDC  0,2(0) 	load const
* <- Const
 33:     LD  1,0(6) 	op: load left
 34:    MUL  0,1,0 	op *
* <- Op
 35:     ST  0,0(6) 	op: push left
* -> Op
* -> Id
 36:     LD  0,2(5) 	load id value
* <- Id
 37:     ST  0,-1(6) 	op: push left
* -> Const
 38:    LDC  0,3(0) 	load const
* <- Const
 39:     LD  1,-1(6) 	op: load left
 40:    SUB  0,1,0 	op -
* <- Op
 41:     LD  1,0(6) 	op: load left
 42:    ADD  0,1,0 	op +
* <- Op
 43:     ST  0,3(5) 	assign: store value
* <- assign
* if: jump to end belongs here
 28:    JEQ  0,16(7) 	if: jmp to else
 44:    LDA  7,0(7) 	jmp to end
* <- if
* if: jump to end belongs here
 15:    JEQ  0,30(7) 	if: jmp to else
 45:    LDA  7,0(7) 	jmp to end
* <- if
* <- FunK
* End of execution.
 46:   HALT  0,0,0 	
