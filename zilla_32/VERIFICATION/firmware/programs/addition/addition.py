#!/usr/bin/env python3
#
# This script generates header file for I-Type and U-Type tests
from sys import argv
import random

dest_file  = argv[1]               #dest file
#test_count = argv[2]               #test count

rnd_list = []

f= open(dest_file,"w+")

f.write("/*\r\n")
f.write("**\r\n")
f.write("*******************************************************************************\r\n")
f.write("**\r\n")
f.write("** Header file for creating I-Type and U-Type tests\r\n")
f.write("**\r\n")
f.write("** Usage : #include \"ui_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_TEST_H\r\n")
f.write("#define UI_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")


#f.write("#define TEST_COUNT     (%d) /*!< Test count             */\r\n" % int(test_count))
f.write("\r\n")
f.write("\r\n")


f.write("void test_ui_type(void)\r\n")
f.write("{\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit: addi\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(15):
	rnd_list.append(random.randint(0,63))

f.write ("volatile int testnumber=1; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(15):

	f.write("{	TEST_ADDI_INSN_I_SPIKE(addi, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_I(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(15):
	f.write("{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32 bit: addiw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(15):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(15):

	f.write("{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_I(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(15):
	f.write("{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")



f.write("}\r\n")
f.write("\r\n")

f.write("#endif /* UI_TEST_H */\r\n")

f.close() 
