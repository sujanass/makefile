#!/usr/bin/env python3
#
# This script generates header file for I-Type and U-Type tests
from sys import argv
import random

dest_file  = argv[1]               #dest file
test_count = argv[2]               #test count

rnd_list = []

mem_list = []

f= open(dest_file,"w+")

f.write("/*\r\n")
f.write("**\r\n")
f.write("*******************************************************************************\r\n")
f.write("**\r\n")
f.write("** Header file for creating I-Type and U-Type tests\r\n")
f.write("**\r\n")
f.write("** Usage : #include \"ui_sanity_isa_1.h\"\r\n")
f.write("*******************************************************************************\r\n")
f.write("*/\r\n")
f.write("\r\n")

f.write("#ifndef UI_TEST_SANITY_ISA_1_H\r\n")
f.write("#define UI_TEST_SANITY_ISA_1_H\r\n")
f.write("\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
f.write("#include \"data.h\"               /*!< Testbench created data */\r\n")
f.write("#endif\r\n")


f.write("#define TEST_COUNT     (%d) /*!< Test count             */\r\n" % int(test_count))
f.write("\r\n")
f.write("\r\n")


f.write("int test_ui_sanity_isa_1_type(int num)\r\n")
f.write("{\r\n")

f.write ("volatile int testnumber=num; \r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit: addi\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_ADDI_INSN_I_SPIKE(addi, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_I(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32 bit: addiw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_I(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")



f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit : andi\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_ANDI_INSN_I_SPIKE64(andi, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_andi_I64(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_ANDI_INSN_I64(MAILBOX1, andi, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit : ori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_ORI_INSN_I_SPIKE64(ori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_ori_I64(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_ORI_INSN_I64(MAILBOX1, ori, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit : xori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_XORI_INSN_I_SPIKE64(xori, op1, %d, result, exp_result, testnumber);\r\n" % rnd_list[i])
	f.write("	print_test_results_xori_I64(testnumber, op1, op2, result, exp_result);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_XORI_INSN_I64(MAILBOX1, xori, op1, %d, result, testnumber);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit unsigned: slli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,63))

#f.write ("volatile int testnumber=k; \r\n")
#f.write ("volatile int testtypenum; \r\n")
#f.write("	testtypenum++;\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLLI_INSN_I_SPIKE(slli, op1, %d, result, exp_result, testnumber,uint64_t , uint64_t);\r\n" % rnd_list[i])
	f.write("	SLLI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLLI_INSN_I(MAILBOX1, slli, op1, %d, result, testnumber,uint64_t , uint64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit signed: slli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLLI_INSN_I_SPIKE(slli, op1, %d, result, exp_result, testnumber , int64_t, uint64_t);\r\n" % rnd_list[i])
	f.write("	SLLI_PRINT_TEST_RESULTS_S(testnumber, op1, op2, result, exp_result , int64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLLI_INSN_I(MAILBOX1, slli, op1, %d, result, testnumber,int64_t , uint64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit unsigned: slliw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLLIW_INSN_I_SPIKE(slliw, op1, %d, result, exp_result, testnumber , uint32_t , uint32_t );\r\n" % rnd_list[i])
	f.write("	SLLIW_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result , uint32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLLIW_INSN_I(MAILBOX1, slliw, op1, %d, result, testnumber, uint32_t , uint32_t );}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")



f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit signed: slliw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SLLIW_INSN_I_SPIKE(slliw, op1, %d, result, exp_result, testnumber , int32_t, uint32_t);\r\n" % rnd_list[i])
	f.write("	SLLIW_PRINT_TEST_RESULTS_S(testnumber, op1, op2, result, exp_result , int32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SLLIW_INSN_I(MAILBOX1, slliw, op1, %d, result, testnumber,int32_t , uint32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit unsigned: srli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,63))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRLI_INSN_I_SPIKE(srli, op1, %d, result, exp_result, testnumber,uint64_t , uint64_t);\r\n" % rnd_list[i])
	f.write("	SRLI_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result,uint64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRLI_INSN_I(MAILBOX1, srli, op1, %d, result, testnumber,uint64_t , uint64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit signed: srli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRLI_INSN_I_SPIKE(srli, op1, %d, result, exp_result, testnumber , int64_t, uint64_t);\r\n" % rnd_list[i])
	f.write("	SRLI_PRINT_TEST_RESULTS_S(testnumber, op1, op2, result, exp_result , int64_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRLI_INSN_I(MAILBOX1, srli, op1, %d, result, testnumber,int64_t , uint64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit unsigned: srliw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRLIW_INSN_I_SPIKE(srliw, op1, %d, result, exp_result, testnumber , uint32_t , uint32_t );\r\n" % rnd_list[i])
	f.write("	SRLIW_PRINT_TEST_RESULTS(testnumber, op1, op2, result, exp_result , uint32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRLIW_INSN_I(MAILBOX1, srliw, op1, %d, result, testnumber, uint32_t , uint32_t );}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit signed: srliw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))

f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRLIW_INSN_I_SPIKE(srliw, op1, %d, result, exp_result, testnumber , int32_t, uint32_t);\r\n" % rnd_list[i])
	f.write("	SRLIW_PRINT_TEST_RESULTS_S(testnumber, op1, op2, result, exp_result , int32_t);} \r\n")
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRLIW_INSN_I(MAILBOX1, srliw, op1, %d, result, testnumber,int32_t , uint32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit unsigned: sltiu\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,2047))


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

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit signed: slti\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(-2048,2047))


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

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit unsigned: srai\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,63))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRAI_INSN_I_SPIKE(srai,op1,%d,result,exp_result,testnumber,int64_t,int64_t);\r\n" % rnd_list[i])
	f.write("	SRAI_PRINT_RESULT_S(testnumber,op1,op2,result,exp_result,int64_t);} \r\n")
	f.write("	testnumber++;\r\n")

f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRAI_INSN_I(MAILBOX1,srai,op1,%d,result,testnumber,int64_t,int64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64bit signed: srai\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,63))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRAI_INSN_I_SPIKE(srai,op1,%d,result,exp_result,testnumber,int64_t,int64_t);\r\n" % rnd_list[i])
	f.write("	SRAI_PRINT_RESULT_S(testnumber,op1,op2,result,exp_result,int64_t);} \r\n")
	f.write("	testnumber++;\r\n")

f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRAI_INSN_I(MAILBOX1,srai,op1,%d,result,testnumber,int64_t,int64_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit unsigned: sraiw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRAIW_INSN_I_SPIKE(sraiw,op1,%d,result,exp_result,testnumber,uint32_t,int32_t );\r\n" % rnd_list[i])
	f.write("	SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result,exp_result,uint32_t);} \r\n")
	f.write("	testnumber++;\r\n")

f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRAIW_INSN_I(MAILBOX1,sraiw,op1,%d,result,testnumber,uint32_t,int32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")

f.write("\r\n")
f.write("\r\n")



f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 32bit signed: sraiw\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")


rnd_list.clear()
for i in range(3):
	rnd_list.append(random.randint(0,31))


f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):

	f.write("{	TEST_SRAIW_INSN_I_SPIKE(sraiw,op1,%d,result,exp_result,testnumber,int32_t,int32_t);\r\n" % rnd_list[i])
	f.write("	SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result,exp_result,int32_t);} \r\n")
	f.write("	testnumber++;\r\n")

f.write("#else\r\n")
for i in range(3):
	f.write("{	TEST_SRAIW_INSN_I(MAILBOX1,sraiw,op1,%d,result,testnumber,int32_t,int32_t);}\r\n" % int(rnd_list[i]))
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")


f.write("\r\n")
f.write("\r\n")


f.write("#ifdef SPIKE_RUN\r\n")
f.write("	printf(\"\\n------------------------------\");\r\n")
f.write("	printf(\"\\nTest/> Instruction 64 bit: z.roli\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2048,2047))

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
f.write("	printf(\"\\nTest/> Instruction 64 bit: z.rori\");\r\n")
f.write("	printf(\"\\n------------------------------\\n\");\r\n")
f.write("#endif\r\n")

f.write("#ifdef SPIKE_RUN\r\n")
rnd_list.clear()
for i in range(int(test_count)):
	rnd_list.append(random.randint(-2048,2047))

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


f.write("\r\n")
f.write("\r\n")

f.write("return testnumber;")
f.write("}\r\n")


#Load and Store test cases: all bank scenariors 

#Store byte and load byte 
f.write("void test_sb_lb_type(int k)\r\n")
f.write("{\r\n")
f.write("uint64_t base_addrs = START_ADDRS + 0x800;\r\n ")
f.write(" int64_t *addrs_pt = base_addrs ;\r\n" )
rnd_list.clear()
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lb , op1,op2 , op3 , %d, result, exp_result, testnumber , int8_t ,int8_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,1) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sb , lbu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint8_t ,uint8_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,2) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lh , op1,op2 , op3 , %d, result, exp_result, testnumber , int16_t ,int16_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,2) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sh , lhu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint16_t ,uint16_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,4) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lw , op1,op2 , op3 , %d, result, exp_result, testnumber , int32_t ,int32_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,4) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sw , lwu , op1,op2 , op3 , %d, result, exp_result, testnumber , uint32_t ,uint32_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IU(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
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
for i in range(3):
    rnd_list.append(int( random.randrange(-2048 , 2047 ,8) ))

f.write ("volatile int testnumber=k; \r\n")
f.write("#ifdef SPIKE_RUN\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n ")
	f.write("{	TEST_LOAD_STORE_INSN_I_SPIKE(sd , ld , op1,op2 , op3 , %d, result, exp_result, testnumber , int64_t ,int64_t);\r\n" % rnd_list[i] )
	f.write("	PRINT_LOAD_STORE_TEST_RESULT_IS(testnumber, op1, op2,op3 , result, exp_result);} \r\n") 
	f.write("	testnumber++;\r\n")
f.write("#else\r\n")
for i in range(3):
	f.write(" addrs_pt = base_addrs ; \r\n" )
	f.write("base_addrs += 0x1000 ; \r\n")
	f.write("{	TEST_LOAD_STORE_INSN_I( MAILBOX1, sd ,ld , %d, result, testnumber ,int64_t , int64_t );}\r\n" % rnd_list[i] )
	f.write("	testnumber++;\r\n")
f.write("#endif\r\n")
f.write("}\r\n")
f.write("\r\n")



f.write("\r\n")
f.write("#endif /* UI_TEST_SANITY_ISA_1_H */\r\n")

