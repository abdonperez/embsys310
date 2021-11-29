#include <stdint.h>
#include "delay.c"
#include "stm32l475xx.h"
#include "system_stm32l4xx.h"

volatile int counter = 0;

void main(void)
{
  // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
  // RCC Base Address: 0x40021000
  // Address offset: 0x4C
  // Set bit[1] to 1
  // 1. Enable clock to Peripheral
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    GPIOB->MODER |= GPIO_MODER_MODE14_0;

  // GPIOA - LED1 enable output
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;

  while(1)
  {
      GPIOA->ODR |= GPIO_ODR_OD5;
      delay(100000);
      
      GPIOA->ODR &= ~GPIO_ODR_OD5;
      delay(100000);

  } 

}
