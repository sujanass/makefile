//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright Â© 2022 Vivartan Technologies., All rights reserved/////////////////////////////
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
/*
Copyright © 2021 Vivartan Technologies., All rights reserved.

All works published under Zilla_Gen_0 by the Vivartan Technologies. 
is copyrighted by the Association and ownership of all right, title and interest
in and to the works remains with Vivartan Technologies.

No works or documents published under Zilla_Gen_0 by Vivartan Technologies. may be reproduced,
transmitted or copied without the express written permission of Vivartan Technologies.
will be considered as a violations of Copyright Act and it may lead to legal action.
*/

/*
**
*******************************************************************************
**
** This program displays the symbols from linker script
**
** Purpose of this is to debug the section allocation by linker script
*******************************************************************************
*/

#include <stdio.h>   /* Standard IO            */
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
//#include "linker.h"  /* Linker symbols library */

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

int main(int argc, char *argv[])
{
	static volatile unsigned int status = 0;    /* test case status */

        /* Note: Linker Symbols are just like variables, But they do NOT behave same.
           Case 1: C variable : e.g. int x = Y; The variable "x" has name "x", adderss "&x" and value "Y"
           Case 2: Linker symbol : A linker symbol "x" is an address and that address contains the value "Y".
                   e.g. __vector_start is an address and we are worried only about its value which can be
                   obtained by dereferencing the address location. */
#ifdef SPIKE_RUN
	printf("__boot_address        = 0x%X\n",(uint32_t)&__boot_address);
	printf("__etext               = 0x%X\n",(uint32_t)&__etext);
	printf("__data_address        = 0x%X\n",(uint32_t)&__data_address);
	printf("__DATA_BEGIN__        = 0x%X\n",(uint32_t)&_start_data);
	printf("__SDATA_BEGIN__       = 0x%X\n",(uint32_t)&__SDATA_BEGIN__);
	printf("__edata               = 0x%X\n",(uint32_t)&_edata);
	printf("__bss_start           = 0x%X\n",(uint32_t)&_start_bss);
	printf("__bss_end             = 0x%X\n",(uint32_t)&_end_bss);
	printf("__heap_start          = 0x%X\n",(uint32_t)&__heap_start);
	printf("__heap_end            = 0x%X\n",(uint32_t)&__heap_end);
	printf("__stack_start         = 0x%X\n",(uint32_t)&__stack_start);
	printf("__stack_end           = 0x%X\n",(uint32_t)&_end_stack);
#endif
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return status;
}
