#!/usr/bin/env python3
#
# This script generates header file for AUIPC Instruction

from sys import argv
import random

dest_file  = argv[1]               #dest file
#test_count = argv[2]               #test count

rnd_list = []
rnd1_list = []
rnd2_list = []
mem_list = []
f= open(dest_file,"w+")

f.write("/*\r\n")
f.write("**\r\n")
f.write("*******************************************************************************\r\n")
f.write("**\r\n")
f.write("** Header file for creating I-Type and U-Type tests\r\n")
f.write("**\r\n")
f.write("** Usage : #include \"ui_auipc_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_AUIPC_TEST_H\r\n")
f.write("#define UI_AUIPC_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



#Load Upper Immediate : Random Immediate 
f.write("void test_auipc_type(int k)\r\n")
f.write("{\r\n")
rnd_list.clear()
for i in range(10):
    rnd_list.append(int( random.randrange(0 , 1048575 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write("{	TEST_AUIPC_INSN_I_SPIKE(auipc , op1 , %d, result, exp_result, testnumber , uint32_t ,int64_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_AUIPC_TEST_RESULT_I(testnumber, %d , result, exp_result);} \r\n" % rnd_list[i]) 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_AUIPC_INSN_I( auipc , %d, result, testnumber ,uint32_t , int64_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")



#Load Upper Immediate : Random Immediate 
f.write("void test_auipc_jalr_type(int k)\r\n")
f.write("{\r\n")
rnd1_list.clear()
rnd2_list.clear()
for i in range(3):
    rnd1_list.append(int( random.randrange(0 , 1048575 , 4))  )

for i in range(3):
    rnd2_list.append(int( random.randrange(0 , 2048 , 4))  )


f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write("{	TEST_AUIPC_INSN_I_SPIKE(auipc , op1 , %d, result, exp_result, testnumber , uint32_t ,int64_t);\r\n" % rnd1_list[i] )
	f.write("	PRINT_AUIPC_TEST_RESULT_I(testnumber, %d , result, exp_result);} \r\n" % rnd1_list[i]) 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_AUIPC_JALR_INSN_I( auipc , jalr, %d, %d, result, testnumber ,uint32_t , int64_t );}\r\n" % (rnd1_list[i] ,rnd2_list[i]) )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")

#Load Upper Immediate : Random Immediate 
f.write("void test_jalr_auipc_type(int k)\r\n")
f.write("{\r\n")
rnd1_list.clear()
rnd2_list.clear()
for i in range(3):
    rnd1_list.append(int( random.randrange(0 , 1048575 , 4))  )

for i in range(3):
    rnd2_list.append(int( random.randrange(0 , 2048 , 4))  )


f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(1):
	f.write("{	TEST_AUIPC_INSN_I_SPIKE(auipc , op1 , %d, result, exp_result, testnumber , uint32_t ,int64_t);\r\n" % rnd1_list[i] )
	f.write("	PRINT_AUIPC_TEST_RESULT_I(testnumber, %d , result, exp_result);} \r\n" % rnd1_list[i]) 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(1):
	f.write("{	TEST_JALR_AUIPC_INSN_I( jalr , auipc, %d, %d , result, testnumber ,uint32_t , int64_t );}\r\n" % (rnd2_list[i],rnd1_list[i]) )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")



f.write("#endif /* UI_AUIPC_TEST_H */\r\n")

f.close() 



