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
/*
**
*******************************************************************************
**
** Multiple data access (byte) test program
**
** Pass src and dest pointers and then the custom_lib function will add first two
** bytes and store sum in dest and also return the sum.
*******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */

//#ifndef LEN
#define LEN    2
#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Declare extern function */
extern uint32_t _MULTI_B_READ_(uint8_t *, uint8_t *, uint32_t);

int main(int argc, char *argv[])
{
	static volatile unsigned int status = 0;    /* test case status */
	uint8_t source[LEN];
        uint8_t dest  [LEN];

        /* Pre-fill source and dest */
	for (int i = 0; i < LEN; i++)
	{
		source[i] = 0x10 + i;
                dest  [i] = 0;
	}

	/* Call custom library function.
           Note: The function gets 2 bytes from source and adds it and store into dest*/
	uint32_t return_val = _MULTI_B_READ_(source, dest, LEN);	

#ifdef SPIKE_RUN
	printf("test: SRC Address            = 0x%p\n", (void *) source);
	printf("test: DST Address            = 0x%p\n", (void *) dest);
	printf("test: _MULTI_B_READ_ ret val = 0x%X\n", return_val);
	printf("test: sum stored in dest val = 0x%X\n", dest[0]);
#endif

	if (( return_val == 0x21 ) && ( dest[0] == 0x21 ))
	{
		status = 0;
#ifdef SPIKE_RUN
	        printf("\ntest: STATUS = PASS\n");
#endif
	}
	else
	{
		status = 1;
#ifdef SPIKE_RUN
		printf("\ntest: STATUS = FAILED !!!\n");
#endif
	}
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);

	return status;
}
