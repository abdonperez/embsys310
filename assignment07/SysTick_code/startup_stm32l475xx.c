#include "stm32l4xx_it.h"

#pragma section="CSTACK"

void __iar_program_start(void);
void Unused_Handler(void);

int const __vector_table[] @ ".intvec" = {
    (int)__section_end("CSTACK"),   // Stack top
    (int)&__iar_program_start,      // reset handler
    (int)&NMI_Handler,
    (int)&HardFault_Handler,
    (int)&MemManage_Handler,
    (int)&BusFault_Handler,
    (int)&UsageFault_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int)&SVC_Handler,
    (int)&DebugMon_Handler,
    0,      // Reserved
    (int)&PendSV_Handler,
    (int)&SysTick_Handler
};

void NMI_Handler(void)
{
    while(1)
    {
    }
}


void HardFault_Handler(void)
{
    Unused_Handler();
}

void MemManage_Handler(void)
{
    while(1)
    {
    }
}

void BusFault_Handler(void)
{
    while(1)
    {
    }
}

void UsageFault_Handler(void)
{
    while(1)
    {
    }
}

void Unused_Handler(void)
{
    while(1)
    {
    }
}

#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler

