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
#include <stdio.h>              /*!< Standard IO            */
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "wdt.h"  
#include "trapapi.h"


 extern volatile int irq_asserted  ;
 extern value;
  int r0;



//******  STATRT OF MAIN() FUNCTION   *************
int main ()

{ 
    
  csr_asm_rs(csrrsi,r0,768,8);

 
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();
  test_case_6();
  test_case_7();
  test_case_8();
  test_case_9();
  test_case_10();
  test_case_11();
  test_case_12();
  /*test_case_13();
  test_case_14();
  test_case_15();
  test_case_16();
  test_case_17();
  test_case_18();
  test_case_19();
  test_case_20();
  test_case_21();
  test_case_22();
  test_case_23();
  test_case_24();
  test_case_25();
  test_case_26();
  test_case_27(); 
*/
 // test_case_28();
 
 
  mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
  mailbox_send_request(MAILBOX2, error_cnt); 
   return 0;
}



