/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    PUSH {R5, LR}       // PUSH R5&LR to stack for delay() call below
    CMP  R0, #1     // Check for On call
    BEQ  turn_on    // Branch to On code
    LDR  R3, =GPIOA_BASE+GPIOA_ODR // store address of GPIOA
    LDR  R5, [R3]
    AND  R5, R5, #0x0 // load zero for Off
    STR  R5, [R3]     // Turn LED Off
    B    delay_call // Branch to delay function
turn_on:
    LDR  R3, =GPIOA_BASE+GPIOA_ODR // store address value of GPIOA
    LDR  R5, [R3]  // Load register R5 w/ address of R3
    ORR  R5, R5, #GPIOA_BIT_5  // Shift to flip LED1 bit
    STR  R5, [R3]  //  Turn LED On
delay_call:
    BL  delay
    POP {R5, LR} // POP R5&LR from Stack
    BX  LR
    
    END
