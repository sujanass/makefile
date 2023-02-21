//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* File Name : spc_assertion.sv

* Purpose : Assertion cheking 

* Creation Date : 02-04-2023

* Last Modified : Wed 12 Apr 2023 03:45:12 PM IST

* Created By :  Sharon
*/

//use implication and check count is ZERO
property p1;
        @(posedge clock) reset |-> (!count);
endproperty

property p2;
        @(posedge clock) reset_overflow |-> !overflow;
endproperty

property p3;
        @(posedge clock) $rose(reset);
endproperty


