#include "stack.h"
char* Result;

int main()
{
  int success;
  stack_init();
  
  // Test Case 1
  success = pushToStack(3, 4);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  // Test Case 2
  success = popFromStack(0);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  // Test Case 3
  success = popFromStack(5);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  success = popFromStack(2);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  success = popFromStack(3);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  success = popFromStack(1);
  if(success)
    Result = "PASSED";
  else
    Result = "FAILED";
  
  success = popFromStack(1);
  if(success)
     Result = "PASSED";
  else
    Result = "FAILED";
  

  return 0;
}
