/* Stack functions prototypes */
#ifndef	__STACK_H__
#define	__STACK_H__

void stack_init(void);
int pushToStack(int value, int position);
int popFromStack(int position);
int StackFull();
int StackEmpty();

#endif