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
** Header file for including linker script symbols in test programs.
**
** You need to include this header file in your test program if you are
** accessing linker symbols.
**
** Usage : #include "linker.h"
*******************************************************************************
*/

#ifndef LINKER_H
#define LINKER_H

	/* Declare linker symbols (use only that are required) */

	/* Mailbox related linker symbols */
	extern uint32_t          __mailbox1__;
	extern uint32_t      __mailbox1_len__;
	extern uint32_t          __mailbox2__;
	extern uint32_t      __mailbox2_len__;
	extern uint32_t     __mailbox_print__;
	extern uint32_t __mailbox_print_len__;
	extern uint32_t     __mailbox1_flag__;
	extern uint32_t __mailbox1_flag_len__;
	extern uint32_t     __mailbox2_flag__;
	extern uint32_t __mailbox2_flag_len__;

	/* Other linker symbols */
	extern uint32_t __boot_address;
	extern uint32_t __data_address;
	extern uint32_t __etext;
	extern uint32_t __DATA_BEGIN__;
	extern uint32_t __SDATA_BEGIN__;
	extern uint32_t _edata;
	extern uint32_t _start_bss ;
	extern uint32_t _end_bss ;
	extern uint32_t __heap_start;   
	extern uint32_t __heap_end;
	extern uint32_t __stack_start;
	extern uint32_t _end_stack;
    extern uint32_t _start_data ; 
#endif /* LINKER_H */

