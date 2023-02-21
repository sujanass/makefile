#!/usr/bin/env python3
#
# This script generates header file for I-Type and U-Type tests

from sys import argv
import random

dest_file  = argv[1]               #dest file
test_count = argv[2]             #test count

rnd_list = []

f= open(dest_file,"w+")

f.write("/*\r\n")
f.write("**\r\n")
f.write("*******************************************************************************\r\n")
f.write("**\r\n")
f.write("** Header file for creating I-Type and U-Type tests\r\n")
f.write("**\r\n")
f.write("** Usage : #include \"ui_cust_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_TEST_H\r\n")
f.write("#define UI_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")


f.write("#define TEST_COUNT     (%d) /*!< Test count             */\r\n" % int(test_count))
f.write("\r\n")

#f.write("extern volatile int status;\r\n")
f.write("extern volatile int testnumber;\r\n")
f.write("extern volatile int testtypenum;\r\n")
f.write("\r\n")

f.write("void test_ui_custom_type(void)\r\n")
f.write("{\r\n")
f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 8 bit: z.roli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I8_SPIKE(z.roli, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_roli(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I8(MAILBOX1, z.roli, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 16 bit: z.roli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I16_SPIKE(z.roli, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_roli(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I16(MAILBOX1, z.roli, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32 bit: z.roli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I32_SPIKE(z.roli, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_roli(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I32(MAILBOX1, z.roli, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit: z.roli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I64_SPIKE(z.roli, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_roli(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I64(MAILBOX1, z.roli, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 8 bit: z.rori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I8_SPIKE(z.rori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_rori(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I8(MAILBOX1, z.rori, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 16 bit: z.rori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I16_SPIKE(z.rori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_rori(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I16(MAILBOX1, z.rori, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32 bit: z.rori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I32_SPIKE(z.rori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_rori(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I32(MAILBOX1, z.rori, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("	testtypenum++;\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit: z.rori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2047,2048))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I64_SPIKE(z.rori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_rori(testnumber, op1, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_I64(MAILBOX1, z.rori, op1, %d, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction : z.mvir\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(0,0xFFFFF))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_U_SPIKE(z.mvir, 0x%x, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_mvir(testnumber, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_U(z.mvir, 0x%x, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction : z.mviru\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(0,0xFFFFF))

for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_U_SPIKE_U(z.mviru, 0x%x, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_mviru(testnumber, imm, result, exp_result); }\r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(int(test_count)):
	f.write("{	TEST_CUSTOM_INSN_U_U(z.mviru, 0x%x, result, testnumber); }\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")


f.write("#endif /* UI_TEST_H */\r\n")

f.close() 
