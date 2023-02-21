## This is the library for providing assembly level functions used by various test applications.


.global _REM_TEST_S8_ 
.global _REM_TEST_U8_ 
.global _REM_TEST_U16_ 
.global _REM_TEST_S16_ 
.global _REM_TEST_U32_
.global _REM_TEST_S32_
.global _REM_TEST_U64_
.global _REM_TEST_S64_

.global _REM_TEST_U8U16_
.global _REM_TEST_U8U32_
.global _REM_TEST_U16U32_
.global _REM_TEST_S8S16_
.global _REM_TEST_S8S32_
.global _REM_TEST_S16S32_
.global _REM_TEST_S8U8_
.global _REM_TEST_S16U16_
.global _REM_TEST_S32U32_
.global _REM_TEST_S8U16_
.global _REM_TEST_S8U32_
.global _REM_TEST_S16U32_
.global _REM_TEST_U8S32_
.global _REM_TEST_U16S32_

.global _REM_TEST_U8SRC1_EQ_DEST_
.global _REM_TEST_U8SRC2_EQ_DEST_
.global _REM_TEST_U8SRC12_EQ_DEST_
.global _REM_TEST_U8ZEROSRC1_
.global _REM_TEST_U8ZEROSRC2_
.global _REM_TEST_U8ZEROSRC12_
.global _REM_TEST_U8ZERODEST_
.global _REM_TEST_U8DEST_BYPASS_
.global _REM_TEST_U8SRC12_BYPASS_
.global _REM_TEST_U8SRC21_BYPASS_




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


_REM_TEST_S8_: # signed char or int8_t reminder

	    lb	    a5, 0(a0)              # Load byte (signed) into a5 from the address strored at a0 (op1)
        slliw	a6,a5,0x10             # Logical Shift-left a5 (op1) by 0x10 or 16 and store into a6
        sraiw	a6,a6,0x10             # Arithmentic shift-right a6 by 0x10 or 16 and store into a6
        lb	    a5,0(a1)               # Load byte (signed) into a5 from the address strored at a1 (op2)
        slliw	a5,a5,0x10             # Logical Shift-left a5 (op21) by 0x10 or 16 and store into a5
        sraiw	a5,a5,0x10             # Arithmentic shif-right a5 by 0x10 or 16 and store into a5
        remw	a5,a6,a5               # Remainder using remw and store result into a5
        sb	    a5,0(a2)               # The byte result stored back to variable
    	add     a0, x0, a5             # Set the return value
    	jr      ra                     # return

_REM_TEST_U8_: # unsigned char or uint8_t reminder

    	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu 	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        remuw	a5,a5,a6               # Remainder using remuw and store result into a5
        sb  	a5,0(a2)               # The byte result stored back to variable
    	add     a0, x0, a5             # Set the return value
    	jr      ra                     # return

_REM_TEST_U16_: # unsigned short or uint16_t reminder

    	lhu	    a5, 0(a0)              # Load half-word (unsigned) into a5 from the address strored at a0 (op1)
        lhu 	a6,0(a1)               # Load half-word (unsigned) into a6 from the address strored at a1 (op2)
        remuw	a5,a5,a6               # Remainder using remuw and store result into a5
        sh	    a5,0(a2)               # The half word result stored back to variable
    	add     a0, x0, a5             # Set the return value
    	jr      ra                     # return

_REM_TEST_S16_: # signed short or int16_t reminder

     	lh	    a5, 0(a0)              # Load half-word (signed) into a5 from the address strored at a0 (op1)
        slli	a6,a5,0x10             # Logical Shift-left a5 (op1) by 0x10 and store into a6
        srai	a6,a6,0x10             # Arithmentic shift-right a6 by 0x10 and store into a6
        lh	    a5,0(a1)               # Load half-word (signed) into a5 from the address strored at a1 (op2)
        slli	a5,a5,0x10             # Logical Shift-left a5 (op21) by 0x10 or 16 and store into a5
        srai	a5,a5,0x10             # Arithmentic shift-right a5 by 0x10 or 16 and store into a5
        remw	a5,a6,a5               # Remainder using REMW and store result into a5
        sh	    a5,0(a2)               # The word result stored back to variable
    	add     a0, x0, a5             # Set the return value
    	jr      ra                     # return

_REM_TEST_U32_: # unsigned word or uint32_t division

	     lwu	a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
         lwu	a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
	     remu	a7,a5,a6     	       # Remainder using REMU and store result into a7
         sw	    a7,0(a2)               # The  word result stored back to variable
	     add    a0, x0, a7             # Set the return value double word
	     jr     ra                     # return

