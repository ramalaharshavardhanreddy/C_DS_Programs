//P1 :- In C++, it is a compiler error to call a function before it is declared. But in C, it may compile
#include<stdio.h> 
int main() 
{ 
   foo(); // foo() is called before its declaration/definition 
}  
int foo() 
{ 
   printf("Hello"); 
   return 0;  
}


//P2 In C++, it is compiler error to make a normal pointer to point a const variable, but it is allowed in C.
 #include <stdio.h> 
int main(void) 
{ 
    int const j = 20; 
  
    /* The below assignment is invalid in C++, results in error 
       In C, the compiler *may* throw a warning, but casting is 
       implicitly allowed */
    int *ptr = &j;  // A normal pointer points to const 
  
    printf("*ptr: %d\n", *ptr); 
  
    return 0; 
} 

//P3 In C, a void pointer can directly be assigned to some other pointer like int *, char *. But in C++, a void pointer must be 
//   explicitly typcasted.

#include <stdio.h> 
int main() 
{ 
   void *vptr; 
   int *iptr = vptr; //In C++, it must be replaced with int *iptr=(int *)vptr;  
   return 0; 
}    


//P4 in C++. const variable in C++ must be initialized but in c it isn’t necessary. 
// OP:- Line 4 [Error] uninitialized const 'a' [-fpermissive]  
#include <stdio.h> 
int main() 
{ 
    const int a;   // LINE 4 
    return 0; 
}


