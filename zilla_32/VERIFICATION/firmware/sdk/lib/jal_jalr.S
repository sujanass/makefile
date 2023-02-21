# This is the library for providing assembly level functions used by various test applications.


.global _JAL_
.global _JALR_

_JAL_ :

#unsigned char or uint8_t JAL

        jal  	a6,jump1            # Use JAL to jump to PC location

     jump1:jal  	a6,jump2      # Use JAL to jump to PC location
     jump2:jal  	a6,jump3      # Use JAL to jump to PC location
     jump3:jal  	a6,jump4      # Use JAL to jump to PC location
     jump4:jal  	a6,jump5      # Use JAL to jump to PC location
     jump5:jal  	a6,jump6      # Use JAL to jump to PC location
     jump6:jal  	a6,jump7      # Use JAL to jump to PC location
     jump7:jal  	a6,jump8      # Use JAL to jump to PC location
     jump8:jal  	a6,jump9      # Use JAL to jump to PC location
     jump9:jal  	a6,jump10     # Use JAL to jump to PC location
     jump10:jal  	a6,jump11     # Use JAL to jump to PC location
     jump11:nop                   # No operation

   	jr      ra                     # return


_JALR_ :

#unsigned char or uint8_t JALR
  
   auipc a4,0                       # Store PC value to a4 using auipc
   
     jalr a6,a4,8                  # Use JALR to jump to PC location
     jalr a6,a4,12                 # Use JALR to jump to PC location
     jalr a6,a4,16                 # Use JALR to jump to PC location
     jalr a6,a4,20                 # Use JALR to jump to PC location
     jalr a6,a4,24                 # Use JALR to jump to PC location
     jalr a6,a4,28                 # Use JALR to jump to PC location
     jalr a6,a4,32                 # Use JALR to jump to PC location
     jalr a6,a4,36                 # Use JALR to jump to PC location
     jalr a6,a4,40                 # Use JALR to jump to PC location
     jalr a6,a4,44                 # Use JALR to jump to PC location
     jalr a6,a4,48                 # Use JALR to jump to PC location
     nop   

   jr      ra                     # return



