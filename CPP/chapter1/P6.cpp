// C program to illustrate need of loops 
#include <stdio.h> 
  
int main() 
{ 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
    printf( "Hello World\n"); 
      
    return 0; 
} 

/* For Loop Syntax :- 
	for (initialization expr; test expr; update expr)
{    
     // body of the loop
     // statements we want to execute
}*/ 

// C program to illustrate for loop 
#include <stdio.h> 
  
int main() 
{ 
    int i=0; 
      
    for (i = 1; i <= 10; i++) 
    { 
        printf( "Hello World\n");     
    } 
  
    return 0; 
} 

/* While  Loop Syntax  :- 
	initialization expression;
while (test_expression)
{
   // statements
 
  update_expression;
} */ 

// C program to illustrate for loop 
#include <stdio.h> 
  
int main() 
{ 
    // initialization expression 
    int i = 1; 
  
    // test expression 
    while (i < 6) 
    { 
        printf( "Hello World\n");     
  
        // update expression 
        i++; 
    } 
  
    return 0; 
}  

/* do while syntax :- 
	initialization expression;
do
{
   // statements

   update_expression;
} while (test_expression);
  
*/ 

// C program to illustrate do-while loop 
#include <stdio.h> 
  
int main() 
{ 
    int i = 2; // Initialization expression 
  
    do
    { 
        // loop body 
        printf( "Hello World\n");     
  
        // update expression 
        i++; 
  
    }  while (i < 1);   // test expression 
  
    return 0; 
}   


/* C program to demonstrate infinite loops 
   using for and while 
   Uncomment the  sections to see the output  */  
  
#include <stdio.h> 
  
int main () 
{ 
    int i; 
  
    // This is an infinite for loop as the condition 
    // expression is blank 
    for ( ; ; ) 
    { 
       printf("This loop will run forever.\n"); 
    } 
  
    // This is an infinite for loop as the condition 
    // given in while loop will keep repeating infinitely 
    /* 
    while (i != 0) 
    { 
        i-- ; 
        printf( "This loop will run forever.\n"); 
    } 
    */
  
    // This is an infinite for loop as the condition 
    // given in while loop is "true" 
    /* 
    while (true) 
    { 
        printf( "This loop will run forever.\n"); 
    } 
    */
}   


