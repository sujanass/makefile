#!/usr/bin/env python3
#
# This script generates header file for LUI Instruction

from sys import argv
import random

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
f.write("** Usage : #include \"ui_lui_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_LUI_TEST_H\r\n")
f.write("#define UI_LUI_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



#Load Upper Immediate : Random Immediate 
f.write("void test_lui_type(int k)\r\n")
f.write("{\r\n")
rnd_list.clear()
for i in range(10):
    rnd_list.append(int( random.randrange(0 , 1048575 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(10):
	f.write("{	TEST_LUI_INSN_I_SPIKE(lui , op1 , %d, result, exp_result, testnumber , uint32_t ,int64_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LUI_TEST_RESULT_I(testnumber, %d , result, exp_result);} \r\n" % rnd_list[i]) 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(10):
	f.write("{	TEST_LUI_INSN_I( lui , %d, result, testnumber ,uint32_t , int64_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


f.write("#endif /* UI_LUI_TEST_H */\r\n")

f.close() 


