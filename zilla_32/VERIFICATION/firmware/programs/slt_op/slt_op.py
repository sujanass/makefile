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
f.write("** Usage : #include \"ui_slt_test.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_SLT_TEST_H\r\n")
f.write("#define UI_SLT_TEST_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")


#f.write("#define TEST_COUNT     (%d) /*!< Test count             */\r\n" % int(test_count))
f.write("\r\n")
f.write("\r\n")


f.write("void test_sltiu_u8_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,255))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTIU_INSN_I_SPIKE(sltiu, op1, %d, result, exp_result, testnumber,uint8_t , uint8_t);\r\n" % rnd_list[i])
	f.write("	SLTIU_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint8_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTIU_INSN_I(MAILBOX1, sltiu, op1, %d, result, testnumber,uint8_t , uint8_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("void test_sltiu_u16_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTIU_INSN_I_SPIKE(sltiu, op1, %d, result, exp_result, testnumber,uint16_t , uint16_t);\r\n" % rnd_list[i])
	f.write("	SLTIU_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint16_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTIU_INSN_I(MAILBOX1, sltiu, op1, %d, result, testnumber,uint16_t , uint16_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")




f.write("\r\n")
f.write("\r\n")


f.write("void test_sltiu_u32_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTIU_INSN_I_SPIKE(sltiu, op1, %d, result, exp_result, testnumber,uint32_t , uint32_t);\r\n" % rnd_list[i])
	f.write("	SLTIU_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTIU_INSN_I(MAILBOX1, sltiu, op1, %d, result, testnumber,uint32_t , uint32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")




f.write("\r\n")
f.write("\r\n")


f.write("void test_sltiu_u64_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTIU_INSN_I_SPIKE(sltiu, op1, %d, result, exp_result, testnumber,uint64_t , uint64_t);\r\n" % rnd_list[i])
	f.write("	SLTIU_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTIU_INSN_I(MAILBOX1, sltiu, op1, %d, result, testnumber,uint64_t , uint64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("void test_slti_s8_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-128,127))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTI_INSN_I_SPIKE(slti, op1, %d, result, exp_result, testnumber,int8_t , int8_t);\r\n" % rnd_list[i])
	f.write("	SLTI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,int8_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTI_INSN_I(MAILBOX1, slti, op1, %d, result, testnumber,int8_t , int8_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("void test_slti_s16_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTI_INSN_I_SPIKE(slti, op1, %d, result, exp_result, testnumber,int16_t , int16_t);\r\n" % rnd_list[i])
	f.write("	SLTI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,int16_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTI_INSN_I(MAILBOX1, slti, op1, %d, result, testnumber,int16_t , int16_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("void test_slti_s32_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTI_INSN_I_SPIKE(slti, op1, %d, result, exp_result, testnumber,int32_t , int32_t);\r\n" % rnd_list[i])
	f.write("	SLTI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,int32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTI_INSN_I(MAILBOX1, slti, op1, %d, result, testnumber,int32_t , int32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")



f.write("\r\n")
f.write("\r\n")


f.write("void test_slti_s64_ui_type(int k)\r\n")
f.write("{\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLTI_INSN_I_SPIKE(slti, op1, %d, result, exp_result, testnumber,int64_t , int64_t);\r\n" % rnd_list[i])
	f.write("	SLTI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,int64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLTI_INSN_I(MAILBOX1, slti, op1, %d, result, testnumber,int64_t , int64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")




f.write("}\r\n")
f.write("\r\n")


f.write("#endif /* UI_SLT_TEST_H */\r\n")

f.close() 


