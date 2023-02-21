# This is the library for providing assembly level functions used by various test applications.

//******** Unsigned Integer  **********
.global _SRAW_TEST_U8_ 
.global _SRAW_TEST_U16_ 
.global _SRAW_TEST_U32_ 
.global _SRA_TEST_U64_

//******  Signed Integer    ***********
.global _SRAW_TEST_S8_ 
.global _SRAW_TEST_S16_ 
.global _SRAW_TEST_S32_ 
.global _SRA_TEST_S64_

//******  Compliance Test   ***********
.global _SRAW_TEST_U8SRC1_EQ_DEST_
.global _SRAW_TEST_U8SRC2_EQ_DEST_
.global _SRAW_TEST_U8SRC12_EQ_DEST_
.global _SRAW_TEST_U8ZEROSRC1_
.global _SRAW_TEST_U8ZEROSRC2_
.global _SRAW_TEST_U8ZEROSRC12_
.global _SRAW_TEST_U8ZERODEST_
.global _SRAW_TEST_U8DEST_BYPASS_
.global _SRAW_TEST_U8SRC12_BYPASS_
.global _SRAW_TEST_U8SRC21_BYPASS_



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



_SRAW_TEST_U8_:           # unsigned char or uint8_t 

    lbu  a5, 0(a0)        # Load 8-bit(byte) unsigned into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bit(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sb   a7, 0(a2)        # Byte (8-bit) Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value


_SRAW_TEST_U16_:          # unsigned char or uint16_t 

    lhu  a5, 0(a0)        # Load 16-bits(2 bytes) unsigned into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sh   a7, 0(a2)        # 2-Bytes (16-bits)[HALF WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value
  

_SRAW_TEST_U32_:           # unsigned char or uint32_t 

    lwu  a5, 0(a0)        # Load 24-bits(3 bytes) unsigned into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sw   a7, 0(a2)        # 3-Bytes (24-bits)[A WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value
 

_SRA_TEST_U64_:           # unsigned char or uint64_t 

    ld   a5, 0(a0)        # Load 32-bits(4 bytes) unsigned into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sra  a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sd   a7, 0(a2)        # 4-Bytes (32-bits)[A WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value


_SRAW_TEST_S8_:           #signed char or int8_t 

    lb   a5, 0(a0)        # Load 8-bit(byte) signed into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bit(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sb   a7, 0(a2)        # Byte (8-bit) Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value


_SRAW_TEST_S16_:           # signed char or int16_t 

    lh   a5, 0(a0)        # Load 16-bits(2 bytes) signed into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sh   a7, 0(a2)        # 2-Bytes (16-bits)[HALF WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value
  

_SRAW_TEST_S32_:          # signed char or int32_t 

    lw   a5, 0(a0)        # Load 24-bits(3 bytes) signed into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sraw a7,a5,a6         # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sw   a7, 0(a2)        # 3-Bytes (24-bits)[A WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value
 

_SRA_TEST_S64_:           # signed char or int64_t 

    ld   a5, 0(a0)        # Load 32-bits(4 bytes) signed into a5 from the address stored at a0(op1)
    lbu  a6, 0(a1)        # Load 8-bits(byte) unsigned into a6 from the address stored at a1(op2)
    sra a7,a5,a6          # Perform Right shift operation on a5 and by how much a5 will be shifted is decided by a6(op2)
    sd   a7, 0(a2)        # 4-Bytes (32-bits)[A WORD] Result will get stored back to the variable
    add  a0,x0,a7         # Set return value
    jr   ra               # Return Value

//***********************   Compliance Test      *****************

_SRAW_TEST_U8SRC1_EQ_DEST_:

	lbu	 a5, 0(a0)        # Load byte (unsigned) into a5 from the address stored at a0 (op1)
    lbu	 a6, 0(a1)        # Load byte (unsigned) into a6 from the address stored at a1 (op2)
    sraw a5,a5,a6         # Shift Right using SRA and store result into a5
	sb	 a5, 0(a2)        # The byte result stored back to variable a5
	add  a0,x0,a5         # Set the return value
	jr   ra               # Return Value

