/*---------------modulo inverse on core FOR UNSIGNED 16 BIT------------*/
#define MODULO_ARTHEMATIC(mb,op1_dt,op2_dt,op1,op2,result_full,tn)\
    op1_dt a;\
    op2_dt b;\
    op2_dt result_full;\
    a=(uint16_t)generate_random_num(mb);\
    b=(uint16_t)generate_random_num(mb);\
    result_full=op1%op2;\
    actual_result[(tn-1)*3 + 0] = op1; \
    actual_result[(tn-1)*3 + 1] = op2; \
    actual_result[(tn-1)*3 + 2] = result_full; \

/*-------------------modulo inverse on spike--------------*/
#define MODULO_ARTHEMATIC_SPIKE(op1,op2,result_full,result_tb,tn)\
    op1_dt op1;\
    op1_dt op2;\
    uint16_t result_full,result_tb;\
    op1 = (uint16_t)data[(tn-1)*3 + 0]; \
    op2 = (uint16_t)data[(tn-1)*3 + 1]; \
    result_full=op1%op2;\
    result_tb = (uint16_t)data[(tn-1)*3 + 2];\ 
/*--------------print results-------------------*/
#define PRINT_RESULT_MODULO(op1,op2,a_result,e_result,test_num) \
	if(a_result == e_result) \
	  printf("Test/> [%3d] MODULUS: %15u | %15u: E-result = %15u, A-result = %15u : Status = [PASS]\n", test_num, op1, op2, a_result, e_result); \
    else \
	  printf("Test/> [%3d] MODULUS: %15u | %15u: E-result = %15u, A-result = %15u : Status = [FAIL]\n", test_num, op1, op2, a_result, e_result);



