#!/usr/bin/env python3
#
# This script generates header file for Load and Store Instruction

from sys import argv
import random

BANK_COUNT = 62
dest_file  = argv[1]               #dest file
#test_count = argv[2]               #test count

rnd_list = []
mem_list = []
f= open(dest_file,"w+")

f.write("/*\r\n")
f.write("**\r\n")
f.write("*******************************************************************************\r\n")
f.write("**\r\n")
f.write("** Header file for creating I-Type and U-Type tests\r\n")
f.write("**\r\n")
f.write("** Usage : #include \"ui_load_store_2_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_LOAD_STORE_2_TEST_H\r\n")
f.write("#define UI_LOAD_STORE_2_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")


f.write("\r\n")
f.write("\r\n")


#Store byte and load byte signed Max offset
f.write("void test_sb_lb_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lb , op1,op2 , op3 , 2047, result, exp_result, testnumber , int8_t ,int8_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sb ,lb , 2047, result, testnumber ,int8_t , int8_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store byte and load byte unsigned Max offset
f.write("void test_sb_lbu_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lbu , op1,op2 , op3 , 2047, result, exp_result, testnumber , uint8_t ,uint8_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sb ,lbu , 2047, result, testnumber ,uint8_t , uint8_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store half word and load half word signed Max offset
f.write("void test_sh_lh_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lh , op1,op2 , op3 , 2046, result, exp_result, testnumber , int16_t ,int16_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sh ,lh , 2046, result, testnumber ,int16_t , int16_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Store half word and load half word unsigned Max offset
f.write("void test_sh_lhu_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lhu , op1,op2 , op3 , 2046, result, exp_result, testnumber , uint16_t ,uint16_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sh ,lhu , 2046, result, testnumber ,uint16_t , uint16_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store  word and load word signed Max offset
f.write("void test_sw_lw_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lw , op1,op2 , op3 , 2044, result, exp_result, testnumber , int32_t ,int32_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sw ,lw , 2044, result, testnumber ,int32_t , int32_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Store word and load  word unsigned Max offset
f.write("void test_sw_lwu_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lwu , op1,op2 , op3 , 2044, result, exp_result, testnumber , uint32_t ,uint32_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sw ,lwu , 2044, result, testnumber ,uint32_t , uint32_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store  double word and load doble word signed Max offset
f.write("void test_sd_ld_max_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sd , ld , op1,op2 , op3 , 2040, result, exp_result, testnumber , int64_t ,int64_t);\r\n")
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sd ,ld , 2040, result, testnumber ,int64_t , int64_t );}\r\n" )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

f.write("#endif /* UI_LOAD_STORE_2_TEST_H */\r\n")

f.close() 

