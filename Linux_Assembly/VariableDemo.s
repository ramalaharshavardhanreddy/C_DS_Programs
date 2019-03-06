# Demo program to show how to use Data types and MOVx instructuins 

.data 
    HelloWorld:
            .ascii "Hello World!"

    ByteLocation:
            .byte 10

    Int32:
            .int 2 

    Int16:
            .short 3

    Float:
            .float 1.25

    IntegerArray:
            .int 10,20,30,50,60

.bss
        .comm LargeBuffer, 10000 

.text 
        .globl _start

        _start:
                nop
                # exit() syscall to exit the program 
                movl $1,%eax
                movl $0,%ebx
                int $0x80 
