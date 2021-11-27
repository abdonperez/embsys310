// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#include "delay.h"
#include <stdio.h>

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//volatile int counter=0;
int counter=0;

#define ORD14   (1<<14)
#define ORD5    (1<<5)

int a;
int b;

// Probelm #1 - Swapping pointers 
#if 0
void swap_pointer(volatile int** x, volatile int** y);

// Swap the pointer addresses
void swap_pointer(volatile int** x, volatile int** y)
{
    volatile int* temp_ptr = *x;
    *y = *x;
    *x = temp_ptr;
    
    return;
}

int main(void)
{
  volatile int a = 10;
  volatile int b = 12;
  volatile int* a_ptr = &a;
  volatile int* b_ptr = &b;
  
  swap_pointer(&a_ptr, &b_ptr);
  
  return 0;
}
#endif

// Problem #3 - Swapping two characters with assembly 
#if 1
void swapCharsAsm(char x, char y);

void swapCharsAsm(char x, char y)
{
  // Move variable x to R3 
  asm("MOV R3, R0");
  
  // Move variable y to R0
  asm("MOV R0, R1");
  
  // Move variable x to R1
  asm("MOV R1, R3");  
 
   return;

}

int main(void)
{
  char a = 'a';
  char b = 'b';
  
  swapCharsAsm(a, b);

  //printf("%c%c", a, b);
  
  return 0;
}

#endif

