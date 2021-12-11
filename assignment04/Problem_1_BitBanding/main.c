// LD1 --> PA5
// LD2 --> PB14 -- in class

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

#define ORD5 (1<<5)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB2ENR |= 0x1;         // Set Bit[0]
    *((unsigned int*)(0x42000000+(0x2104C *32) + (0*4))) = 0x1;    
  
    // GPIOA Base Address: 0x480004000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  // To enable PB5 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    while(1)
    {
        counter=0;

        while (counter < 100000)
        {
          counter++;
        }
        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        GPIOA_ODR &= ~ORD5;
    }
}
