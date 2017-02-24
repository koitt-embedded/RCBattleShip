/*----------------------------------------------------------------------------*/
/* AR16XX.cmd                                                                 */
/*                                                                            */
/* (c) Texas Instruments 2016, All rights reserved.                           */
/*                                                                            */

/* USER CODE BEGIN (0) */
/* USER CODE END */


/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
--retain="*(.intvecs)"

/*----------------------------------------------------------------------------*/
/* Memory Map                                                                 */
MEMORY{
    VECTORS (X)  : origin=0x00000000 length=0x00000100
    CODE    (RX) : origin=0x00000100 length=0x0003FF00
    DATA    (RW) : origin=0x08000000 length=0x00030000
}

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */
SECTIONS{
    .intvecs : {} > VECTORS
    .text    : {} > CODE
    .const   : {} > CODE
    .cinit   : {} > CODE
    .pinit   : {} > CODE
    .bss     : {} > DATA
    .data    : {} > DATA
    .stack   : {} > DATA
}
/*----------------------------------------------------------------------------*/
