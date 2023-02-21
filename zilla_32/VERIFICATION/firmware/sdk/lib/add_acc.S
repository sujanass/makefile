############################################################################################################
########  This is the library for providing assembly level functions used by various test applications. ####
########                                   Addition                                                     ####
############################################################################################################

.global _ADD_TEST_S8_
.global _ADD_TEST_U8_
.global _ADD_TEST_S16_
.global _ADD_TEST_U16_
.global _ADD_TEST_U32_
.global _ADD_TEST_S32_
.global _ADD_TEST_U8U16_
.global _ADD_TEST_U8U32_
.global _ADD_TEST_U8S8_
.global _ADD_TEST_U8S16_
.global _ADD_TEST_U8S32_
.global _ADD_TEST_U16U32_
.global _ADD_TEST_U16S8_
.global _ADD_TEST_U16S16_
.global _ADD_TEST_U16S32_
.global _ADD_TEST_U32S8_
.global _ADD_TEST_U32S16_
.global _ADD_TEST_U32S32_
.global _ADD_TEST_S8S16_
.global _ADD_TEST_S8S32_
.global _ADD_TEST_S16S32_


##############################################
######    Add Immediate ADDI  ################
##############################################

.global _ADD_TEST_I_U8_ 
.global _ADD_TEST_I_S8_ 
.global _ADD_TEST_I_U16_ 
.global _ADD_TEST_I_S16_ 
.global _ADD_TEST_I_U32_ 
.global _ADD_TEST_I_S32_ 


##############################################
######   RISCV Compliance     ################
##############################################
.global _ADD_TEST_U8SRC1_EQ_DEST_
.global _ADD_TEST_U8SRC2_EQ_DEST_
.global _ADD_TEST_U8SRC12_EQ_DEST_
.global _ADD_TEST_U8ZEROSRC1_
.global _ADD_TEST_U8ZEROSRC2_
.global _ADD_TEST_U8ZEROSRC12_
.global _ADD_TEST_U8ZERODEST_
.global _ADD_TEST_U8DEST_BYPASS_
.global _ADD_TEST_U8SRC12_BYPASS_
.global _ADD_TEST_U8SRC21_BYPASS_



#define TEST_INSERT_NOPS_0
#define TEST_INSERT_NOPS_1  nop; TEST_INSERT_NOPS_0
#define TEST_INSERT_NOPS_2  nop; TEST_INSERT_NOPS_1
#define TEST_INSERT_NOPS_3  nop; TEST_INSERT_NOPS_2
#define TEST_INSERT_NOPS_4  nop; TEST_INSERT_NOPS_3
#define TEST_INSERT_NOPS_5  nop; TEST_INSERT_NOPS_4
#define TEST_INSERT_NOPS_6  nop; TEST_INSERT_NOPS_5
#define TEST_INSERT_NOPS_7  nop; TEST_INSERT_NOPS_6
#define TEST_INSERT_NOPS_8  nop; TEST_INSERT_NOPS_7
#define TEST_INSERT_NOPS_9  nop; TEST_INSERT_NOPS_8
#define TEST_INSERT_NOPS_10 nop; TEST_INSERT_NOPS_9

###################### Addition ###############################
####################### Part 2 ################################

_ADD_TEST_S8_: 				# int8_t Addition
	lb	a5, 0(a0)		# Load byte (signed) into a5 from the address strored at a0 (op1)
        slliw	a6,a5,0x10 		# Logical Shift-left a5 (op1) by 0x10 or 16 and store into a6
   	sraiw	a6,a6,0x10		# Arithmentic shift-right a6 by 0x10 or 16 and store into a6 
	lb	a5,0(a1)  		# Load byte (signed) into a5 from the address strored at a1 (op2)     
        slliw	a5,a5,0x10		# Logical Shift-left a5 (op21) by 0x10 or 16 and store into a5 
        sraiw	a5,a5,0x10		# Arithmentic shif-right a5 by 0x10 or 16 and store into a5 
   	addw	a5,a6,a5   		# Add using ADDW and store result into a5
        sh	a5,0(a2)   		# The half-word result stored back to variable    
	add     a0, x0, a5 		# Set the return value    
	jr      ra                      # return       

