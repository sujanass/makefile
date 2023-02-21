## This is the library for providing assembly level functions used by various test applications.


.global _SLL_TEST_S8_ 
.global _SLL_TEST_U8_ 
.global _SLL_TEST_U16_ 
.global _SLL_TEST_S16_ 
.global _SLL_TEST_U32_
.global _SLL_TEST_S32_
.global _SLL_TEST_U64_
.global _SLL_TEST_S64_


.global _SLL_TEST_U8SRC1_EQ_DEST_
.global _SLL_TEST_U8SRC2_EQ_DEST_
.global _SLL_TEST_U8SRC12_EQ_DEST_
.global _SLL_TEST_U8ZEROSRC1_
.global _SLL_TEST_U8ZEROSRC2_
.global _SLL_TEST_U8ZEROSRC12_
.global _SLL_TEST_U8ZERODEST_
.global _SLL_TEST_U8DEST_BYPASS_
.global _SLL_TEST_U8SRC12_BYPASS_
.global _SLL_TEST_U8SRC21_BYPASS_

.global _SLLW_TEST_U32SRC1_EQ_DEST_
.global _SLLW_TEST_U32SRC2_EQ_DEST_
.global _SLLW_TEST_U32SRC12_EQ_DEST_
.global _SLLW_TEST_U32ZEROSRC1_
.global _SLLW_TEST_U32ZEROSRC2_
.global _SLLW_TEST_U32ZEROSRC12_
.global _SLLW_TEST_U32ZERODEST_
.global _SLLW_TEST_U32DEST_BYPASS_
.global _SLLW_TEST_U32SRC12_BYPASS_
.global _SLLW_TEST_U32SRC21_BYPASS_




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


_SLL_TEST_S8_: # signed char or int8_t shift left
        lb    a5, 0(a0)                # Load byte (signed) into a5 from the address strored at a0 (op1)
       lb    a6, 0(a0)                # Load byte (signed) into a6 from the address strored at a0 (op1)
                sll   a5,a5,a6                 # Shift left using SLL and store result into a5
        sb    a5,0(a2)                 # The half-word result stored back to variable
	add   a0, x0, a5               # Set the return value
	jr    ra                       # return

_SLL_TEST_U8_: # unsigned char or uint8_t shift left

	lbu  a5, 0(a0)                 # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu  a6,0(a1)                  # Load byte (unsigned) into a5 from the address strored at a1 (op2)
	sll  a5,a5,a6                  # shift left using SLL and store result into a5
        sb   a5,0(a2)                  # The half-word result stored back to variable
	add  a0, x0, a5                # Set the return value
	jr   ra                        # return

_SLL_TEST_U16_: # unsigned short or uint16_t shift left

	lhu  a5, 0(a0)                 # Load half-word (unsigned) into a5 from the address strored at a0 (op1)
        lhu  a6,0(a1)                  # Load half-word (unsigned) into a6 from the address strored at a1 (op2)
        sll  a5,a5,a6                  # shift left using SLL and store result into a5
        sh   a5,0(a2)                  # The word result stored back to variable
	add  a0, x0, a5                # Set the return value
	jr   ra                        # return

_SLL_TEST_S16_: # signed short or int16_t shift left

	lh    a5, 0(a0)                # Load half-word (signed) into a5 from the address strored at a0 (op1)
     lh   a6,0(a1)                 # Load half-word (signed) into a6 from the address strored at a1 (op2)
        sll   a5,a5,a6                 # shift left using SLL and store result into a5
        sh    a5,0(a2)                 # The word result stored back to variable
	add   a0, x0, a5               # Set the return value
	jr    ra                       # return

_SLL_TEST_U32_: # unsigned word or uint32_t shift left
	 lwu a5,0(a0)                  # Load word (unsigned) into a5 from the address strored at a0 (op1)
      lwu a6,0(a1)                  # Load word (unsigned) into a6 from the address strored at a1 (op2)
	 sllw a5,a5,a6     	       # shift left using SLL and store result into a5
     sw  a5,0(a2)                  # The double word result stored back to variable
	 add a0, x0, a5                # Set the return value double word
	 jr  ra                        # return

_SLL_TEST_S32_: # signed word or int32_t shift left

	lw  a5,0(a0)                   # Load word  into a5 from the address strored at a0 (op1)
        lw  a6,0(a1)                   # Load word into a6 from the address strored at a1 (op2)
	sllw a5,a5,a6                   # shift left using SLL and store result into a5
        sw a5,0(a2)                   # The double word result stored back to variable
	add a0, x0, a5                 # Set the return value double word
  	jr  ra                         # return


_SLL_TEST_U64_: # unsigned word or uint32_t shift left
	 ld a5,0(a0)                  # Load word (unsigned) into a5 from the address strored at a0 (op1)
      lwu a6,0(a1)                  # Load word (unsigned) into a6 from the address strored at a1 (op2)
	 sllw a5,a5,a6     	       # shift left using SLL and store result into a5
     sd  a5,0(a2)                  # The double word result stored back to variable
	 add a0, x0, a5                # Set the return value double word
	 jr  ra                        # return

_SLL_TEST_S64_: # signed word or int32_t shift left

	ld  a5,0(a0)                   # Load word  into a5 from the address strored at a0 (op1)
        lw  a6,0(a1)                   # Load word into a6 from the address strored at a1 (op2)
	sllw a5,a5,a6                   # shift left using SLL and store result into a5
      sd a5,0(a2)                   # The double word result stored back to variable
	add a0, x0, a5                 # Set the return value double word
  	jr  ra                         # return
	



