#include <stdint.h>
#include "delay.h"

void delay(uint32_t time_in_ms)
{
  int time_in_sec = time_in_ms*1000;
  
  while (time_in_sec > 0)
  {
    //time_in_sec--;    
  }
}