_ADD_TEST_U8_:                          # uint8_t Addition                                                        
	lbu	a5, 0(a0)               # Load byte (signed) into a5 from the address strored at a0 (op1)
   	slli	a6,a5,0x30              # Logical Shift-left a5 (op1) by 0x30 or 48 and store into a6
        srai	a6,a6,0x30              # Arithmentic shift-right a6 by 0x30 or 48 and store into a6 
        lbu     a5,0(a1)                # Load byte (signed) into a5 from the address strored at a1 (op2)     
        slli	a5,a5,0x30              # Logical Shift-left a5 (op21) by 0x30 or 48 and store into a5 
        srai	a5,a5,0x30              # Arithmentic shif-right a5 by 0x30 or 48 and store into a5 
        addw	a5,a6,a5                # Add using ADDW and store result into a5
        sh	a5,0(a2)                # The half-word result stored back to variable    
	add     a0, x0, a5              # Set the return value    
	jr      ra                      # return                                                                                   
	
	
_ADD_TEST_U16_:                         # uint16_t Addition                                                   
	lhu	a5, 0(a0)               # Load byte (signed) into a5 from the address strored at a0 (op1)      
        slli	a6,a5,0x10              # Logical Shift-left a5 (op1) by 0x10 or 16 and store into a6         
        srai	a6,a6,0x10              # Arithmentic shift-right a6 by 0x10 or 16 and store into a6          
        lhu	a5,0(a1)                # Load byte (signed) into a5 from the address strored at a1 (op2)     
        slli	a5,a5,0x10              # Logical Shift-left a5 (op21) by 0x10 or 16 and store into a5        
        srai	a5,a5,0x10              # Arithmentic shif-right a5 by 0x10 or 16 and store into a5           
        addw	a5,a6,a5                # Add using ADDW and store result into a5                             
        sw	a5,0(a2)                # The half-word result stored back to variable                        
	add     a0, x0, a5              # Set the return value                                                
	jr      ra                      # return                                                              
	                        
_ADD_TEST_S16_:
	lh	a5, 0(a0)           
        slli	a6,a5,0x10  
        srai	a6,a6,0x10  
        lh	a5,0(a1)        
        slli	a5,a5,0x10  
        srai	a5,a5,0x10  
        addw	a5,a6,a5    
        sw	a5,0(a2)        
	add     a0, x0, a5      
	jr      ra         
	
_ADD_TEST_U32_:
	lwu	a5,0(a0)      
	lwu	a6,0(a1)      
	add	a5,a6,a5      
        sd	a5,0(a2)  
	add     a0, x0, a5
	jr      ra       
	
_ADD_TEST_S32_:
	lw      a5,0(a0)      
        lw	a6,0(a1)  
	add	a5,a6,a5      
        sd	a5,0(a2)  
	add     a0, x0, a5
	jr      ra        
	
	
###################################### Part 4 ##########################################

_ADD_TEST_U8U16_:
	lbu	a5, 0(a0)              
        slli	a6,a5,0x30             
        srai	a6,a6,0x30    
 	lhu	a5,0(a1)               
        slli	a5,a5,0x10            
        srai	a5,a5,0x10 
	addw	a5,a6,a5               
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra   

_ADD_TEST_U8U32_:
	lbu	a5, 0(a0)              
        slli	a6,a5,0x30             
        srai	a6,a6,0x30    
 	lwu	a5,0(a1)               
	add	a5,a6,a5               
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra   

_ADD_TEST_U8S8_:
	lbu	a5, 0(a0)              
        slliw	a6,a5,0x10             
        sraiw	a6,a6,0x10    
 	lb	a5,0(a1)               
        slliw	a5,a5,0x10            
        sraiw	a5,a5,0x10 
	addw	a5,a6,a5               
        sh	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_U8S16_:

	lbu	a5, 0(a0)              
        slli	a6,a5,0x30             
        srai	a6,a6,0x30 
	lh	a5,0(a1)               
        slli	a5,a5,0x10             
        srai	a5,a5,0x10 	
	addw	a5,a6,a5              
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_U8S32_:

	lbu	a5, 0(a0)              
        slli	a6,a5,0x30             
        srai	a6,a6,0x30 
	lw	a5,0(a1) 	
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_U16U32_:

	lhu	a5, 0(a0)              
        slli	a6,a5,0x10             
        srai	a6,a6,0x10 
	lwu	a5,0(a1) 	
	add	a5,a6,a5              
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_U16S8_:

	lhu	a5, 0(a0)              
        slli	a6,a5,0x10             
        srai	a6,a6,0x10 
	lb	a5,0(a1)               
	addw	a5,a6,a5              
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_U16S16_:

	lhu	a5, 0(a0)              
        slli	a6,a5,0x10             
        srai	a6,a6,0x10 
	lh	a5,0(a1)               
        slli	a5,a5,0x10             
        srai	a5,a5,0x10 	
	addw	a5,a6,a5              
        sw	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_U16S32_:

	lhu	a5, 0(a0)              
        slli	a6,a5,0x10             
        srai	a6,a6,0x10 
	lw	a5,0(a1) 	
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_U32S8_:
	lwu	a6,0(a0)
	lb	a5,0(a1)  
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_U32S16_:
	lwu	a6,0(a0)
	lh	a5,0(a1)               
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_U32S32_:
	lwu	a6,0(a0)
	lw	a5,0(a1) 
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_S8S16_:
	lb	a5,0(a0)
        slliw	a6,a5,0x18             
        sraiw	a6,a6,0x18    
	lh	a5,0(a1)
        slliw	a5,a5,0x10             
        sraiw	a5,a5,0x10     
	addw	a5,a6,a5              
    	sh	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 