_SRAW_TEST_U8SRC2_EQ_DEST_:

    lbu  a5, 0(a0)        # Load byte (unsigned) into a5 from the address stored at a0 (op1)
    lbu	 a6, 0(a1)        # Load byte (unsigned) into a6 from the address stored at a1 (op2)
    sraw a6,a5,a6         # Shift Right using SRA and store result into a6
	sb	 a6, 0(a2)        # The byte result stored back to variable a6
	add  a0,x0,a6         # Set the return value
	jr   ra               # Return Value

_SRAW_TEST_U8SRC12_EQ_DEST_:

    lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address stored at a0 (op1 and op2)
    sraw a5,a5,a5          # Shift Right using SRA and store result into a5
	sb   a5, 0(a1)         # The half-word result stored back to variable a5
	add  a0,x0,a5          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8ZEROSRC1_:

	lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address stored at a0 (op1)
	sraw a5,x0,a5          # Shift Right using SRA and store result into a5
	sb	 a5, 0(a1)         # The byte result stored back to variable a5
	add  a0,x0,a5          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8ZEROSRC2_:

    lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address stored at a0 (op1)
    sraw a5,a5,x0          # Shift Right using SRA and store result into a5
	sb	 a5, 0(a1)         # The byte result stored back to variable a5
	add  a0,x0,a5          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8ZEROSRC12_:

    sraw a5,x0,x0          # Shift Right using SRA and store result into a5
	sb	 a5, 0(a0)         # The byte result stored back to variable a5
	add  a0,a5,x0          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8ZERODEST_:

    lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address stored at a0 (op1)
    lbu	 a6, 0(a1)         # Load byte (unsigned) into a6 from the address stored at a1 (op2)
    sraw x0,a6,a5          # Shift Right using SRL and store result into x0
	sb	 x0, 0(a2)         # The byte result stored back to variable
	add  a0,x0,x0          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8DEST_BYPASS_:

    li	 x4, 0		       # Load immediate zero into x4 
1:	lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address stored at a0 (op1)
    lbu	 a6, 0(a1)         # Load byte (unsigned) into a5 from the address stored at a1 (op2)
    sraw a7,a6,a5          # Shift Right using SRA and store result into a7
	TEST_INSERT_NOPS_2     # Two No operation cycles are added
	sb	 a7,0(a2)          # The byte result stored back to variable a7
	addi x4,x4,1		   # Add immediate value to x4
	li	 x5, 2		       # Load immediate value into x5 
	bne  x4,x5,1b	       # Branch not equals used to jump to the label 
	add  a0,x0,a7          # Set the return value
	jr   ra                # Return Value


_SRAW_TEST_U8SRC12_BYPASS_:

    li	 x4, 0		       # Load immediate zero into x4
1:	lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address strored at a0 (op1)
	TEST_INSERT_NOPS_1     # One No operation cycles are added
    lbu	 a6, 0(a1)         # Load byte (unsigned) into a6 from the address strored at a1 (op2)
	TEST_INSERT_NOPS_2     # Two No operation cycles are added
    sraw a7,a5,a6          # shift right using SRL and store result into a7
	sb	 a7, 0(a2)         # The byte result stored back to variable
	addi x4,x4,1		   # Add immediate value to x4
	li	 x5,2		       # Load immediate value into x5
	bne  x4,x5,1b	       # Branch not equals used to jump to the label
	add  a0,x0,a7          # Set the return value
	jr   ra                # Return Value



_SRAW_TEST_U8SRC21_BYPASS_:

    li	 x4, 0			   # Load immediate zero into x4
1:	lbu	 a5, 0(a0)         # Load byte (unsigned) into a5 from the address strored at a0 (op1)
	TEST_INSERT_NOPS_2     # Two No operation cycles are added
	lbu	 a6, 0(a1)         # Load byte (unsigned) into a6 from the address strored at a1 (op2)
	TEST_INSERT_NOPS_1     # One No operation cycles are added
    sraw a7,a5,a6          # shift right t using SRL and store result into a7
	sb	 a7, 0(a2)         # The byte result stored back to variable
	addi x4,x4,1		   # Add immediate value to x4
	li	 x5, 2			   # Load immediate value into x5
	bne  x4,x5,1b	       # Branch not equals used to jump to the label
	add  a0,x0,a7          # Set the return value
	jr   ra                # Return Value
