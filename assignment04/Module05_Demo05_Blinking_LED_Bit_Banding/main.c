#if 0
// LD1 --> PA5
// LD2 --> PB14 -- in class

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

//  LED1 locations
#define GPIOA_BASE      0x48000000
#define GPIOA_MODER     (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR       (*((unsigned int*)(GPIOA_BASE + 0x14)))

//volatile int counter=0;
int counter=0;

#define ODR14 (1<<14)
#define ODR5  (1<<5)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB2ENR |= 0x2;         // Set Bit[1]
    //RCC_AHB2ENR |= 0x1;         // Set Bit[1]
    //RCC_AHB2ENR &= 0xFFFFFFDF;  // Clear Bit[1]

    *((unsigned int*)(0x42000000+(0x2104C *32) + (1*4))) = 0x1;
  
    /* For flashing LED2 */
    /*===================*/
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    //GPIOB_MODER &= 0xDFFFFFFF;

    // GPIOB Base Address: 0x48000400
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

    /* For flashing LED1 */
    /*===================*/
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOB Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
        counter=0;

        while (counter < 100000)
        {
          counter++;
        }
        //GPIOB_ODR |= ODR14;
        GPIOA_ODR |= ODR5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        //GPIOB_ODR &= ~ORD14;
        GPIOA_ODR &= ~ODR5;
    }
}

#endif

#if 0

// Example of writing to a memory address using bit-band aliasing.
// Writing to 0x2000.0000 in RAM

void main(void)
{
    int value_at_mem_adx;
    
    // clear value at memory address 0x20000000
    *((unsigned int*)(0x20000000)) = 0x0;
    
    value_at_mem_adx = *((unsigned int*)(0x20000000));
    
    for (int i = 0; i < 32; i++)
    {
        *((unsigned int*)(0x22000000+(0x0 *32) + (i*4))) = 0x1;
        value_at_mem_adx = *((unsigned int*)(0x20000000));
    }
}
#endif

// ************ Quiz_05 ************
#if 0
void main(void)
{
     unsigned int* quiz_bitband_alias = ((unsigned int*)(0x22000000+(0x4500 *32) + (4*4)));
    *quiz_bitband_alias = 0x0;
    *quiz_bitband_alias = 0x1;

    int myIntArray[5] = {41, 42, 43, 44, 45};
    int* myIntPtr = myIntArray;
    
    int size1 = sizeof(myIntArray);
    int size2 = sizeof(myIntArray)/sizeof(myIntArray[0]);

    char myCharArray[5] = {'a', 'b', 'c', 'd', 'e'};
    char* myCharPtr = myCharArray;
    
    int size3 = sizeof(myCharPtr)/sizeof(myCharPtr[0]);
    int size4 = sizeof(myCharPtr);
}

#endif

