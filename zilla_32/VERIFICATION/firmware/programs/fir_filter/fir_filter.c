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
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "data.h"               /*!< Testbench created data */


#include "waveform.h" 
#include "filters.h"

extern  long int InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern  long int  Impulse_response[IMP_RSP_LENGTH];
extern  long int  Output_signal[SIG_LENGTH-IMP_RSP_LENGTH];
extern int i;

 int main(void)
{
           
      
 z_printf("Sinc and Window function \n");   

 for(i=0;i<IMP_RSP_LENGTH;i++)
 {
     if(i-IMP_RSP_LENGTH/2==0)
     {
         Impulse_response[i]= qformat_multiplication(TWO_PI,CUT_OFF_FREQ);
     }
     if(i-IMP_RSP_LENGTH/2!=0)
     {
         Impulse_response[i] =  sinc_function(i,TWO_PI,CUT_OFF_FREQ,IMP_RSP_LENGTH);

         //Window function 
         
          Impulse_response[i] = Hamming_window(i,TWO_PI,CUT_OFF_FREQ,IMP_RSP_LENGTH);

          //Impulse_response[i] = Hanning_window(i,TWO_PI,CUT_OFF_FREQ,IMP_RSP_LENGTH);

          //Impulse_response[i] = blackman_window(i,TWO_PI,CUT_OFF_FREQ,IMP_RSP_LENGTH);

        
      }
 }

 z_printf("Convolution \n");
 
 convolution(IMP_RSP_LENGTH,SIG_LENGTH);

 
  for(i=IMP_RSP_LENGTH;i<SIG_LENGTH;i++)
     {

         z_printf("Output signal in %d is %d \n",i,Output_signal[i]);
     }
 

    mailbox_send_request(MAILBOX1, MEM_DUMP);
    mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt);   
    return 0;
}


