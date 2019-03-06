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
                # 1. Move immediate value into register 
                movl $10,%eax 

                #2. Move immediate value into momorylocation 
                movw $12,Int16 
                
                #3. Move data between the registers
                movl %eax, %ebx 
                 
                #4. Move data from memory to Register  
                movl Int32, %eax 
                
                #5. Move  data from register to memory  
                movb $1, %al
                movb %al, ByteLocation 
                
                #6. Move data into an indexed memory location 
                # Location is decided by BaseAdress(offset, Index, DataSize)
                # offset and Index must be registers, Data Size can be a numerical value
                movl $0, %ecx 
                movl $2, %edi 
                movl $22, IntegerArray(%ecx, %edi, 4)

                #7. Indirect Adressing using registers 
                movl $Int32, %eax 
                movl (%eax), %ebx 

                movl $9, (%eax) 

                # exit() syscall to exit the program 
                movl $1,%eax
                movl $0,%ebx
                int $0x80 
