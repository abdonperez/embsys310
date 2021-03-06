1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
a) What is the value of the “counter” from the “Locals” window?
    
    0x80000000
    
b) What is the value of the “counter” in the “Registers” window?
    
    0x80000000
    
c) Please note down which flags are set in the APSR register. And explain why.
    
    N - Negative condition
    V-  Overflow
    
    counter is defined as a singed integer and the most significant bit is set after the increment, making it a Negative value.
    V is set because of an overflow condition
    

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
a) What happens to the value of “counter” in the “Locals” window?

    It flipped to 0x00000000
    
b) Please note down which are set in the APSR register. And explain why.

    Z - zero condition flag
        value set to zero
    C - carry condition flag
        the calculation caused a carry operation


3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?

        0xFFFFFFFF
        
b) Please note down which flags are set in the APSR register. And explain why.

        None are set because the operation incremented nominally.

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?

        0x00000000

b) Please note down which are set in the APSR register. And explain why.

        Z - Zero condition flag
            the previous value had all bits high, so this increment rolled the counter over.
            
        C - Carry condition flag
            with all the bits set adding a 1 causes a carry operation.


5. Move the “counter’ variable outside of main (at the top of the file):
a) What is the scope of the variable “counter”?
    
    The variable is now global and accessible by any function in file.
    
b) Is it still visible in the “Locals” view?

    No.

c) In which window view can we track “counter” now?

    We can track it in the Watch window.

d) What is the address of the “counter” variable in memory?

    0x20000000

6. Change the source code to the following, then run the program in the simulator:
        int counter = 0x0;
        int main() {
            int *p_int = (int *)0x20000000;
            ++(*p_int);
            ++(*p_int);
            ++(*p_int);
            counter ++;
            return 0;
        }

a) What is the value of “counter” at the end of the program (halting at the return 0 statement)

    4

b) Explain why the counter value has changed?

    The value has changed because the operation is incrementing the value in that register address.

7. Change the setting of IAR to run the same program on the evaluation board:
a) What is the address where “counter” is stored?

    0x20000000

b) Is the “counter” variable stored in RAM or ROM?

    RAM
    
c) What is the value of “counter” at the end of the program (halting at the return 0 statement).

    4

