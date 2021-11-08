int counter = 0;

#define RCC_BASE        0x40021000
#define RCC_AHB2ENR     (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE      0x48000400
#define GPIOB_MODER     (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR       (*((unsigned int*)(GPIOB_BASE + 0x14)))

#define GPIOA_BASE      0x48000000
#define GPIOA_MODER     (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR       (*((unsigned int*)(GPIOA_BASE + 0x14)))

//0b10000000000000
#define ODR14           (1<<14)
#define ODR5            (1<<5)

int main()
{
  while(counter < 25)
  {
    counter++;
  }
  
  // Enabled the clock to Port B (GPIOB)
  // RCC_AHB2ENR = RCC_AHB2ENR | 0x2;
  
  // Enabled the clock to Port A (GPIOA)
  RCC_AHB2ENR = RCC_AHB2ENR | 0x1;
  
  // Setup the GPIO port to become an output
  // GPIOB_MODER = GPIOB_MODER & 0xDFFFFFFF;
  
  // Setup the GPIO port to become an output
  GPIOA_MODER = GPIOA_MODER & 0xFFFFF7FF;
  
  while(1)
  {
      // Set the output to 1 - LED ON (or 0x - LED OFF)
      // GPIOB_ODR |= 0x4000; // LED ON
      GPIOA_ODR |= 0x20; // LED ON
      counter = 0;
      while(counter < 100000)
      {
        counter++;
      }
      
      GPIOA_ODR = GPIOA_ODR & ~ODR5; // LED OFF
      counter = 0;
      while(counter < 100000)
      {
        counter++;
      }
      
  }
  
  return 0;
}