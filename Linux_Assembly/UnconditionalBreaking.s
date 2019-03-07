.data 
        HelloWorld:
                .asciz "Hello World\n"

        CallDemo:
                .asciz "Call works\n"

.text 
    
        .globl _start 

        _start:
           
           nop  
            # jmp ExitProgram     # Program will jump to ExitProgram lable.  
            # call CallMe         # program call CallMe function 
           
          #write Hello world 
            movl $4, %eax
            movl $1, %ebx 
            movl $HelloWorld, %ecx 
            movl $12, %edx 
            int $0x80 


        ExitProgram:
            # Exit the progarm 
            movl $1, %eax 
            movl $10, %ebx 
            int $0x80  

       CallMe: 
            movl $4, %eax 
            movl $1, %ebx 
            movl $CallDemo, %ecx 
            movl $11, %edx 
            int $0x80 
            ret  
