/* if Syntax  :- 
			if(condition) 
			{
				// Statements to execute if
				// condition is true
			}  
*/ 
 
// C++ program to illustrate If statement 
#include<iostream> 
using namespace std; 
  
    int main() 
    { 
        int i = 10; 
   
        if (i > 15) 
        { 
           cout<<"10 is less than 15"; 
        }     
         
        cout<<"I am Not in if"; 
    } 
 

 /* if-else Syntax :- 
	Syntax:

          if (condition)
          {
              // Executes this block if
              // condition is true
          }
          else
          {
              // Executes this block if
              // condition is false
          }
*/ 

// C++ program to illustrate if-else statement 
#include<iostream> 
using namespace std; 
  
int main() 
 { 
        int i = 20; 
   
        if (i < 15) 
            cout<<"i is smaller than 15"; 
        else
            cout<<"i is greater than 15"; 
              
    return 0;     
 }  
 
 
 /*   nested-if Syntax :-  
 
	if (condition1) 
    {
       // Executes when condition1 is true
       if (condition2) 
       {
          // Executes when condition2 is true
       }
    }	 
*/  

// C++ program to illustrate nested-if statement 
int main() 
{ 
    int i = 10; 

    if (i == 10) 
    { 
        // First if statement 
        if (i < 15) 
           cout<<"i is smaller than 15"; 

        // Nested - if statement 
        // Will only be executed if statement above 
        // it is true 
        if (i < 12) 
            cout<<"i is smaller than 12 too"; 
        else
            cout<<"i is greater than 15"; 
    } 

    return 0; 
}   

/* if-else-ladder Syntax :- 
	if (condition)
        statement;
    else if (condition)
        statement;
    .
    .
    else
        statement;
*/ 
// C++ program to illustrate if-else-if ladder 
#include<iostream> 
using namespace std; 
  
int main() 
{ 
    int i = 20; 
   
    if (i == 10) 
        cout<<"i is 10"; 
    else if (i == 15) 
        cout<<"i is 15"; 
    else if (i == 20) 
        cout<<"i is 20"; 
    else
        cout<<"i is not present"; 
} 

/* Switch Syntax :- 
	switch (n)
    {
        case 1: // code to be executed if n = 1;
            break;
        case 2: // code to be executed if n = 2;
            break;
        default: // code to be executed if n doesn't match any cases
    } 
*/  
   
  /* 
  Valid expressions for switch:
		// Constant expressions allowed
			switch(1+2+23)
			switch(1*2+3%4)
  Invalid switch expressions for switch:

		// Variable expression not allowed
			switch(ab+cd)
			switch(a+b+c)
  
  */ 
// Following is a simple program to demonstrate  
// syntax of switch. 
#include <stdio.h> 
int main() 
{ 
   int x = 2; 
   switch (x) 
   { 
       case 1: printf("Choice is 1"); 
               break; 
       case 2: printf("Choice is 2"); 
                break; 
       case 3: printf("Choice is 3"); 
               break; 
       default: printf("Choice other than 1, 2 and 3"); 
                break;   
   } 
   return 0; 
}   
 
//  C/C++ program to execute both statements simultaneously 
	
#include <stdio.h> 
int main() 
{ 
  if (1) //Replace 1 with 0 and see the magic 
  { 
    label_1: printf("Hello "); 
      
    // Jump to the else statement after  
    // executing the above statement 
    goto label_2; 
  } 
  else
  { 
    // Jump to 'if block statement' if  
    // the Boolean condition becomes false 
    goto label_1; 
  
    label_2: printf("Geeks"); 
  } 
  return 0; 
}  
			
