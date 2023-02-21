## This is the library for providing assembly level functions used by various test applications.

.global _SUB_TEST_U8_
.global _SUB_TEST_S8_
.global _SUB_TEST_U16_
.global _SUB_TEST_S16_
.global _SUB_TEST_U32_
.global _SUB_TEST_S32_
.global _SUB_TEST_U8U16_
.global _SUB_TEST_U8U32_
.global _SUB_TEST_U16U32_
.global _SUB_TEST_S8S16_
.global _SUB_TEST_S8S32_
.global _SUB_TEST_S16S32_
.global _SUB_TEST_U8S16_
.global _SUB_TEST_S8U8_
.global _SUB_TEST_S16U16_
.global _SUB_TEST_S32U32_
.global _SUB_TEST_S8U16_
.global _SUB_TEST_S8U32_
.global _SUB_TEST_S16U32_
.global _SUB_TEST_U8S32_
.global _SUB_TEST_U16S32_


.global _SUB_TEST_U8SRC1_EQ_DEST_
.global _SUB_TEST_U8SRC2_EQ_DEST_
.global _SUB_TEST_U8SRC12_EQ_DEST_
.global _SUB_TEST_U8ZEROSRC1_
.global _SUB_TEST_U8ZEROSRC2_
.global _SUB_TEST_U8ZEROSRC12_
.global _SUB_TEST_U8ZERODEST_
.global _SUB_TEST_U8DEST_BYPASS_
.global _SUB_TEST_U8SRC12_BYPASS_
.global _SUB_TEST_U8SRC21_BYPASS_


#define TEST_INSERT_NOPS_0
#define TEST_INSERT_NOPS_1  nop; TEST_INSERT_NOPS_0
#define TEST_INSERT_NOPS_2  nop; TEST_INSERT_NOPS_1
#define TEST_INSERT_NOPS_3  nop; TEST_INSERT_NOPS_2
#define TEST_INSERT_NOPS_4  nop; TEST_INSERT_NOPS_3
#define TEST_INSERT_NOPS_5  nop; TEST_INSERT_NOPS_4
#define TEST_INSERT_NOPS_6  nop; TEST_INSERT_NOPS_5
#define TEST_INSERT_NOPS_7  nop; TEST_INSERT_NOPS_6
#define TEST_INSERT_NOPS_8  nop; TEST_INSERT_NOPS_7
#define TEST_INSERT_NOPS_9  nop; TEST_INSERT_NOPS_8
#define TEST_INSERT_NOPS_10 nop; TEST_INSERT_NOPS_9


###################### Subtraction ############################
####################### Part 2 ################################

_SUB_TEST_U8_:                     # uint8_t subtraction  
        lbu	a5, 0(a0)          # Load byte (unsigned) in the LSB of a5 and zero-fills the upper bits of a5.   
    	lbu	a6, 0(a1)      	   # Load byte (unsigned) into a6 from the address strored at a1 (op2), and zerofills the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sh	a5,0(a2)           # store halfword (lower 2 bytes ) from a5 to address stored at a2 (result)  
	jr      ra                 # return

_SUB_TEST_S8_:                     # int8_t subtraction  
        lb	a5, 0(a0)          # Load byte (signed) in the LSB of a5 and fills the upper bits of a5 with copies of the sign bit.     
    	lb	a6, 0(a1)      	   # Load byte (signed) into a6 from the address strored at a1 (op2), and sign-extends the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sh	a5,0(a2)           # store halfword (lower 2 bytes) from a5 to address stored at a2 (result) 
	jr      ra                 # return

_SUB_TEST_U16_:                     # uint16_t subtraction  
        lhu	a5, 0(a0)          # Load halfword (unsigned) in a5 and zero-fills the upper bits of a5..     
    	lhu	a6, 0(a1)      	   # Load halfword (unsigned) in a6 from the address strored at a1 (op2), and zerofills the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sw	a5,0(a2)           # store word (lower 4 bytes) from a5 to address stored at a2 (result) 
	jr      ra                 # return

_SUB_TEST_S16_:                     # int16_t subtraction  
        lh	a5, 0(a0)          # Load halfword (signed) in the LSB of a5 and fills the upper bits of a5 with copies of the sign bit.     
    	lh	a6, 0(a1)      	   # Load halfword (signed) into a6 from the address strored at a1 (op2), and sign-extends the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sw	a5,0(a2)           # store word (lower 4 bytes) from a5 to address stored at a2 (result)  
	jr      ra                 # return

_SUB_TEST_U32_:                     # uint32_t subtraction  
        lwu	a5, 0(a0)          # Load word (unsigned) in a5 and zero-fills the upper bits of a5..     
    	lwu	a6, 0(a1)      	   # Load word (unsigned) in a6 from the address strored at a1 (op2), and zerofills the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sd	a5,0(a2)           # store doubleword (all bytes) from a5 to address stored at a2 (result)
	jr      ra                 # return

