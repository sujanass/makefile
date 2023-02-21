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
** Prints mail box messages to pre-defined location in RAM
**
*******************************************************************************
*/

#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Linker symbols library */

/* Main function */
int main(int argc, char *argv[])
{
	/* test case status */
	static volatile unsigned char status = 0;    

	
	/************************************** Testing z_printf ************************************/

	/* Write message (formatted string) to print mailbox using z_printf function */
        int      d = -23;                     /* Integer */
        uint64_t x = 0xF463899923457890;      /* Hex number */
        char     c = 'T';                     /* Character */
        char   s[] = "StringToSend";          /* String */
        int      o = 076;                     /* Octal number */
        z_printf("Hello world from Zilla!!!!! - int=%d: char=%c : hex=0x%x : string=%s : oct=%o\n", d,c,x,s,o);

#ifdef SPIKE_RUN
        /* Read mailbox message */
        printf("Test/> Message read from print mailbox after z_printf call:\n--------------------------------\n");
        for(int i = 0; i < &__mailbox_print_len__; i++)
        {
	    printf("%c", MAILBOX->PRINT_MAILBOX_MSG[i]);
        }
        printf("\n--------------------------------\n");
#endif

	/************************************** End of z_printf test************************************/

	/************************************** Testing print_str ************************************/

	/* Write a message to print mailbox using print_str function */
        print_str("This message is pushed onto print mailbox using print_str function\n");

#ifdef SPIKE_RUN
        /* Read mailbox message to verify if the print_str function worked */
        printf("Test/> Message read from print mailbox after print_str call:\n--------------------------------\n");
        for(int i = 0; i < &__mailbox_print_len__; i++)
        {
	    printf("%c", MAILBOX->PRINT_MAILBOX_MSG[i]);
        }
        printf("\n--------------------------------\n");
#endif

	/************************************** End of print_str test************************************/

	// ********************** SENDING REQUEST TO TB FROM MB1 ASKING TO GENERATE RANDOM NUMBER  *********************//
	mailbox_send_request(MAILBOX1, REQ_RAND);   /* Send request and set flag */

#ifdef SPIKE_RUN
	printf("Test/> Requested TB to generate a random number and place the random number in same address.\n");
#endif

	/* Set mailbox flag */    
	mailbox_set_flag(MAILBOX1);

#ifdef SPIKE_RUN
	printf("Test/> MAILBOX1 FLAG = %lX\n", mailbox_read_flag(MAILBOX1));
#endif

	
#ifndef SPIKE_RUN
	/* Wait until mailbox flag is unset */
	wait_until_flag_unset(MAILBOX1);

    z_printf("The Random Number generated by TB is : %X\n", mailbox_read_value(MAILBOX1));
        
#endif

	// ********************** SENDING REQUEST TO TB FROM MB2 ASKING TO GENERATE RANDOM NUMBER  *********************//
	mailbox_send_request(MAILBOX2, REQ_RAND);

#ifdef SPIKE_RUN
	printf("Test/> Requested TB to generate a random number and place the random number in same address.\n");
#endif

	/* Set mailbox flag */    
	mailbox_set_flag(MAILBOX2);

#ifdef SPIKE_RUN
	printf("Test/> MAILBOX2 FLAG = %lX\n", mailbox_read_flag(MAILBOX2));
#endif

	
#ifndef SPIKE_RUN
	/* Wait until mailbox flag is unset */
	wait_until_flag_unset(MAILBOX2);
    z_printf("The Random Number generated by TB is : %X\n", mailbox_read_value(MAILBOX2));
    
#endif

	// ********************** SENDING REQUEST TO TB FROM MB1 ASKING TO END SIMULATION  *********************//
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
    
	return status;
}


