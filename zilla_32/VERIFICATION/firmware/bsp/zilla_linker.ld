/*
**
*******************************************************************************
**
** Linker script for Zilla Gen 0 32 -bit. i.e. RV32IM
**
** Note: Read comments for more details
**
*******************************************************************************
*/


OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
/*OUTPUT_ARCH(riscv)*/
 
OUTPUT_ARCH( "riscv" )

/* This specifies the first function to execute. _reset is the function name */
ENTRY(_reset)

/* In this section mention the memory sections, attributes, start address and length */
MEMORY
{
  /* Note: Please change according to actual memory address range for zilla */

  INST_MEM       (rxai) : ORIGIN = 0x00008000, LENGTH = 0x40000  /* 256 KB */
  MAILBOX1      (rwxai) : ORIGIN = 0x00048000, LENGTH = 0x4      /*   4 B */
  MAILBOX2      (rwxai) : ORIGIN = 0x00048004, LENGTH = 0x4      /*   4 B */
  PRINT_MAILBOX (rwxai) : ORIGIN = 0x00048008, LENGTH = 0x100    /* 256 B */
  MAIL_FLG1     (rwxai) : ORIGIN = 0x00048108, LENGTH = 0x4      /*   4 B */
  MAIL_FLG2     (rwxai) : ORIGIN = 0x0004810C, LENGTH = 0x4      /*   4 B */
  DATA_MEM      (rwxai) : ORIGIN = 0x00048110, LENGTH = 0x3FEE0  /* 256 KB - 4B - 4B -256B - 4B -4B */

        /* TODO - The spike simulation might not work with INST_MEM memory < 20KB (most cases) 
           To fix this, just make LENGTH bigger. However, this will not create problems
           where SPIKE simulator is not involved */
}

/* Here we are allocating address for various sections */
SECTIONS
{
  /* Define __boot_address for Entry point address */
  PROVIDE(__boot_address = 0x8100);                /* Start of text (code) */
  PROVIDE(__data_address = ORIGIN(DATA_MEM));   /* Start of data (rodata, data, bss, etc) */

  /* Define mailbox and print mailbox symbols for use by C */
  PROVIDE(__mailbox1__          = ORIGIN(MAILBOX1));
  PROVIDE(__mailbox2__          = ORIGIN(MAILBOX2));
  PROVIDE(__mailbox_print__     = ORIGIN(PRINT_MAILBOX));
  PROVIDE(__mailbox1_flag__     = ORIGIN(MAIL_FLG1));
  PROVIDE(__mailbox2_flag__     = ORIGIN(MAIL_FLG2));

  PROVIDE(__mailbox1_len__      = LENGTH(MAILBOX1));
  PROVIDE(__mailbox2_len__      = LENGTH(MAILBOX2));
  PROVIDE(__mailbox_print_len__ = LENGTH(PRINT_MAILBOX));
  PROVIDE(__mailbox_flag_len__  = LENGTH(MAIL_FLG1));
  PROVIDE(__mailbox_flag_len__  = LENGTH(MAIL_FLG2));

 /* CORE-V: interrupt vectors */

  .vectors (ORIGIN(INST_MEM)):
  {
    PROVIDE(_start_vector = .);
    KEEP(*(.isr_vector));
    PROVIDE (end = .);
     /* PROVIDE(_vector_end = ORIGIN(INST_MEM) + 0x100);
      . = _vector_end; */

  } >INST_MEM



  /*  init code at __boot_address */
  .init ():
  {
    KEEP (*(SORT_NONE(.init)))
    KEEP (*(.text.start))
  } >INST_MEM


  /* Note: All Text ection goes into INST_MEM
     All rodata, data, sdatata, etc go into DATA_MEM */
  .text :
    {
        
        *(.text*)

        _end_text = .;
    } >INST_MEM
      
     /* Align to 8 byte boundary */
  . = ALIGN(8);

  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);



  .results        (__data_address) : { *(.results) } >DATA_MEM

  .rodata         : { *(.rodata .rodata.*) } >DATA_MEM

  .rodata1        : { *(.rodata1) } >DATA_MEM
  /* Align to 8 byte boundary */
  . = ALIGN(8);

  /* Note:  .sdata is the section for initialized data, which is accessed using GP relative addressing */
    .sdata2         :
  {
    *(.sdata2 .sdata2.*)
  } >DATA_MEM
   
   /* Align to 8 byte boundary */
  . = ALIGN(8); 
      
      
  /*KEEP(*(.eh_frame))*/
  /*    . = ALIGN(8);*/

     /* .sbss is the section for un-initialized data, which is accessed using GP relative addressing */
   .sbss2          : { *(.sbss2 .sbss2.*) } >DATA_MEM
  
   /* Align to 8 byte boundary */
   . = ALIGN(8);	


    _stored_data = .;
   /* Data section */
   .data :  
    {
        _start_data = .;
        *(.data*)
        //_global_pointer = . + 0x800;     
	. = ALIGN(8);
        _end_data = .;
    } >DATA_MEM
    /* Align to 8 byte boundary */
      . = ALIGN(8);


  /* data1 section */
  .data1 :
  {
      *(.data1) 
  } >DATA_MEM

  /* Align to 8 byte boundary */
  . = ALIGN(8);
 
      
     /* sdata section */
  .sdata :
  {
      __SDATA_BEGIN__ = .;
      *(.srodata.cst16) *(.srodata.cst8) *(.srodata.cst4) *(.srodata.cst2) *(.srodata .srodata.*)
      *(.sdata .sdata.*)
  } >DATA_MEM

  /* Align to 8 byte boundary */
  . = ALIGN(8);

  /* End of data section */
  _edata = .;
  PROVIDE (edata = .);
  . = .;
  /* Start of bss section */
  _start_bss = .;

  /* Uninitialized data section with short address access */
  .sbss           :
  {
      *(.dynsbss)
      *(.sbss .sbss.*)
      *(.scommon)
  } >DATA_MEM

  /* Align to 8 byte boundary */
  . = ALIGN(8);
  /* Uninitialized data section */
    .bss :
    {
      *(.dynbss)
      *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(8);
  } >DATA_MEM
  /* Align to 8 byte boundary */
  . = ALIGN(8);
        _end_bss = .;


  /* Global Pointer value */
  _global_pointer = MIN(__SDATA_BEGIN__ + 0x800, MAX(_start_data + 0x800, _end_bss - 0x800));
        _end = .;
  PROVIDE (end = .);

  /* Heap grows upward towards end of DATA_MEM */
  .heap                    : ALIGN(16)
  {
      PROVIDE(__heap_start = .);
      /* If end of DATA_MEM is not 16-byte aligned, align to previous 16-byte
         boundary */
      PROVIDE(__heap_end = ALIGN(ORIGIN(DATA_MEM) + LENGTH(DATA_MEM) - __heap_start - 15, 16));
      . = __heap_end;
  } >DATA_MEM

  /* Stack grows downward from end of DATA_MEM */
  .stack (__heap_start)    : ALIGN(16)
  {
      PROVIDE(__stack_start = __heap_start);
      . = __heap_end;
      PROVIDE(_end_stack = .);
  } >DATA_MEM
  
}