_ADD_TEST_S8S32_:
	lb	a6,0(a0)  
	lw	a5,0(a1)   
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra 

_ADD_TEST_S16S32_:
	lh	a6,0(a0)  
	lw	a5,0(a1)   
	add	a5,a6,a5              
        sd	a5,0(a2)               
	add     a0, x0, a5             
	jr      ra


///////////////// part 5  //////////////////////////////
/////////       Compliance        //////////////////////
///////////////////////////////////////////////////////

_ADD_TEST_U8SRC1_EQ_DEST_:


	lbu	a5, 0(a0)             
        lbu	a6,0(a1)          
        addw	a5,a6,a5      
	sh	a5,0(a2)              
	add     a0, x0, a5        
	jr      ra                


_ADD_TEST_U8SRC2_EQ_DEST_:


	lbu	a5, 0(a0)             
        lbu	a6,0(a1)          
        addw	a6,a6,a5      
	sh	a6,0(a2)              
	add     a0, x0, a6        
	jr      ra                

_ADD_TEST_U8SRC12_EQ_DEST_:


	lbu	a5, 0(a0)             
        addw	a5,a5,a5      
	sh	a5,0(a1)              
	add     a0, x0, a5        
	jr      ra                


_ADD_TEST_U8ZEROSRC1_:

	lbu	a5, 0(a0)             
        addw	a5,x0,a5      
	sh	a5,0(a1)              
	add     a0, x0, a5        
	jr      ra                


_ADD_TEST_U8ZEROSRC2_:

	lbu	a5, 0(a0)             
        addw	a5,a5,x0      
	sh	a5,0(a1)              
	add     a0, x0, a5        
	jr      ra                


_ADD_TEST_U8ZEROSRC12_:

        addw	a5,x0,x0      
	sh	a5,0(a0)              
	add     a0, a5, x0        
	jr      ra                


_ADD_TEST_U8ZERODEST_:

	lbu	a5, 0(a0)             
        lbu	a6,0(a1)          
        addw	x0,a6,a5      
	sh	x0,0(a2)              
	add     a0, x0, x0        
	jr      ra                


_ADD_TEST_U8DEST_BYPASS_:

		li	x4,0		      
	1:	lbu	a5, 0(a0)         
        	lbu	a6,0(a1)      
        	addw	a7,a6,a5  
		TEST_INSERT_NOPS_2    
		sh	a7,0(a2)          
		addi	x4,x4,1		  
		li	x5,2		      
		bne 	x4, x5, 1b	  
		add     a0, x0, a7    
		jr      ra            



_ADD_TEST_U8SRC12_BYPASS_:


		li	x4,0		      
	1:	lbu	a5, 0(a0)         
		TEST_INSERT_NOPS_1    
        	lbu	a6,0(a1)      
		TEST_INSERT_NOPS_2    
        	addw	a7,a5,a6  
		sh	a7,0(a2)          
		addi	x4,x4,1		  
		li	x5,2		      
		bne 	x4, x5, 1b	  
		add     a0, x0, a7    
		jr      ra            



_ADD_TEST_U8SRC21_BYPASS_:


		li	x4,0			
        1:	lbu	a6,0(a1)      
		TEST_INSERT_NOPS_2    
		lbu	a5, 0(a0)         
		TEST_INSERT_NOPS_1    
        	addw	a7,a5,a6  
		sh	a7,0(a2)          
		addi	x4,x4,1		  
		li	x5,2			
		bne 	x4, x5, 1b	  
		add     a0, x0, a7    
		jr      ra            

