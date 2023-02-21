# This is the library for providing assembly level functions used by various test applications.


.global _ASM_IRQ_MUL_
.global _ASM_IRQ_ADD_
.global _ASM_IRQ_SUB_
.global _ASM_IRQ_SLL_
.global _ASM_IRQ_ADDI_
.global _ASM_IRQ_XORI_
.global _ASM_IRQ_BEQ_
.global _ASM_IRQ_BNE_
.global _ASM_IRQ_JAL_ 
.global _ASM_IRQ_JALR_ 



_ASM_IRQ_MUL_: 

# unsigned char or uint8_t MUL

	lbu	a6, 0(a0)              # Load byte (unsigned) into a6 from the address strored at a0 (op1)
    lbu	a7,0(a1)               # Load byte (unsigned) into a7 from the address strored at a1 (op2)
    lbu	t0,0(a2)               # Load byte (unsigned) into t0 from the address strored at a2 (op3)
    lbu	t1,0(a3)               # Load byte (unsigned) into t1 from the address strored at a3 (op4)

        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,a6,a7              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
        mul	a5,t0,t1              # Use MUL and store result into a5
                
        sb	a5,0(a4)               # The byte result stored back to variable
   	jr      ra                     # return

_ASM_IRQ_ADD_: 

# unsigned char or uint8_t ADD

	lbu	a6, 0(a0)              # Load byte (unsigned) into a6 from the address strored at a0 (op1)
    lbu	a7,0(a1)               # Load byte (unsigned) into a7 from the address strored at a1 (op2)
    lbu	t0,0(a2)               # Load byte (unsigned) into t0 from the address strored at a2 (op3)
    lbu	t1,0(a3)               # Load byte (unsigned) into t1 from the address strored at a3 (op4)

        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,a6,a7              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
        add	a5,t0,t1              # Use ADD and store result into a5
                
        sb	a5,0(a4)               # The byte result stored back to variable
   	jr      ra                     # return


_ASM_IRQ_SUB_: 

# unsigned char or uint8_t SUB

	lbu	a6, 0(a0)              # Load byte (unsigned) into a6 from the address strored at a0 (op1)
    lbu	a7,0(a1)               # Load byte (unsigned) into a7 from the address strored at a1 (op2)
    lbu	t0,0(a2)               # Load byte (unsigned) into t0 from the address strored at a2 (op3)
    lbu	t1,0(a3)               # Load byte (unsigned) into t1 from the address strored at a3 (op4)

        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,a6,a7              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
        sub	a5,t0,t1              # Use SUB and store result into a5
                
        sb	a5,0(a4)               # The byte result stored back to variable
   	jr      ra                     # return


_ASM_IRQ_SLL_: 

# unsigned char or uint8_t SLL

	lbu	a6, 0(a0)              # Load byte (unsigned) into a6 from the address strored at a0 (op1)
    lbu	a7,0(a1)               # Load byte (unsigned) into a7 from the address strored at a1 (op2)
    lbu	t0,0(a2)               # Load byte (unsigned) into t0 from the address strored at a2 (op3)
    lbu	t1,0(a3)               # Load byte (unsigned) into t1 from the address strored at a3 (op4)

        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,a6,a7              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
        sll	a5,t0,t1              # Use SLL and store result into a5
                
        sb	a5,0(a4)               # The byte result stored back to variable
   	jr      ra                     # return



_ASM_IRQ_ADDI_: 

# unsigned char or uint8_t ADDI

    lbu	a7,0(a0)               # Load byte (unsigned) into a7 from the address strored at a1 (op1)
    lbu a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a2 (op2)

        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a6,222              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        addi	a5,a7,100              # Use ADDI with immediate value and store result into a5
        
                
        sb	a5,0(a2)               # The byte result stored back to variable
   	jr      ra                     # return


_ASM_IRQ_XORI_: 

# unsigned char or uint8_t XORI

    lbu	a7,0(a0)               # Load byte (unsigned) into a7 from the address strored at a0 (a1)
    lbu a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (a2)

        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a6,222              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
        xori	a5,a7,100              # Use XORI with immediate value and store result into a5
                   
        sb	a5,0(a2)               # The byte result stored back to variable
   	jr      ra                     # return 
    
_ASM_IRQ_BEQ_ :

