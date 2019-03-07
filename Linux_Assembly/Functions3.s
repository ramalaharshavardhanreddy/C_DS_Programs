.data 
        HelloWorld:
                .asciz "Hello World\n"

.text 
    
        .globl _start 

        
            .type PrintFunction, @function

            PrintFunction:   
                        pushl %ebp  # Store the current value of EBP on the stack. 
                        movl %esp, %ebp  # make EBP points to top of stack 
                        
                        # The write function 
                        movl $4, %eax 
                        movl $1, %ebx 
                        movl 8(%ebp), %ecx
                        movl 12(%ebp), %edx 
                        int  $0x80 
                        
                        movl %ebp, %esp # Restore the old value of ESP 
                        popl %ebp       # Restore the old value of EBP 
                        ret             # change the EIP to start the next instruction
        
        _start:     
           nop 
           
           #push the strlen on the stack 
           pushl $13  

           #push the string pointer to the stack 
           pushl $HelloWorld 

           #call the function  
           call PrintFunction 

           #adjust the Stack pointer
           addl $8, %esp 

        ExitProgram:
            # Exit the progarm 
            movl $1, %eax 
            movl $10, %ebx 
            int $0x80  