_REM_TEST_S32_: # signed word or int32_t division

	    lw	    a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lw	    a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
#	slli	a5,a5,0x20             # Logical Shift-left a5 (op1) by 0x20 and store into a5
#       srai	a5,a5,0x20             # Arithmentic shift-right a5 by 0x20 and store into a5
#	slli	a6,a6,0x20             # Logical Shift-left a6 (op1) by 0x20 and store into a6
#       srai	a6,a6,0x20             # Arithmentic shift-right a6 by 0x20 and store into a6
	    rem	    a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The  word result stored back to variable
	    add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_U64_: # unsigned word or uint64_t division

	 ld	    a5,0(a0)               # Load double word (unsigned) into a5 from the address strored at a0 (op1)
     ld	    a6,0(a1)               # Load double word (unsigned) into a6 from the address strored at a1 (op2)
	 remu	a7,a5,a6     	       # Remainder using REMU and store result into a7
     sd	    a7,0(a2)               # The double word result stored back to variable
	 add     a0, x0, a7            # Set the return value double word
	 jr      ra                    # return

_REM_TEST_S64_: # signed word or int64_t division

	ld	    a5,0(a0)               # Load double word (signed) into a5 from the address strored at a0 (op1)
    ld	    a6,0(a1)               # Load double word (signed) into a6 from the address strored at a1 (op2)
	rem	    a7,a5,a6               # Remainder using REM and store result into a7
    sd	    a7,0(a2)               # The double word result stored back to variable
	add     a0, x0, a7             # Set the return value double word
    jr      ra                     # return


_REM_TEST_U8U16_: # unint16_t % uint8_t reminder operation

	    lhu	    a5,0(a0)               # Load half word (unsigned) into a5 from the address strored at a0 (op1)
        lbu	    a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)	
	    remuw	a7,a5,a6               # Remainder using REM and store result into a7
        sh	    a7,0(a2)               # The half word result stored back to variable
	    add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_U8U32_: # unint32_t % uint8_t reminder operation

    	lwu	    a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lbu	    a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)	
    	remuw	a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_U16U32_: # unint32_t % uint16_t reminder operation

    	lwu	    a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lhu	    a6,0(a1)               # Load half word (unsigned) into a6 from the address strored at a1 (op2)	
    	remuw	a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The  word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_S8S16_:# int16_t % int8_t reminder operation

    	lh	    a5,0(a0)               # Load half word (signed) into a5 from the address strored at a0 (op1)
        lb  	a6,0(a1)               # Load byte (signed) into a6 from the address strored at a1 (op2)	
    	remw	a7,a5,a6               # Remainder using REM and store result into a7
        sh  	a7,0(a2)               # The half word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_S8S32_:# int32_t % int8_t reminder operation

    	lw	    a5,0(a0)               # Load word (signed) into a5 from the address strored at a0 (op1)
        lb	    a6,0(a1)               # Load byte (signed) into a6 from the address strored at a1 (op2)	
	    remw	a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_S16S32_:# int32_t % int16_t reminder operation

	    lw  	a5,0(a0)               # Load word (signed) into a5 from the address strored at a0 (op1)
        lh	    a6,0(a1)               # Load half word (signed) into a6 from the address strored at a1 (op2)	
    	remw	a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The  word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_S8U8_:# uint8_t % int8_t reminder operation

	    lbu	    a5,0(a0)               # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lb	    a6,0(a1)               # Load byte (signed) into a6 from the address strored at a1 (op2)	
    	remw	a7,a5,a6               # Remainder using REM and store result into a7
        sb	    a7,0(a2)               # The byte result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_S16U16_:# uint16_t % int16_t reminder operation

    	lhu 	a5,0(a0)               # Load half word (usigned) into a5 from the address strored at a0 (op1)
        lh	    a6,0(a1)               # Load half word (signed) into a6 from the address strored at a1 (op2)	
    	remw	a7,a5,a6               # Remainder using REM and store result into a7
        sh	    a7,0(a2)               # The half word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

