
MEMORY
{
PAGE 0 :
   /* BEGIN is used for the "boot to Flash" bootloader mode   */

   BEGIN           	: origin = 0x080000, length = 0x000002
   RAMM0           	: origin = 0x0000F6, length = 0x00030A

   //RAMLS0          	: origin = 0x008000, length = 0x000800
   //RAMLS1          	: origin = 0x008800, length = 0x000800
//   RAMLS2      		: origin = 0x009000, length = 0x000800
//   RAMLS3      		: origin = 0x009800, length = 0x000800
//   RAMLS4      		: origin = 0x00A000, length = 0x000800
   RAMLS5           : origin = 0x00A800, length = 0x000800
   RAMLS0_4         : origin = 0x008000, length = 0x002800

   RESET           	: origin = 0x3FFFC0, length = 0x000002
   RAMGS0_3    : origin = 0x00C000, length = 0x007FF8
   /* Flash sectors */
   /* BANK 0 */
   FLASH_BANK0_SEC0  : origin = 0x080002, length = 0x000FFE	/* on-chip Flash */
   FLASH_BANK0_SEC1  : origin = 0x081000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK0_SEC2_5  : origin = 0x082000, length = 0x004000	/* on-chip Flash */
   //FLASH_BANK0_SEC2  : origin = 0x082000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC3  : origin = 0x083000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC4  : origin = 0x084000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC5  : origin = 0x085000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK0_SEC6  : origin = 0x086000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK0_SEC7_13  : origin = 0x087000, length = 0x007000	/* on-chip Flash */
   //FLASH_BANK0_SEC7  : origin = 0x087000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC8  : origin = 0x088000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC9  : origin = 0x089000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC10 : origin = 0x08A000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC11 : origin = 0x08B000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC12 : origin = 0x08C000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC13 : origin = 0x08D000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC14 : origin = 0x08E000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK0_SEC15 : origin = 0x08F000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK0_SEC14_15 : origin = 0x08E000, length = 0x002000	/* on-chip Flash */

   /* BANK 1 */
   //FLASH_BANK1_SEC0  : origin = 0x090000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC1  : origin = 0x091000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC2  : origin = 0x092000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC3  : origin = 0x093000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC4  : origin = 0x094000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC5  : origin = 0x095000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC6  : origin = 0x096000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC7  : origin = 0x097000, length = 0x001000	/* on-chip Flash */
   //FLASH_BANK1_SEC8  : origin = 0x098000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC0_8  : origin = 0x090000, length = 0x009000	/* on-chip Flash */
   FLASH_BANK1_SEC9  : origin = 0x099000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC10 : origin = 0x09A000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC11 : origin = 0x09B000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC12 : origin = 0x09C000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC13 : origin = 0x09D000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC14 : origin = 0x09E000, length = 0x001000	/* on-chip Flash */
   FLASH_BANK1_SEC15 : origin = 0x09F000, length = 0x000FF0	/* on-chip Flash */

//   FLASH_BANK1_SEC15_RSVD : origin = 0x09FFF0, length = 0x000010  /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */

PAGE 1 :

   BOOT_RSVD       : origin = 0x000002, length = 0x0000F1     /* Part of M0, BOOT rom will use this for stack */
   RAMM1           : origin = 0x000400, length = 0x0003F8     /* on-chip RAM block M1 */
//   RAMM1_RSVD      : origin = 0x0007F8, length = 0x000008     /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */


   RAMLS6      : origin = 0x00B000, length = 0x000800
   RAMLS7      : origin = 0x00B800, length = 0x000800

  // RAMGS0      : origin = 0x00C000, length = 0x002000
  // RAMGS1      : origin = 0x00E000, length = 0x002000
  // RAMGS2      : origin = 0x010000, length = 0x002000
  // RAMGS3      : origin = 0x012000, length = 0x001FF8
//   RAMGS3_RSVD : origin = 0x013FF8, length = 0x000008     /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */

   CLA1_MSGRAMLOW   : origin = 0x001480, length = 0x000080
   CLA1_MSGRAMHIGH  : origin = 0x001500, length = 0x000080
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0, ALIGN(4)
   .text            : >> FLASH_BANK0_SEC7_13,   PAGE = 0, ALIGN(4)
   .cinit           : > FLASH_BANK0_SEC1,     PAGE = 0, ALIGN(4)
   .switch          : > FLASH_BANK0_SEC1,     PAGE = 0, ALIGN(4)
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */

   .stack           : > RAMM1,     PAGE = 1

#if defined(__TI_EABI__)
   .init_array      : > FLASH_BANK0_SEC1,       PAGE = 0,       ALIGN(4)
   .bss             : >> RAMGS0_3,    PAGE = 0,       ALIGN(4)
   .bss:output      : > RAMGS0_3,     PAGE = 0,       ALIGN(4)
   .bss:cio         : > RAMGS0_3,     PAGE = 0,       ALIGN(4)
   .data            : > RAMGS0_3,     PAGE = 0,       ALIGN(4)
   .sysmem          : > RAMGS0_3,     PAGE = 0,       ALIGN(4)

   /* Initalized sections go in Flash */
   .const           : > FLASH_BANK0_SEC14_15,       PAGE = 0,       ALIGN(4)
#else
   .pinit           : > FLASH_BANK0_SEC1,       PAGE = 0,       ALIGN(4)
   .ebss            : > RAMGS0_3,       PAGE = 0,       ALIGN(4)
   .esysmem         : > RAMGS0_3,       PAGE = 0,       ALIGN(4)
   .cio             : > RAMGS0_3,       PAGE = 0,       ALIGN(4)
   .econst          : > FLASH_BANK0_SEC6,    PAGE = 0, ALIGN(4)
#endif
   ramm0            : > RAMM0,       PAGE = 0   //SECTIONS specification
   ramgs0           : > RAMGS0_3,    PAGE = 0,       ALIGN(4)
   ramgs1           : > RAMGS0_3,    PAGE = 0,       ALIGN(4)


#if defined(__TI_EABI__)
    /* CLA specific sections */
    Cla1Prog        : LOAD = FLASH_BANK1_SEC0_8,
                      RUN = RAMLS0_4,
                      LOAD_START(Cla1ProgLoadStart),
                      RUN_START(Cla1ProgRunStart),
                      LOAD_SIZE(Cla1ProgLoadSize),
                      PAGE = 0, ALIGN(4)
#else
    /* CLA specific sections */
    Cla1Prog        : LOAD = FLASH_BANK1_SEC0_8,
                      RUN = RAMLS0_4,
                      LOAD_START(_Cla1ProgLoadStart),
                      RUN_START(_Cla1ProgRunStart),
                      LOAD_SIZE(_Cla1ProgLoadSize),
                      PAGE = 0, ALIGN(4)
#endif


    Cla1ToCpuMsgRAM  : > CLA1_MSGRAMLOW,   PAGE = 1
    CpuToCla1MsgRAM  : > CLA1_MSGRAMHIGH,  PAGE = 1

#if defined(__TI_EABI__)
   .TI.ramfunc      : LOAD = FLASH_BANK1_SEC9,
                      RUN = RAMGS0_3,
                      LOAD_START(RamfuncsLoadStart),
                      LOAD_SIZE(RamfuncsLoadSize),
                      LOAD_END(RamfuncsLoadEnd),
                      RUN_START(RamfuncsRunStart),
                      RUN_SIZE(RamfuncsRunSize),
                      RUN_END(RamfuncsRunEnd),
                      PAGE = 0, ALIGN(4)
#else
   .TI.ramfunc      : LOAD = FLASH_BANK1_SEC9,
                      RUN = RAMGS0_3,
                      LOAD_START(_RamfuncsLoadStart),
                      LOAD_SIZE(_RamfuncsLoadSize),
                      LOAD_END(_RamfuncsLoadEnd),
                      RUN_START(_RamfuncsRunStart),
                      RUN_SIZE(_RamfuncsRunSize),
                      RUN_END(_RamfuncsRunEnd),
                      PAGE = 0, ALIGN(4)
#endif

   .scratchpad      : > RAMLS6,           PAGE = 1
   .bss_cla         : > RAMLS6,           PAGE = 1

   Cla1DataRam      : > RAMLS7,           PAGE = 1
   cla_shared       : > RAMLS6,           PAGE = 1
#if defined(__TI_EABI__)
   .const_cla      : LOAD = FLASH_BANK0_SEC2_5,
                      RUN = RAMLS5,
                      RUN_START(Cla1ConstRunStart),
                      LOAD_START(Cla1ConstLoadStart),
                      LOAD_SIZE(Cla1ConstLoadSize),
                      PAGE = 0, ALIGN(4)
#else
   .const_cla      : LOAD = FLASH_BANK0_SEC2_5,
                      RUN = RAMLS5,
                      RUN_START(_Cla1ConstRunStart),
                      LOAD_START(_Cla1ConstLoadStart),
                      LOAD_SIZE(_Cla1ConstLoadSize),
                      PAGE = 0, ALIGN(4)
#endif
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
