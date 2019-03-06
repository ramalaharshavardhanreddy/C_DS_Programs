.data 
        HelloWorldString:
            .asciz "Hello World of Assembly"
            
        HELLO:
            .asciz "HELLO"
            
.bss
        .lcomm Destination, 100
        .lcomm DestinationUsingRep, 100 
        .lcomm DestinationUsingstos, 100 
      
.text 
        .globl _start  
        
        _start:
                nop 
                #1. Simple copying using movsb, movsw, movsl 
                
                movl $HelloWorldString, %esi
                movl $Destination, %edi 
                
                movsb 
                movsw
                movsl 
                
                #2. Getting / clearing the DF flag 

                std # set DF flag 
                cld # clear DF flag 

                #3. using REP Instruction  
                
                movl $HelloWorldString, %esi 
                movl $DestinationUsingRep, %edi 
                movl $23, %ecx # set the string length in ECX 
                cld  # clear the DF 
                rep movsb 
                std 
                
                #4. Loading string from memory into EAX Register 

                cld 
                leal HelloWorldString, %esi # store adress of  lable to esi.  
                lodsb              # Transfer one byte from memory to eax.  
                movb $0, %al 

                dec %esi 
                lodsw 
                movw $0, %ax 

                subl $2, %esi # Make esi point back to the original string 
                lodsl 

                #5. Storing string from EAX to memory 
                
                leal DestinationUsingstos, %edi 
                stosb 
                stosw 
                stosl 

                #6. Comparing Strings 

                cld 
                leal HelloWorldString, %esi 
                leal HELLO, %edi
                cmpsb 
                
                dec %esi 
                dec %edi 
                cmpsw 
                
                subl $2, %esi 
                subl $2, %edi 
                cmpsl 
                
                # The exit() syscall 
                movl $1, %eax 
                movl $10, %ebx
                int $0x80 
