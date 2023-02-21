## This is the library for providing assembly level functions used by various test applications.


.global _SRL_TEST_S8_ 
.global _SRL_TEST_U8_ 
.global _SRL_TEST_U16_ 
.global _SRL_TEST_S16_ 
.global _SRL_TEST_U32_
.global _SRL_TEST_S32_
.global _SRL_TEST_U64_
.global _SRL_TEST_S64_

.global _SRL_TEST_U8SRC1_EQ_DEST_
.global _SRL_TEST_U8SRC2_EQ_DEST_
.global _SRL_TEST_U8SRC12_EQ_DEST_
.global _SRL_TEST_U8ZEROSRC1_
.global _SRL_TEST_U8ZEROSRC2_
.global _SRL_TEST_U8ZEROSRC12_
.global _SRL_TEST_U8ZERODEST_
.global _SRL_TEST_U8DEST_BYPASS_
.global _SRL_TEST_U8SRC12_BYPASS_
.global _SRL_TEST_U8SRC21_BYPASS_




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

_SRL_TEST_U8_: 

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        srlw	a5,a5,a6               # Logical Shift Right using srl and store result into a5
        sb	a5,0(a2)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return

_SRL_TEST_S8_: # signed char or int8_t Shift Right
        lb    a5, 0(a0)                # Load byte (signed) into a5 from the address strored at a0 (op1)
        slliw a6,a5,0x18               # Logical Shift-left a5 (op1) by 0x10 or 16 and store into a6
        srliw a6,a6,0x18               # Arithmentic shift-right a6 by 0x10 or 16 and store into a6
        lbu    a5,0(a1)                 # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        srlw   a5,a6,a5                 # Shift Right using SLL and store result into a5
        sb    a5,0(a2)                 # The byte result stored back to variable
	add   a0, x0, a5               # Set the return value
	jr    ra                       # return


_SRL_TEST_U16_: # unsigned short or uint16_t Shift Right

	lhu  a5, 0(a0)                 # Load half-word (unsigned) into a5 from the address strored at a0 (op1)
        lbu  a6,0(a1)                  # Load half-word (unsigned) into a6 from the address strored at a1 (op2)
        srlw  a5,a5,a6                  # Shift Right using srl and store result into a5
        sh   a5,0(a2)                  # The half word result stored back to variable
	add  a0, x0, a5                # Set the return value
	jr   ra                        # return

_SRL_TEST_S16_: # signed short or int16_t Shift Right

	lh    a5, 0(a0)                # Load half-word (signed) into a5 from the address strored at a0 (op1)
        slli  a6,a5,0x10               # Logical Shift-left a5 (op1) by 0x10 and store into a6
        srli  a6,a6,0x10               # Arithmentic shift-right a6 by 0x10 and store into a6
        lbu    a5,0(a1)                 # Load half-word (signed) into a5 from the address strored at a1 (op2)
        srlw   a5,a6,a5                 # Shift Right using SRL and store result into a5
        sh    a5,0(a2)                 # The word result stored back to variable
	add   a0, x0, a5               # Set the return value
	jr    ra                       # return

_SRL_TEST_U32_: # unsigned word or uint32_t Shift Right
	 lwu a5,0(a0)                  # Load word (unsigned) into a5 from the address strored at a0 (op1)
         lbu a6,0(a1)                  # Load word (unsigned) into a6 from the address strored at a1 (op2)
	 srlw a7,a5,a6     	       # Shift Right using SRL and store result into a7
         sw  a7,0(a2)                  # The double word result stored back to variable
	 add a0, x0, a7                # Set the return value double word
	 jr  ra                        # return

_SRL_TEST_S32_: # signed word or int32_t Shift Right

	lw  a5,0(a0)                   # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lbu  a6,0(a1)                   # Load word (unsigned) into a6 from the address strored at a1 (op2)
	srlw a7,a5,a6                   # Shift Right using SRL and store result into a7
        sw  a7,0(a2)                   # The double word result stored back to variable
	add a0, x0, a7                 # Set the return value double word
  	jr  ra                         # return

_SRL_TEST_U64_: # unsigned word or uint64_t Shift Right
	 ld a5,0(a0)                  # Load word (unsigned) into a5 from the address strored at a0 (op1)
         lbu a6,0(a1)                  # Load word (unsigned) into a6 from the address strored at a1 (op2)
	 srl a7,a5,a6     	       # Shift Right using SRL and store result into a7
         sd  a7,0(a2)                  # The double word result stored back to variable
	 add a0, x0, a7                # Set the return value double word
	 jr  ra                        # return