_REM_TEST_S32U32_:# uint32_t % int32_t reminder operation

	    lwu	    a5,0(a0)               # Load word (usigned) into a5 from the address strored at a0 (op1)
        lw	    a6,0(a1)               # Load word (signed) into a6 from the address strored at a1 (op2)	
	    rem	    a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
	    add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_S8U16_:# uint16_t % int16_t reminder operation

	    lhu	    a5,0(a0)               # Load half word word (unsigned) into a5 from the address strored at a0 (op1)
        lb	    a6,0(a1)               # Load byte (signed) into a6 from the address strored at a1 (op2)	
	    remw	a7,a5,a6               # Remainder using REM and store result into a7
        sh	    a7,0(a2)               # The half word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_S8U32_:# uint32_t % int8_t reminder operation

    	lwu	    a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lb	    a6,0(a1)               # Load byte (signed) into a6 from the address strored at a1 (op2)	
    	rem	    a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_S16U32_:# uint32_t % int16_t reminder operation

	    lwu	    a5,0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lh	    a6,0(a1)               # Load half word (signed) into a6 from the address strored at a1 (op2)	
    	rem 	a7,a5,a6               # Remainder using REM and store result into a7
        sw  	a7,0(a2)               # The word result stored back to variable
	    add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_U8S32_:# int32_t % uint8_t reminder operation

    	lw	    a5,0(a0)               # Load word (signed) into a5 from the address strored at a0 (op1)
        lbu	    a6,0(a1)               # Load byte  (unsigned) into a6 from the address strored at a1 (op2)	
	    rem	    a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return


_REM_TEST_U16S32_:# int32_t % uint16_t reminder operation

    	lw	    a5,0(a0)               # Load word (signed) into a5 from the address strored at a0 (op1)
        lhu 	a6,0(a1)               # Load half word (unsigned) into a6 from the address strored at a1 (op2)	
	    rem	    a7,a5,a6               # Remainder using REM and store result into a7
        sw	    a7,0(a2)               # The word result stored back to variable
    	add     a0, x0, a7             # Set the return value double word
    	jr      ra                     # return

	
_REM_TEST_U8SRC1_EQ_DEST_:


    	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	    a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        remuw	a5,a5,a6               #  Remainder  using REMUW and store result into a5
    	sb  	a5,0(a2)               # The byte result stored back to variable
	    add     a0, x0, a5             # Set the return value
    	jr      ra                     # return

_REM_TEST_U8SRC2_EQ_DEST_:


    	lbu 	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
    	lbu	    a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        remuw   a6,a5,a6               # Remainder using REMUW and store result into a6
    	sb	    a6,0(a2)               # The byte result stored back to variable
    	add     a0, x0, a6             # Set the return value
    	jr      ra                     # return

_REM_TEST_U8SRC12_EQ_DEST_:


    	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1 and op2)
        remuw	a5,a5,a5               # Remainder using REMUW and store result into a5
    	sb  	a5,0(a1)               # The byte result stored back to variable
    	add     a0, x0, a5             # Set the return value
    	jr      ra                     # return


_REM_TEST_U8ZEROSRC1_:

	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
	remuw	a5,x0,a5               # Remainder using REMUW and store result into a5
	sb	    a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_REM_TEST_U8ZEROSRC2_:

	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
    remuw	a5,a5,x0               # Remainder using remuw and store result into a5
	sb	    a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_REM_TEST_U8ZEROSRC12_:

        remuw	a5,x0,x0               # Remainder using remuw and store result into a5
    	sb	    a5,0(a0)               # The byte result stored back to variable
	    add     a0, a5, x0             # Set the return value
	    jr      ra                     # return


_REM_TEST_U8ZERODEST_:

	    lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	    a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        remuw	x0,a6,a5               # Remainder using remuw and store result into x0
	    sb  	x0,0(a2)               # The byte result stored back to variable
    	add     a0, x0, x0             # Set the return value
    	jr      ra                     # return


_REM_TEST_U8DEST_BYPASS_:

		li  	x4,0		           # Load immediate zero into x4 
	1:	lbu	    a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu 	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        remuw	a7,a6,a5               # Remainder using REMUW and store result into a7
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
		sb	    a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		           # Add immediate value to x4
		li	    x5,2		           # Load immediate value into x5 
		bne 	x4, x5, 1b	           # Branch not equals used to jump to the label 
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_REM_TEST_U8SRC12_BYPASS_:


		li	x4,0		       # Load immediate zero into x4
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1             # One No operation cycles are added
        	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
        	remuw	a7,a5,a6               # Remainder using remuw and store result into a7
		sb	a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_REM_TEST_U8SRC21_BYPASS_:


		li	x4,0			# Load immediate zero into x4
        1:	lbu	a6,0(a1)                # Load byte (unsigned) into a5 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2         	# Two No operation cycles are added
		lbu	a5, 0(a0)               # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1         	# One No operation cycles are added
        	remuw	a7,a5,a6                # Remainder using remuw and store result into a7
		sb	a7,0(a2)                # The byte result stored back to variable
		addi	x4,x4,1			# Add immediate value to x4
		li	x5,2			# Load immediate value into x5
		bne 	x4, x5, 1b		# Branch not equals used to jump to the label
		add     a0, x0, a7              # Set the return value
		jr      ra                      # return

