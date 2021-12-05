#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

#define SYS_CLOCK_HZ 4000u   // 4.000.000 * 0.001 for 1 ms cycle
uint32_t globalTimeToggle = 100000; 

void SysTick_Initialize(void);

void main(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
    SysTick_Initialize();

    while(1)
    {
      delay(globalTimeToggle);
    }    

}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;  // set for 1 ms
    SysTick->VAL = 0x0;                // initialize to 0
    SysTick->CTRL = 0x7;               // enable clock, interupt, & counter
}

void SysTick_Handler(void)
{
    GPIOA->ODR ^= GPIO_ODR_OD5;
    globalTimeToggle--;
}