_SRL_TEST_S64_: # signed word or int64_t Shift Right

	ld  a5,0(a0)                   # Load word (unsigned) into a5 from the address strored at a0 (op1)
        lbu  a6,0(a1)                   # Load word (unsigned) into a6 from the address strored at a1 (op2)
	srl a7,a5,a6                   # Shift Right using SRL and store result into a7
        sd  a7,0(a2)                   # The double word result stored back to variable
	add a0, x0, a7                 # Set the return value double word
  	jr  ra                         # return
	

_SRL_TEST_U8SRC1_EQ_DEST_:


	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        srlw	a5,a5,a6               #  Shift Right  using SRL and store result into a5
	sb	a5,0(a2)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return

_SRL_TEST_U8SRC2_EQ_DEST_:


	lbu 	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
    	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        srlw    a6,a5,a6               # Shift Right using SRL and store result into a6
	sb	a6,0(a2)               # The byteresult stored back to variable
	add     a0, x0, a6             # Set the return value
	jr      ra                     # return

_SRL_TEST_U8SRC12_EQ_DEST_:


	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1 and op2)
        srlw	a5,a5,a5               # Shift Right using SRL and store result into a5
	sb  	a5,0(a1)               # The half-word result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SRL_TEST_U8ZEROSRC1_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
	srlw	a5,x0,a5               # Shift Right using SRL and store result into a5
	sb	a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SRL_TEST_U8ZEROSRC2_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        srlw	a5,a5,x0               # Shift Right using SRL and store result into a5
	sb	a5,0(a1)               # The byte result stored back to variable
	add     a0, x0, a5             # Set the return value
	jr      ra                     # return


_SRL_TEST_U8ZEROSRC12_:

       srlw	a5,x0,x0               # Shift Right using SRL and store result into a5
	sb	a5,0(a0)               # The byte result stored back to variable
	add     a0, a5, x0             # Set the return value
	jr      ra                     # return


_SRL_TEST_U8ZERODEST_:

	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
        srlw	x0,a6,a5               # Shift Right using SRL and store result into x0
	sb	x0,0(a2)               # The byte result stored back to variable
	add     a0, x0, x0             # Set the return value
	jr      ra                     # return


_SRL_TEST_U8DEST_BYPASS_:

		li	x4,0		       # Load immediate zero into x4 
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
        	lbu	a6,0(a1)               # Load byte (unsigned) into a5 from the address strored at a1 (op2)
        	srlw	a7,a6,a5               # Shift Right using SRL and store result into a7
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
		sb	a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5 
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label 
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_SRL_TEST_U8SRC12_BYPASS_:


		li	x4,0		       # Load immediate zero into x4
	1:	lbu	a5, 0(a0)              # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_1             # One No operation cycles are added
        	lbu	a6,0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_2             # Two No operation cycles are added
        	srlw	a7,a5,a6               # shift right using SRL and store result into a7
		sb	a7,0(a2)               # The byte result stored back to variable
		addi	x4,x4,1		       # Add immediate value to x4
		li	x5,2		       # Load immediate value into x5
		bne 	x4, x5, 1b	       # Branch not equals used to jump to the label
		add     a0, x0, a7             # Set the return value
		jr      ra                     # return



_SRL_TEST_U8SRC21_BYPASS_:


		li	x4,0			# Load immediate zero into x4
        1:	lbu	a5,0(a0)                # Load byte (unsigned) into a5 from the address strored at a0 (op1)
		TEST_INSERT_NOPS_2         	# Two No operation cycles are added
		lbu	a6, 0(a1)               # Load byte (unsigned) into a6 from the address strored at a1 (op2)
		TEST_INSERT_NOPS_1         	# One No operation cycles are added
        	srlw	a7,a5,a6                # shift right t using SRL and store result into a7
		sb	a7,0(a2)                # The byte result stored back to variable
		addi	x4,x4,1			# Add immediate value to x4
		li	x5,2			# Load immediate value into x5
		bne 	x4, x5, 1b		# Branch not equals used to jump to the label
		add     a0, x0, a7              # Set the return value
		jr      ra                      # return
