#if 1  
/* P1 */ 
#include <iostream> 
  
// macro definition 
#define LIMIT 5 
int main() 
{ 
    for (int i = 0; i < LIMIT; i++) { 
        std::cout << i << "\n"; 
    } 
  
    return 0; 
} 
#endif  

#if 1 
/*  P2:-  Macros with arguments */ 
#include <iostream> 
  
// macro with parameter 
#define AREA(l, b) (l * b) 
int main() 
{ 
    int l1 = 10, l2 = 5, area; 
  
    area = AREA(l1, l2); 
  
    std::cout << "Area of rectangle is: " << area; 
  
    return 0; 
}
#endif 

#if 1   
/* P3:- #pragma Directive */ 
#include <stdio.h> 
  
void func1(); 
void func2(); 
  
#pragma startup func1 
#pragma exit func2 
  
void func1() 
{ 
    printf("Inside func1()\n"); 
} 
  
void func2() 
{ 
    printf("Inside func2()\n"); 
} 
  
int main() 
{ 
    void func1(); 
    void func2(); 
    printf("Inside main()\n"); 
  
    return 0; 
} 
#endif  

#if 1

/* */ 

#include <stdio.h> 
  
void func1(); 
void func2(); 
  
void __attribute__((constructor)) func1(); 
void __attribute__((destructor)) func2(); 
  
void func1() 
{ 
    printf("Inside func1()\n"); 
} 
  
void func2() 
{ 
    printf("Inside func2()\n"); 
} 
  
int main() 
{ 
    printf("Inside main()\n"); 
  
    return 0; 
} 
#endif 

 

