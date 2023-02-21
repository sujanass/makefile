#!/usr/bin/env python3
#
# This script generates header file for Load Instruction

from sys import argv
import random
BANK_COUNT = 62 ; 
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
f.write("** Usage : #include \"ui_load_store_1_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_LOAD_STORE_1_TEST_H\r\n")
f.write("#define UI_LOAD_STORE_1_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")

#Load and Store test cases: all bank scenariors 

#Store byte and load byte 
f.write("void test_sb_lb_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lb , op1,op2 , op3 , %d, result, exp_result, testnumber , int8_t ,int8_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sb ,lb , %d, result, testnumber ,int8_t , int8_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store byte and load byte unsigned 
f.write("void test_sb_lbu_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lbu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint8_t ,uint8_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sb ,lbu , %d, result, testnumber ,uint8_t , uint8_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Store half word and load half word signed 
f.write("void test_sh_lh_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,2) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lh , op1,op2 , op3 , %d, result, exp_result, testnumber , int16_t ,int16_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sh ,lh , %d, result, testnumber ,int16_t , int16_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Store half word and load  half word unsigned 
f.write("void test_sh_lhu_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,2) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lhu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint16_t ,uint16_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sh ,lhu , %d, result, testnumber ,uint16_t , uint16_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


#Store word and load word signed 
f.write("void test_sw_lw_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,4) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lw , op1,op2 , op3 , %d, result, exp_result, testnumber , int32_t ,int32_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sw ,lw , %d, result, testnumber ,int32_t , int32_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Store  word and load word unsigned 
f.write("void test_sw_lwu_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,4) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lwu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint32_t ,uint32_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sw ,lwu , %d, result, testnumber ,uint32_t , uint32_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")
#Store double word and load double word 
f.write("void test_sd_ld_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(BANK_COUNT):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,8) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sd , ld , op1,op2 , op3 , %d, result, exp_result, testnumber , int64_t ,int64_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(BANK_COUNT):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sd ,ld , %d, result, testnumber ,int64_t , int64_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")



f.write("#endif /* UI_LOAD_STORE_1_TEST_H */\r\n")

f.close() 