_SUB_TEST_S32_:                     # int32_t subtraction  
        lw	a5, 0(a0)          # Load word (signed) in the LSB of a5 and fills the upper bits of a5 with copies of the sign bit.     
    	lw	a6, 0(a1)      	   # Load word (signed) into a6 from the address strored at a1 (op2), and sign-extends the upper bits of a6
    	subw	a5, a5, a6  	   # Subtract using SUBW, a5-a6, and store result into a5 , and sign extended to 64 bits.
    	sd	a5,0(a2)           # store doubleword (all bytes) from a5 to address stored at a2 (result)
	jr      ra                 # return

_SUB_TEST_U8U16_:
	lbu	a5, 0(a0)
	lhu	a6, 0(a1)
	subw	a5, a5, a6
	sw	a5,0(a2)
	jr      ra 

_SUB_TEST_U8U32_:
	lbu	a5, 0(a0)
	lwu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_U16U32_:
	lhu	a5, 0(a0)
	lwu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 

_SUB_TEST_S8S16_:
	lb	a5, 0(a0)
	lh	a6, 0(a1)
	subw	a5, a5, a6
	sw	a5,0(a2)
	jr      ra 

_SUB_TEST_S8S32_:
	lb	a5, 0(a0)
	lh	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_S16S32_:
	lh	a5, 0(a0)
	lw	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_U8S16_:
	lbu	a5, 0(a0)
	lh	a6, 0(a1)
	subw	a5, a5, a6
	sw	a5,0(a2)
	jr      ra 


_SUB_TEST_S8U8_:
	lb	a5, 0(a0)
	lbu	a6, 0(a1)
	subw	a5, a5, a6
	sw	a5,0(a2)
	jr      ra 


_SUB_TEST_S16U16_:
	lh	a5, 0(a0)
	lhu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_S32U32_:
	lw	a5, 0(a0)
	lwu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_S8U16_:
	lb	a5, 0(a0)
	lhu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_S8U32_:
	lb	a5, 0(a0)
	lwu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 

_SUB_TEST_S16U32_:
	lh	a5, 0(a0)
	lwu	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_U8S32_:
	lbu	a5, 0(a0)
	lw	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 

_SUB_TEST_U16S32_:
	lhu	a5, 0(a0)
	lw	a6, 0(a1)
	subw	a5, a5, a6
	sd	a5,0(a2)
	jr      ra 


_SUB_TEST_U8SRC1_EQ_DEST_:
	lbu	a5,0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        subw	a5,a6,a5               # Multiply using SUBW and store result into a5 : Src1=Dst
	sh	a5,0(a2)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8SRC2_EQ_DEST_:
	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        subw	a6,a6,a5               # Multiply using SUBW and store result into a6
	sh	a6,0(a2)               # The half-word result stored back to variable
	jr      ra                     # return

_SUB_TEST_U8SRC12_EQ_DEST_:
	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1 and op2)
        subw	a5,a5,a5               # Multiply using SUBW and store result into a5
	sh	a5,0(a1)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8ZEROSRC1_:
	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        subw	a5,a5,x0               # Multiply using SUBW and store result into a5
	sh	a5,0(a1)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8ZEROSRC2_:
	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        subw	a5,x0,a5               # Multiply using SUBW and store result into a5
	sh	a5,0(a1)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8ZEROSRC12_:
        subw	a5,x0,x0               # Multiply using SUBW and store result into a5
	sh	a5,0(a0)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8ZERODEST_:
	lbu	a5,0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        subw	x0,a6,a5               # Multiply using SUBW and store result into x0
	sh	x0,0(a2)               # The half-word result stored back to variable
	jr      ra                     # return


_SUB_TEST_U8DEST_BYPASS_:
		li	x4,0		       # Load immediate zero into x4 
	1:	lbu	a5,0(a0)               # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        	lbu	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        	subw	a7,a6,a5               # subtraction using SUBW and store result into a7
		TEST_INSERT_NOPS_2             # Two No operation cycles are added 
		sh	a7,0(a2)               # The half-word result stored back to variable 
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5 
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label 
		jr      ra                     # return

_SUB_TEST_U8SRC12_BYPASS_:
		li	x4,0		       # Load immediate zero into x4
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1             # One No operation cycles are added
        	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
        	subw	a7,a5,a6               # subtraction using SUBW and store result into a7
		sh	a7,0(a2)               # The half-word result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return

_SUB_TEST_U8SRC21_BYPASS_:
		li	x4,0			# Load immediate zero into x4
        1:	lbu	a6,0(a1)                # Load byte (unsigned) into a5 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2         	# Two No operation cycles are added
		lbu	a5, 0(a0)               # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1         	# One No operation cycles are added
        	subw	a7,a5,a6                # subtraction using SUBW and store result into a7
		sh	a7,0(a2)                # The half-word result stored back to variable
		addi	x4,x4,1			# Add immediate value to x4
		li	x5,2			# Load immediate value into x5
		bne 	x4, x5, 1b		# Branch not equals used to jump to the label
		add     a0, x0, a7              # Set the return value
		jr      ra                      # return
