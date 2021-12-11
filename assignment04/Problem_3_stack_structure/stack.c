#include <stdio.h>
#include "stack.h"
#define STACK_SIZE	5
#define INT_SIZE        sizeof(int)

int Stack[STACK_SIZE];
int SizeOfStack = 0; 
int stackFull = 0;
int stackEmpty = 1;

void stack_init(void)
{
  int x;
  for(x = 0; x <= STACK_SIZE; x++){
    Stack[x] = x+2;
  }
  
  SizeOfStack = sizeof(Stack)/INT_SIZE;
}

int pushToStack(int value, int position)
{
  if (!StackFull()){
    Stack[position] = value;
    return 1;
  }else{
    return -1;
  }
}

int popFromStack(int position)
{
  if (!StackFull()){
      Stack[position] = NULL;
      return 1;
  }else{
    return -1;
  }
}

int StackFull()
{
  
  if(Stack[STACK_SIZE-1] != NULL)
  {
    return 1;
  } else 
  {
    return 0;
  }
}

int StackEmpty()
{
  if(Stack[0] == NULL)
  {
    return 1;
  } else {
    return 0;
  }	
}