#unsigned char or uint8_t BEQ

    lbu	a5,0(a0)               # Load byte (unsigned) into a7 from the address strored at a0 (b1)
    lbu	a6,0(a1)               # Load byte (unsigned) into a7 from the address strored at a0 (b1)    
    lbu	t0,0(a2)               # Load byte (unsigned) into a4 from the address strored at a2 (b3)
    lbu t1,0(a3)               # Load byte (unsigned) into a5 from the address strored at a3 (b4)


             beq  	a5,a6,branch1      # Use BEQ and jump to branch condition if condition is true

     branch1:beq  	a5,a6,branch2      # Use BEQ and jump to branch condition if condition is true
     branch2:beq  	a5,a6,branch3      # Use BEQ and jump to branch condition if condition is true
     branch3:beq  	a5,a6,branch4      # Use BEQ and jump to branch condition if condition is true
     branch4:beq  	a5,a6,branch5      # Use BEQ and jump to branch condition if condition is true
     branch5:beq  	t0,t1,branch6      # Use BEQ and jump to branch condition if condition is true
     branch6:beq  	a5,a6,branch7      # Use BEQ and jump to branch condition if condition is true
     branch7:beq  	a5,a6,branch8      # Use BEQ and jump to branch condition if condition is true
     branch8:beq  	a5,a6,branch9      # Use BEQ and jump to branch condition if condition is true
     branch9:beq  	a5,a6,branch10     # Use BEQ and jump to branch condition if condition is true
     branch10:beq  	a5,a6,branch11     # Use BEQ and jump to branch condition if condition is true
     branch11:nop                      # No operation

   	jr      ra                     # return


_ASM_IRQ_BNE_ :

#unsigned char or uint8_t BNE

    lbu	a5,0(a0)               # Load byte (unsigned) into a7 from the address strored at a0 (b1)
    lbu	a6,0(a1)               # Load byte (unsigned) into a7 from the address strored at a0 (b1)    
    lbu	t0,0(a2)               # Load byte (unsigned) into a4 from the address strored at a2 (b3)
    lbu t1,0(a3)               # Load byte (unsigned) into a5 from the address strored at a3 (b4)

          bne  	a5,a6,bne1          # Use BNE and jump to branch condition if condition is true

     bne1:bne  	a5,a6,bne2      # Use BNE and jump to branch condition if condition is true
     bne2:bne  	a5,a6,bne3      # Use BNE and jump to branch condition if condition is true
     bne3:bne  	a5,a6,bne4      # Use BNE and jump to branch condition if condition is true
     bne4:bne  	a5,a6,bne5      # Use BNE and jump to branch condition if condition is true
     bne5:bne  	t0,t1,bne6      # Use BNE and jump to branch condition if condition is true
     bne6:bne  	a5,a6,bne7      # Use BNE and jump to branch condition if condition is true
     bne7:bne  	a5,a6,bne8      # Use BNE and jump to branch condition if condition is true
     bne8:bne  	a5,a6,bne9      # Use BNE and jump to branch condition if condition is true
     bne9:bne  	a5,a6,bne10     # Use BNE and jump to branch condition if condition is true
     bne10:bne  a5,a6,bne11     # Use BNE and jump to branch condition if condition is true
     bne11:nop                  # No operation

   	jr      ra                     # return

_ASM_IRQ_JAL_ :

#unsigned char or uint8_t JAL

        jal  	a6,jump1            # Use JAL to jump to PC location

     jump1:jal  	a6,jump2      # Use JAL to jump to PC location
     jump2:jal  	a6,jump3      # Use JAL to jump to PC location
     jump3:jal  	a6,jump4      # Use JAL to jump to PC location
     jump4:jal  	a6,jump5      # Use JAL to jump to PC location
     jump5:jal  	a6,jump6      # Use JAL to jump to PC location
     jump6:jal  	a6,jump7      # Use JAL to jump to PC location
     jump7:jal  	a6,jump8      # Use JAL to jump to PC location
     jump8:jal  	a6,jump9      # Use JAL to jump to PC location
     jump9:jal  	a6,jump10     # Use JAL to jump to PC location
     jump10:jal  	a6,jump11     # Use JAL to jump to PC location
     jump11:nop                   # No operation

   	jr      ra                     # return


_ASM_IRQ_JALR_ :

#unsigned char or uint8_t JALR
  
   auipc a4,0                       # Store PC value to a4 using auipc
   
     jalr a6,a4,8                  # Use JALR to jump to PC location
     jalr a6,a4,12                 # Use JALR to jump to PC location
     jalr a6,a4,16                 # Use JALR to jump to PC location
     jalr a6,a4,20                 # Use JALR to jump to PC location
     jalr a6,a4,24                 # Use JALR to jump to PC location
     jalr a6,a4,28                 # Use JALR to jump to PC location
     jalr a6,a4,32                 # Use JALR to jump to PC location
     jalr a6,a4,36                 # Use JALR to jump to PC location
     jalr a6,a4,40                 # Use JALR to jump to PC location
     jalr a6,a4,44                 # Use JALR to jump to PC location
     jalr a6,a4,48                 # Use JALR to jump to PC location
     nop   

   jr      ra                     # return



