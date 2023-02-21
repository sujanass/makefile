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

#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Linker symbols library */
#include "trapapi.h"  /* Linker symbols library */
#include "irq_api.h"


extern volatile int irq_asserted  ;
extern int irq_remap_flag;

int main()
{

 int r0;
 csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests
 irq_remap_flag = 1 ;  // set irq_remap flag high to perform remapping of functions
 irq_remap_default();  // default remapping ( remaps to and_op)

// Re-maping of all 48 interrupts in assending order

irq_remap(0 ,sub_op , "Subtraction operation") ;
irq_remap(1 ,or_op , "OR operation") ;
irq_remap(2 ,cgte_op , "Compare greater than  equal to operation") ;
irq_remap(3 ,rem_op , "Remainder operation") ;
irq_remap(4 ,srl_op , "Logical shift right operation") ;
irq_remap(5 ,clt_op , "Compare less than operation") ;
irq_remap(6 ,bubble_sort , "Bubble sort algorithm") ;
irq_remap(7 ,xor_op , "XOR operation") ;
irq_remap(8 ,add_op , "ADD operation") ;
irq_remap(9 ,insertion_sort , "Insertion sort") ;
irq_remap(10 ,sqrt_op , "Square root") ;
irq_remap(11 ,div_op , "Division operation") ;
irq_remap(12 ,cneq_op , "Compare not equal to operation") ;
irq_remap(13 ,sll_op , "logical shift left operation") ;
irq_remap(14 ,shell_sort , "Shell sort algorithm ") ;
irq_remap(15 ,cgt_op , "Comapre greater than operation");
irq_remap(17 ,gnome_sort , "Gnome sort algorithm") ;
irq_remap(18 ,mul_op , "Multiplication operation") ;
irq_remap(19 ,clte_op , "Compare less than equal to operation") ;
irq_remap(20 ,ceq_op , "Compare equal to operation") ;
irq_remap(21 ,selection_sort , "Selection sort algorithm ") ;
irq_remap(22 ,clt_op , "Compare less than operation") ;
irq_remap(23 ,div_op , "Division operation") ;
irq_remap(24 ,sub_op , "Subtraction operation") ;
irq_remap(25 ,or_op , "OR operation") ;
irq_remap(26 ,selection_sort , "Selection sort algorithm") ;
irq_remap(28 ,sll_op , "Logical shift left operation") ;
irq_remap(29 ,srl_op , "Logical shift right operation") ;
irq_remap(30 ,add_op , "Addition operation") ;
irq_remap(31 ,gnome_sort , "Gnome sort algorithm") ;
irq_remap(32 ,clte_op , "Compare less than equal to operation") ;
irq_remap(33 ,cneq_op , "Compare not equal to  operation") ;
irq_remap(34 ,bubble_sort , "Bubble sort algorithm") ;
irq_remap(35 ,mul_op , "Multiplication operation") ;
irq_remap(36 ,rem_op , "Remainder operation") ;
irq_remap(37 ,ceq_op , "Compare equal to operation") ;
irq_remap(38 ,shell_sort , "Shell sort") ;
irq_remap(39 ,cgt_op , "Compare greater than operation") ;
irq_remap(40 ,xor_op , "XOR operation") ;
irq_remap(41 ,insertion_sort , "Insertion sort algorithm") ;
irq_remap(42 ,cgte_op , "Compare greater than equal to operation") ;
irq_remap(43 ,sqrt_op , "Square root") ;
irq_remap(44 ,add_op , "Addition operation") ;
irq_remap(45 ,ceq_op , "Compare equal to operation") ;
irq_remap(46 ,or_op , "OR operation") ;

INT_ASCENDING; //generating all 48 interrupts in asscending order


irq_remap(46 ,xor_op , "XOR operation") ;
irq_remap(45 ,cgte_op , "Compare greater than  equal to operation") ;
irq_remap(44 ,rem_op , "Remainder operation") ;
irq_remap(43 ,srl_op , "Logical shift right operation") ;
irq_remap(42 ,clt_op , "Compare less than operation") ;
irq_remap(41 ,bubble_sort , "Bubble sort algorithm") ;
irq_remap(39 ,xor_op , "XOR operation") ;
irq_remap(38 ,add_op , "ADD operation") ;
irq_remap(37 ,insertion_sort , "Insertion sort") ;
irq_remap(36 ,sqrt_op , "Square root") ;
irq_remap(35 ,div_op , "Division operation") ;
irq_remap(34 ,cneq_op , "Compare not equal to operation") ;
irq_remap(33 ,sll_op , "logical shift left operation") ;
irq_remap(32 ,shell_sort , "Shell sort algorithm ") ;
irq_remap(31 ,cgt_op , "Comapre greater than operation");
irq_remap(30 ,gnome_sort , "Gnome sort algorithm") ;
irq_remap(29 ,mul_op , "Multiplication operation") ;
irq_remap(28 ,clte_op , "Compare less than equal to operation") ;
irq_remap(27 ,ceq_op , "Compare equal to operation") ;
irq_remap(26 ,insertion_sort , "Insertion sort algorithm ") ;
irq_remap(25 ,clt_op , "Compare less than operation") ;
irq_remap(24 ,div_op , "Division operation") ;
irq_remap(23 ,sub_op , "Subtraction operation") ;
irq_remap(22 ,or_op , "OR operation") ;
irq_remap(21 ,div_op , "Division operation") ;
irq_remap(20 ,sll_op , "Logical shift left operation") ;
irq_remap(19 ,srl_op , "Logical shift right operation") ;
irq_remap(18 ,add_op , "Addition operation") ;
irq_remap(17 ,or_op , "OR operation") ;
irq_remap(16 ,clte_op , "Compare less than equal to operation") ;
irq_remap(15 ,cneq_op , "Compare not equal to  operation") ;
irq_remap(14 ,bubble_sort , "Bubble sort algorithm") ;
irq_remap(13 ,mul_op , "Multiplication operation") ;
irq_remap(12 ,rem_op , "Remainder operation") ;
irq_remap(11 ,ceq_op , "Compare equal to operation") ;
irq_remap(10 ,shell_sort , "Shell sort") ;
irq_remap(8 ,cgt_op , "Compare greater than operation") ;
irq_remap(7 ,shell_sort ,"Shell sort algorithm") ;
irq_remap(6 ,insertion_sort , "Insertion sort algorithm") ;
irq_remap(5 ,cgte_op , "Compare greater than equal to operation") ;
irq_remap(4 ,sqrt_op , "Square root") ;
irq_remap(3 ,add_op , "Addition operation") ;
irq_remap(2 ,ceq_op , "Compare equal to operation") ;
irq_remap(1 ,clte_op , "Comapre less than equal to operation") ;
irq_remap(0 ,bubble_sort , "Bubble sort algorithm") ;

INT_DESCENDING; //generating all 48 interrupts in descending order


irq_remap( 14 , mul_op ,"Multiplication operation") ;
irq_remap( 3 , rem_op, "Remainder operation") ;
irq_remap( 8 , cgte_op ,"Compare greater than or equal operation ") ;
irq_remap( 16 , mul_op , "Multiplication operation") ;
irq_remap( 27 , sll_op , "Shift Logical Left operation" ) ;
irq_remap( 32 , cneq_op , "Compare not Equal to operation " ) ;
irq_remap( 45 , rem_op , "Remainder Operation") ;
irq_remap( 11 , xor_op, "XOR operation ") ;
irq_remap( 13 , sub_op, "Subraction Operation") ;
irq_remap( 25 , bubble_sort, "bubble sort algorithm") ;
irq_remap( 33 , clte_op , "compare less than or equal to operation") ;
irq_remap( 41 , gnome_sort , "gnome sort algorithm") ;
irq_remap(1 ,sub_op , "Subtraction operation") ;
irq_remap( 19 , div_op , "division operation" ) ;
irq_remap( 38 , srl_op, "logical shift right opeartion " ) ;
irq_remap( 21 , cgt_op, "Compare greater than operation") ;
irq_remap( 44 , ceq_op, "Compare Equal to operation") ;
irq_remap( 17 , cgt_op, "compare greater than operation") ;
irq_remap( 9 , add_op, "Add operation") ;
irq_remap( 15 , clt_op ,"compare less than operation") ;
irq_remap( 28 , sqrt_op, "Square Root operation") ;
irq_remap( 46 , shell_sort , "Shell Sort algorithm") ;
irq_remap(31 ,srl_op , "Logical shift right operation") ;
irq_remap( 36 , clt_op ,"compare less than operation") ;
irq_remap( 4 , bubble_sort , "Bubble Sort algorithm") ;
irq_remap( 0 , add_op, "Add operation") ;
irq_remap( 29 , cneq_op , "Compare not Equal to operation " ) ;
irq_remap( 42 , sll_op , "Shift Logical Left operation" ) ;
irq_remap( 12 , sqrt_op, "Square Root operation") ;
irq_remap( 30 , cneq_op , "Compare not Equal to operation " ) ;
irq_remap( 35 , insertion_sort , "Insertion Sort algorithm") ;
irq_remap( 5 , add_op, "Division operation") ;
irq_remap(7 ,srl_op , "Logical shift right operation") ;
irq_remap( 40 , cgte_op, "Compare greater than equal to operation") ;
irq_remap( 37 , sqrt_op, "Square Root operation") ;
irq_remap( 34 , sll_op , "Shift Logical Left operation" ) ;
irq_remap( 6 , add_op, "MUltiplication operation") ;
irq_remap( 18 , clte_op ,"compare less than or equal to operation") ;
irq_remap( 43 , selection_sort , "Selection Sort algorithm") ;
irq_remap( 22 , cgt_op, "Compare greater than operation") ;
irq_remap( 26 , cgt_op, "Compare greater than operation") ;
irq_remap( 10 , sub_op, "Subtraction operation") ;
irq_remap( 2 , gnome_sort , "Gnome Sort algorithm") ;
irq_remap( 24 , xor_op, "XOR operation ") ;



//Generating all the randomly remapped functions

 GEN_INT(IRQ_GEN_1);
 GEN_INT(IRQ_GEN_14);
 GEN_INT(IRQ_GEN_3);
 GEN_INT(IRQ_GEN_8);
 GEN_INT(IRQ_GEN_16);
 GEN_INT(IRQ_GEN_27);
 GEN_INT(IRQ_GEN_32);
 GEN_INT(IRQ_GEN_45);
 GEN_INT(IRQ_GEN_11);
 GEN_INT(IRQ_GEN_13);
 GEN_INT(IRQ_GEN_25);
 GEN_INT(IRQ_GEN_33);
 GEN_INT(IRQ_GEN_41);
 GEN_INT(IRQ_GEN_19);
 GEN_INT(IRQ_GEN_38);
 GEN_INT(IRQ_GEN_21);
 GEN_INT(IRQ_GEN_44);
 GEN_INT(IRQ_GEN_39);
 GEN_INT(IRQ_GEN_17);
 GEN_INT(IRQ_GEN_9);
 GEN_INT(IRQ_GEN_15);
 GEN_INT(IRQ_GEN_28);
 GEN_INT(IRQ_GEN_46);
 GEN_INT(IRQ_GEN_31);
 GEN_INT(IRQ_GEN_20);
 GEN_INT(IRQ_GEN_36);
 GEN_INT(IRQ_GEN_4);
 GEN_INT(IRQ_GEN_0);
 GEN_INT(IRQ_GEN_29);
 GEN_INT(IRQ_GEN_42);
 GEN_INT(IRQ_GEN_12);
 GEN_INT(IRQ_GEN_30);
 GEN_INT(IRQ_GEN_35);
 GEN_INT(IRQ_GEN_5);
 GEN_INT(IRQ_GEN_39);
 GEN_INT(IRQ_GEN_7);
 GEN_INT(IRQ_GEN_40);
 GEN_INT(IRQ_GEN_37);
 GEN_INT(IRQ_GEN_6);
 GEN_INT(IRQ_GEN_18);
 GEN_INT(IRQ_GEN_23);
 GEN_INT(IRQ_GEN_43);
 GEN_INT(IRQ_GEN_22);
 GEN_INT(IRQ_GEN_26);
 GEN_INT(IRQ_GEN_10);
 GEN_INT(IRQ_GEN_2);
 GEN_INT(IRQ_GEN_24);


  mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
  mailbox_send_request(MAILBOX2, error_cnt); 
   return 0;
}