_SLL_TEST_U8SRC1_EQ_DEST_:


	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        sll	a5,a5,a6               #  shift left  using SLL and store result into a5
	sb	a5,0(a2)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return

_SLL_TEST_U8SRC2_EQ_DEST_:


	lbu 	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
    	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        sll     a6,a5,a6               # shift left using SLL and store result into a6
	sb	a6,0(a2)               # The byteresult stored back to variable
	add     a0, x0, a6             # Set the return value
	jr      ra                     # return

_SLL_TEST_U8SRC12_EQ_DEST_:


	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1 and op2)
        sll	a5,a5,a5               # shift left using SLL and store result into a5
	sb  	a5,0(a1)               # The half-word result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLL_TEST_U8ZEROSRC1_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
	sll	a5,x0,a5               # shift left using SLL and store result into a5
	sb	a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLL_TEST_U8ZEROSRC2_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        sll	a5,a5,x0               # shift left using SLL and store result into a5
	sb	a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLL_TEST_U8ZEROSRC12_:

       sll	a5,x0,x0               # shift left using SLL and store result into a5
	sb	a5,0(a0)               # The byte result stored back to variable
	add     a0, a5, x0             # Set the return value
	jr      ra                     # return


_SLL_TEST_U8ZERODEST_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        sll	x0,a6,a5               # shift left using SLL and store result into x0
	sb	x0,0(a2)               # The byte result stored back to variable
	add     a0, x0, x0             # Set the return value
	jr      ra                     # return


_SLL_TEST_U8DEST_BYPASS_:

		li	x4,0		       # Load immediate zero into x4 
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        	lbu	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        	sll	a7,a6,a5               # shift left using SLL and store result into a7
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
		sb	a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5 
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label 
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_SLL_TEST_U8SRC12_BYPASS_:


		li	x4,0		       # Load immediate zero into x4
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1             # One No operation cycles are added
        	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
        	sll	a7,a5,a6               # shift left using SLL and store result into a7
		sb	a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_SLL_TEST_U8SRC21_BYPASS_:


		li	x4,0			# Load immediate zero into x4
        1:	lbu	a6,0(a1)                # Load byte (unsigned) into a5 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2         	# Two No operation cycles are added
		lbu	a5, 0(a0)               # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1         	# One No operation cycles are added
        	sll	a7,a5,a6                # shift left using SLL and store result into a7
		sb	a7,0(a2)                # The byte result stored back to variable
		addi	x4,x4,1			# Add immediate value to x4
		li	x5,2			# Load immediate value into x5
		bne 	x4, x5, 1b		# Branch not equals used to jump to the label
		add     a0, x0, a7              # Set the return value
		jr      ra                      # return

	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32SRC1_EQ_DEST_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lwu	a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
         sllw a5,a5,a6               # Use sllw  and store result into a5
	sw	a5,0(a2)               # The word result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32SRC2_EQ_DEST_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lwu	a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
        sllw	a6,a5,a6               # Use SLLW and store result into a6
	sw	a6,0(a2)               # The word result stored back to variable
	add     a0, x0, a6             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32SRC12_EQ_DEST_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1 and op2)
        sllw	a5,a5,a5               # Use SLLW and store result into a5
	sw	a5,0(a1)               # The word result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32ZEROSRC1_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        sllw	a6,x0,a5               # Use SLLW and store result into a6
	sw	a6,0(a1)               # The word result stored back to variable
	add     a0, x0, a6             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32ZEROSRC2_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        sllw	a6,a5,x0               # Use SLLW and store result into a6
	sw	a6,0(a1)               # The word result stored back to variable
	add     a0, x0, a6             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32ZEROSRC12_: # unsigned word or uint32_t and

        and	a5,x0,x0               # Use SLLW and store result into a5
	sw	a5,0(a0)               # The word result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32ZERODEST_: # unsigned word or uint32_t and

	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lwu	a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
        sllw	x0,a5,a6               # Use sllw and store result into x0
	sw	x0,0(a2)               # The word result stored back to variable
	add     a0, x0, x0             # Set the return value
	jr      ra                     # return


_SLLW_TEST_U32DEST_BYPASS_: # unsigned word or uint32_t and

		li	x4,0		       # Load immediate zero into x4 
	1:	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
        	lwu	a6,0(a1)               # Load word (unsigned) into a5 from the address strored at a1 (op2)
        	sllw	a7,a5,a6               # Use SLLW and store result into a7
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
		sw	a7,0(a2)               # The word result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5 
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label 
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return


_SLLW_TEST_U32SRC12_BYPASS_: # unsigned word or uint32_t and

		li	x4,0		       # Load immediate zero into x4
	1:	lwu	a5, 0(a0)              # Load word (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1             # One No operation cycles are added
        	lwu	a6,0(a1)               # Load word (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
        	sllw	a7,a5,a6               # Use SLLW and store result into a7
		sw	a7,0(a2)               # The word result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return


_SLLW_TEST_U32SRC21_BYPASS_: # unsigned word or uint32_t and

		li	x4,0			# Load immediate zero into x4
        1:	lwu	a6,0(a1)                # Load word (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2         	# Two No operation cycles are added
		lwu	a5, 0(a0)               # Load word (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1         	# One No operation cycles are added
        	sllw	a7,a5,a6                # Use AND and store result into a7
		sw	a7,0(a2)                # The word result stored back to variable
		addi	x4,x4,1			# Add immediate value to x4
		li	x5,2			# Load immediate value into x5
		bne 	x4, x5, 1b		# Branch not equals used to jump to the label
		add     a0, x0, a7              # Set the return value
		jr      ra                      # return

