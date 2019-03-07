.data 
        HelloWorld:
                .asciz "Hello World\n"

        ZeroFlagSet:
                .asciz "Zero flag was set\n"

        ZeroFlagNotSet:
                .asciz "Zero flag not set\n"

.text 
    
        .globl _start 

        _start:
           
           nop 
           movl $10, %eax
           xorl %eax, %eax    # takes eax xor eax = 0  , so ZF flag was set   
           jz FlagSetPrint
                     
          FlagNotSetPrint:
                movl $4, %eax
                movl $1, %ebx 
                movl $ZeroFlagNotSet, %ecx 
                movl $19, %edx 
                int $0x80 
                jmp ExitProgram

          FlagSetPrint: 
                movl $4, %eax
                movl $1, %ebx 
                movl $ZeroFlagSet, %ecx 
                movl $19, %edx 
                int $0x80 
                jmp ExitProgram 


        ExitProgram:
            # Exit the progarm 
            movl $1, %eax 
            movl $10, %ebx 
            int $0x80  

       PrintHelloWorld:
            movl $10, %ecx 
            PrintTenTimes:
                pushl %ecx
                movl $4, %eax
                movl $1, %ebx  
                leal HelloWorld, %ecx 
                movl $14, %edx 
                int $0x80 
                popl %ecx 
            loop PrintTenTimes 
            jmp ExitProgram  
