//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//                                                                                                              //
//**************************************************************************************************************//                                                                                                              //
//                                                                                                              //
//FILE NAME:                                                                                                    //
//DESCRIPTION:                                                                                                  //   
//AUTHOR:                                                                                                       //               
//DATE:                                                                                                         //
//LAST MODIFIED BY:                                                                                             //
//LAST MODIFIED ON:                                                                                             //
//                                                                                                              //      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PRINT_RESULT_CRC(flag,flag_tb,len,rslt_tb,rslt_full,tn) \
for(int i=0;i<len;i++)\
{\
    if(rslt_tb == rslt_full)\
        printf("\n E-result --> [%d] A-result --> [%d]\n",rslt_tb[i],rslt_full[i]);\
    else\
        printf("\n E-result --> [%d] A-result --> [%d]\n",rslt_tb[i],rslt_full[i]);\
}\
if(flag == flag_tb)\
 	    printf("\nTest/> [%3d] crc --> E-result: [%d] Number of errors  A-result: [%d] Number of errors  Status = [PASS]\n",tn,flag_tb,flag);\
    else\
        printf("\nTest/> [%3d] crc --> E-result: [%d] Number of errors  A-result: [%d] Number of errors  Status = [FAIL]\n",tn,flag_tb,flag);\

/*********************************** CRC Test MACROs ********************************************/  
/* Macro for crc test without spike */
    #define CRC_TEST_C(mb,data_dec,gen_dec,flag,rslt_full,tn)\
    char temp[100],total[100],data_c[100],data_arr[100],gen_arr[100],gen[100],temp_r[100],rslt_full[100];\
    int8_t i,j,datalen,genlen,len;\
    data_dec = (uint8_t)generate_random_num(MAILBOX1);/*random number generation for data to be transmitted*/\
    gen_dec = (rand() % (15 - 9 + 1)) + 9;/*random number generation for genpoly between 9 to 15*/\
    uint8_t g_dummy = data_dec;\
    uint8_t q_dummy = gen_dec;\
    z_printf("Random Data to be transmitted in Decimal : %d\n",data_dec);\
    z_printf("Random Gen-poly in Decimal : %d\n",gen_dec);\
	i = 0;/*initializing i to 0*/\
	while (data_dec > 0) {/*while loop for conversion of decimal random number to binary for data*/\
		data_c[i] = data_dec % 2;\
		data_dec = data_dec / 2;\
		i++;\
	}\
    for (j = i - 1; j >= 0; j--)\
    {\
    z_printf("Data to be transmitted : %d\n", data_c[j]);\
    }\
    datalen = i;/*Length of binary data*/\
	i = 0;/*initializing i to 0*/\
	while (gen_dec > 0) {/*while loop for conversion of decimal random number to binary for gen-poly*/\
		gen[i] = gen_dec % 2;\
		gen_dec = gen_dec / 2;\
		i++;\
	}\
    genlen = i;/*Length of binary gen-poly*/\
	for ( j = i - 1; j >= 0; j--)\
    {\
    z_printf("Gen-poly : %d\n", gen[j]);\
    }\
    z_printf(" Data length is : %d\n",datalen);\
    z_printf(" Key length is : %d\n",genlen);\
	len=(datalen+genlen)-1;/*Total length --> Data+(genlen-1)*/\
    z_printf(" Total Data Length is : %d\n",len);\
    actual_result[(tn-1)*30 + 0] = g_dummy;\
    actual_result[(tn-1)*30 + 1] = q_dummy;\
    for(i=0;i<datalen;i++)                /*data_arr array*/\
    {\
        data_arr[(datalen-1)-i]=data_c[i];\
    }\
    for(i=1;i<genlen;i++)                /*gen_arr array*/\
    {\
        gen_arr[(genlen-1)-i]=gen[i];\
    }\
    for(i=datalen;i<len;i++)/*Append zeros*/\
    {\
        data_arr[i]=0;\
    }\
    for(i=0;i<len;i++)/*pushing the data+zeros to total array --> used later in reciever*/\
    {\
        total[i]=data_arr[i];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))/*if loop to check whether MSB & LSB of Gen-poly is 1*/\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp[j]=data_arr[j];/*pushing the 1st four bits to array --> temp(in order to perform xor operation)*/\
    }\
    while(j<=len)/*CRC code starts from here*/\
	{\
        if(temp[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp[i] = (( temp[i] == gen_arr[i])?0:1);/*xor operation*/\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp[i]=temp[i+1];/*update temp value*/\
        }\
        temp[i]=data_arr[j++];/*update temp value*/\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    data_arr[i]=temp[i-datalen];/*append crc code*/\
    }\
    for(i=0;i<len;i++)\
    {\
        z_printf("-------------------Transmitted Code Word:--------------%d\n", data_arr[i]);\
        actual_result[(tn-1)*30 + (i+2)] = data_arr[i];/*to dump values in the data.h*/\
    }\
    }\
    for(j=0;j<len;j++)\
    {\
        z_printf("------------Received code word :-------------------- %d\n",data_arr[j]);\
        actual_result[(tn-1)*30 + (j+len+2)] = data_arr[j];/*to dump values in the data.h*/\
        rslt_full[j]=data_arr[j];/*to compare array values of c and spike*/\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))/*reciever side operation*/\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp_r[j]=total[j];\
    }\
    while(j<=len)\
	{\
        if(temp_r[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp_r[i] = (( temp_r[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp_r[i]=temp_r[i+1];\
        }\
        temp_r[i]=total[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    total[i]=temp_r[i-datalen];\
    }\
    int f=0;/*dummy variable*/\
    flag=0;\
    while(f<len)\
    {\
        if(data_arr[f]==total[f])/*comparing recieved and transmitted arrays*/\
        {\
        f++;\
        }\
        else\
        {\
            flag=flag+1;\
            f++;\
        }\
    }\
    actual_result[(tn-1)*30 + 29] = flag;\
    if(flag == 0)\
        {\
            z_printf("\n-----Successful!!-----\n");\
            z_printf("\n-----Received code word contains %d errors...--------\n", flag);}\
	else\
	    z_printf("\n-----Received code word contains %d errors...--------\n", flag);\
    }
	

//////////////////////////////////////////////////////SPIKE_WITHOUT_ERRORS/////////////////////////////////////////////////////////////////////
    
    #define CRC_TEST_SPIKE(data_dec_tb,gen_dec_tb,flag,flag_tb,len,rslt_tb,rslt_full,tn)\
    char temp[100],total[100],data_spike[100],data_arr[100],gen_arr[100],gen[100],temp_r[100],rslt_tb[100],rslt_full[100];\
    int8_t i,j,datalen,genlen,len;\
    data_dec_tb = (uint8_t)data[(tn-1)*30 + 0];\
    gen_dec_tb = (uint8_t)data[(tn-1)*30 + 1];\
    flag = (uint8_t)data[(tn-1)*30 + 29];\
    printf("Random Data to be transmitted in Decimal [%d] & Random Gen-poly in Decimal : [%d]\n",data_dec_tb,gen_dec_tb);\
    i = 0;/*initializing i to 0*/\
	while (data_dec_tb > 0) {/*while loop for conversion of decimal random number to binary for data_spike*/\
		data_spike[i] = data_dec_tb % 2;\
		data_dec_tb = data_dec_tb / 2;\
		i++;\
	}\
    datalen = i;/*Length of binary data_spike*/\
	i = 0;/*initializing i to 0*/\
	while (gen_dec_tb > 0) {/*while loop for conversion of decimal random number to binary for gen-poly*/\
		gen[i] = gen_dec_tb % 2;\
		gen_dec_tb = gen_dec_tb / 2;\
		i++;\
	}\
    genlen = i;/*Length of binary gen-poly*/\
    len=(datalen+genlen)-1;/*Total length --> Data+(genlen-1)*/\
    for(i=0;i<len;i++)\
    {\
        rslt_full[i]=(uint8_t)data[(tn-1)*30 + (i+len+2)];\
    }\
    for(i=0;i<datalen;i++)                /*data_arr array*/\
    {\
        data_arr[(datalen-1)-i]=data_spike[i];\
    }\
    for(i=1;i<genlen;i++)                /*gen_arr array*/\
    {\
        gen_arr[(genlen-1)-i]=gen[i];\
    }\
    for(i=datalen;i<len;i++)\
    {\
        data_arr[i]=0;\
    }\
    for(i=0;i<len;i++)\
    {\
        total[i]=data_arr[i];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp[j]=data_arr[j];\
    }\
    while(j<=len)\
	{\
        if(temp[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp[i] = (( temp[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp[i]=temp[i+1];\
        }\
        temp[i]=data_arr[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    data_arr[i]=temp[i-datalen];\
    }\
    }\
    for(j=0;j<len;j++)\
    {\
        rslt_tb[j]=(uint8_t)data[(tn-1)*30 + (j+len+2)];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp_r[j]=total[j];\
    }\
    while(j<=len)\
	{\
        if(temp_r[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp_r[i] = (( temp_r[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp_r[i]=temp_r[i+1];\
        }\
        temp_r[i]=total[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    total[i]=temp_r[i-datalen];\
    }\
    int f=0;\
    flag_tb=0;\
    while(f<len)\
    {\
        if(data_arr[f]==total[f])\
        {\
        f++;\
        }\
        else\
        {\
            flag_tb=flag_tb+1;\
            f++;\
        }\
    }\
}\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    #define CRC_TEST_ERROR_C(mb,data_dec,gen_dec,flag,rslt_full,tn)\
    char temp[100],total[100],data_c[100],data_arr[100],gen_arr[100],gen[100],temp_r[100],rslt_full[100];\
    int8_t i,j,datalen,genlen,len;\
    data_dec = (uint8_t)generate_random_num(MAILBOX1);/*random number generation for data to be transmitted*/\
    gen_dec = (rand() % (15 - 9 + 1)) + 9;/*random number generation for genpoly between 9 to 15*/\
    uint8_t g_dummy = data_dec;\
    uint8_t q_dummy = gen_dec;\
    z_printf("Random Data to be transmitted in Decimal : %d\n",data_dec);\
    z_printf("Random Gen-poly in Decimal : %d\n",gen_dec);\
	i = 0;/*initializing i to 0*/\
	while (data_dec > 0) {/*while loop for conversion of decimal random number to binary for data*/\
		data_c[i] = data_dec % 2;\
		data_dec = data_dec / 2;\
		i++;\
	}\
    for (j = i - 1; j >= 0; j--)\
    {\
    z_printf("Data to be transmitted : %d\n", data_c[j]);\
    }\
    datalen = i;/*Length of binary data*/\
	i = 0;/*initializing i to 0*/\
	while (gen_dec > 0) {/*while loop for conversion of decimal random number to binary for gen-poly*/\
		gen[i] = gen_dec % 2;\
		gen_dec = gen_dec / 2;\
		i++;\
	}\
    genlen = i;/*Length of binary gen-poly*/\
	for ( j = i - 1; j >= 0; j--)\
    {\
    z_printf("Gen-poly : %d\n", gen[j]);\
    }\
    z_printf(" Data length is : %d\n",datalen);\
    z_printf(" Key length is : %d\n",genlen);\
	len=(datalen+genlen)-1;/*Total length --> Data+(genlen-1)*/\
    z_printf(" Total Data Length is : %d\n",len);\
    actual_result[(tn-1)*30 + 0] = g_dummy;\
    actual_result[(tn-1)*30 + 1] = q_dummy;\
    for(i=0;i<datalen;i++)                /*data_arr array*/\
    {\
        data_arr[(datalen-1)-i]=data_c[i];\
    }\
    for(i=1;i<genlen;i++)                /*gen_arr array*/\
    {\
        gen_arr[(genlen-1)-i]=gen[i];\
    }\
    for(i=datalen;i<len;i++)\
    {\
        data_arr[i]=0;\
    }\
    for(i=0;i<len;i++)\
    {\
        total[i]=data_arr[i];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp[j]=data_arr[j];\
    }\
    while(j<=len)\
	{\
        if(temp[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp[i] = (( temp[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp[i]=temp[i+1];\
        }\
        temp[i]=data_arr[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    data_arr[i]=temp[i-datalen];\
    }\
    for(i=0;i<len;i++)\
    {\
        z_printf("-------------------Transmitted Code Word:--------------%d\n", data_arr[i]);\
        actual_result[(tn-1)*30 + (i+2)] = data_arr[i];\
        rslt_full[j]=data_arr[j];\
    }\
    }\
    int  e = 1;\
    int  index;\
    z_printf("rand : %d\n",e);\
    for(j=0;j<e;j++)\
    {\
        index = 1;\
        z_printf("index : %d\n", index);\
        data_arr[index] =! data_arr[index];\
    }\
    for(j=0;j<len;j++)\
    {\
        z_printf("------------Received code word :-------------------- %d\n",data_arr[j]);\
        actual_result[(tn-1)*30 + (j+len+2)] = data_arr[j];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp_r[j]=total[j];\
    }\
    while(j<=len)\
	{\
        if(temp_r[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp_r[i] = (( temp_r[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp_r[i]=temp_r[i+1];\
        }\
        temp_r[i]=total[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    total[i]=temp_r[i-datalen];\
    }\
    int f=0;\
    flag=0;\
    while(f<len)\
    {\
        if(data_arr[f]==total[f])\
        {\
        f++;\
        }\
        else\
        {\
            flag=flag+1;\
            f++;\
        }\
    }\
    actual_result[(tn-1)*30 + 29] = flag;\
    if(flag == 0)\
	    z_printf("\n-----Successful!!-----\n");\
    else\
	    z_printf("\n-----Received code word contains %d errors...--------\n", flag);\
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    #define CRC_TEST_ERROR_SPIKE(data_dec_tb,gen_dec_tb,flag,flag_tb,len,rslt_tb,rslt_full,tn)\
    char temp[100],total[100],data_spike[100],data_arr[100],gen_arr[100],gen[100],temp_r[100],rslt_tb[100],rslt_full[100];\
    int8_t i,j,datalen,genlen,len;\
    data_dec_tb = (uint8_t)data[(tn-1)*30 + 0];\
    gen_dec_tb = (uint8_t)data[(tn-1)*30 + 1];\
    flag = (uint8_t)data[(tn-1)*30 + 29];\
    printf("Random Data to be transmitted in Decimal [%d] & Random Gen-poly in Decimal : [%d]\n",data_dec_tb,gen_dec_tb);\
    i = 0;/*initializing i to 0*/\
	while (data_dec_tb > 0) {/*while loop for conversion of decimal random number to binary for data_spike*/\
		data_spike[i] = data_dec_tb % 2;\
		data_dec_tb = data_dec_tb / 2;\
		i++;\
	}\
    datalen = i;/*Length of binary data_spike*/\
	i = 0;/*initializing i to 0*/\
	while (gen_dec_tb > 0) {/*while loop for conversion of decimal random number to binary for gen-poly*/\
		gen[i] = gen_dec_tb % 2;\
		gen_dec_tb = gen_dec_tb / 2;\
		i++;\
	}\
    genlen = i;/*Length of binary gen-poly*/\
	len=(datalen+genlen)-1;/*Total length --> Data+(genlen-1)*/\
    for(i=0;i<len;i++)\
    {\
        rslt_full[i]=(uint8_t)data[(tn-1)*30 + (i+len+2)];\
    }\
    for(i=0;i<datalen;i++)                /*data_arr array*/\
    {\
        data_arr[(datalen-1)-i]=data_spike[i];\
    }\
    for(i=1;i<genlen;i++)                /*gen_arr array*/\
    {\
        gen_arr[(genlen-1)-i]=gen[i];\
    }\
    for(i=datalen;i<len;i++)\
    {\
        data_arr[i]=0;\
    }\
    for(i=0;i<len;i++)\
    {\
        total[i]=data_arr[i];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp[j]=data_arr[j];\
    }\
    while(j<=len)\
	{\
        if(temp[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp[i] = (( temp[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp[i]=temp[i+1];\
        }\
        temp[i]=data_arr[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    data_arr[i]=temp[i-datalen];\
    }\
    }\
    int  e = 1;\
    int  index;\
    for(j=0;j<e;j++)\
    {\
        index = 1;\
        data_arr[index] =! data_arr[index];\
    }\
    for(j=0;j<len;j++)\
    {\
        rslt_tb[j]=(uint8_t)data[(tn-1)*30 + (j+len+2)];\
    }\
    if((gen_arr[0]= 1) && (gen_arr[3]=1))\
    {\
	for(j=0;j<genlen;j++)\
    {\
        temp_r[j]=total[j];\
    }\
    while(j<=len)\
	{\
        if(temp_r[0]==1)\
        {\
            for(i = 1;i <genlen ; i++)\
            {\
            temp_r[i] = (( temp_r[i] == gen_arr[i])?0:1);\
            }\
        }\
        for(i=0;i<genlen-1;i++)\
        {\
        temp_r[i]=temp_r[i+1];\
        }\
        temp_r[i]=total[j++];\
     }\
 	for(i=datalen;i<len;i++)\
    {\
    total[i]=temp_r[i-datalen];\
    }\
    int f=0;\
    flag_tb=0;\
    while(f<len)\
    {\
        if(data_arr[f]==total[f])\
        {\
        f++;\
        }\
        else\
        {\
            flag_tb=flag_tb+1;\
            f++;\
        }\
    }\
    }\

