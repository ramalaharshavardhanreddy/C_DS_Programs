/************************* Dangling, Void , Null and Wild Pointers **************/  
//P1  
// Deallocating a memory pointed by ptr causes 
// dangling pointer 
#include <stdlib.h> 
#include <stdio.h> 
int main() 
{ 
    int *ptr = (int *)malloc(sizeof(int)); 
  
    // After below free call, ptr becomes a  
    // dangling pointer 
    free(ptr);  
      
    // No more a dangling pointer 
    ptr = NULL; 
}

//P2 
// The pointer pointing to local variable becomes 
// dangling when local variable is not static. 
#include<stdio.h> 
  
int *fun() 
{ 
    // x is local variable and goes out of 
    // scope after an execution of fun() is 
    // over. 
    int x = 5; 
  
    return &x; 
} 
  
// Driver Code 
int main() 
{ 
    int *p = fun(); 
    fflush(stdin); 
  
    // p points to something which is not 
    // valid anymore 
    printf("%d", *p); 
    return 0; 
} 

//P3 
// The pointer pointing to local variable doesn't 
// become dangling when local variable is static. 
#include<stdio.h> 
  
int *fun() 
{ 
    // x now has scope throughout the program 
    static int x = 5; 
  
    return &x; 
} 
  
int main() 
{ 
    int *p = fun(); 
    fflush(stdin); 
      
    // Not a dangling pointer as it points 
    // to static variable. 
    printf("%d",*p); 
} 

 
//P4  Variable goes out of scope also a dan pointer 
void main()
{
   int *ptr;
   {
       int ch;
       ptr = &ch;
   } 
    // Here ptr is dangling pointer
}

//P5 
#include<stdlib.h> 
  
int main() 
{ 
    int x = 4; 
    float y = 5.5; 
      
    //A void pointer 
    void *ptr; 
    ptr = &x; 
  
    // (int*)ptr - does type casting of void  
    // *((int*)ptr) dereferences the typecasted  
    // void pointer variable. 
    printf("Integer variable is = %d", *( (int*) ptr) ); 
  
    // void pointer is now float 
    ptr = &y;  
    printf("\nFloat variable is= %f", *( (float*) ptr) ); 
  
    return 0; 
} 

//P6  
#include <stdio.h> 
int main() 
{ 
    // Null Pointer 
    int *ptr = NULL; 
      
    printf("The value of ptr is %u", ptr); 
    return 0; 
}  

//p7 
int main() 
{ 
    int *p;  /* wild pointer */
  
    int x = 10; 
  
    // p is not a wild pointer now 
    p = &x; 
  
    return 0; 
}  

//p7 
// C++ program to demonstrate differences between pointer 
// and reference. 
#include <iostream> 
using namespace std; 
  
struct demo 
{ 
    int a; 
}; 
  
int main() 
{ 
    int x = 5; 
    int y = 6; 
    demo d; 
      
    int *p; 
    p =  &x; 
    p = &y;                     // 1. Pointer reintialization allowed 
    int &r = x; 
    // &r = y;                  // 1. Compile Error 
    r = y;                      // 1. x value becomes 6 
      
    p = NULL;            
    // &r = NULL;               // 2. Compile Error 
      
    p++;                        // 3. Points to next memory location 
    r++;                        // 3. x values becomes 7 
      
    cout << &p << " " << &x << endl;    // 4. Different address 
    cout << &r << " " << &x << endl;    // 4. Same address 
      
    demo *q = &d; 
    demo &qq = d; 
      
    q->a = 8; 
    // q.a = 8;                 // 5. Compile Error  
    qq.a = 8; 
    // qq->a = 8;               // 5. Compile Error 
      
    cout << p << endl;        // 6. Prints the address 
    cout << r << endl;        // 6. Print the value of x     
  
    return 0; 
} 


//P8 NaN : Not a Number  
// C++ code to demonstrate NaN exception 
#include<iostream> 
#include<cmath> // for sqrt() 
using namespace std; 
int main() 
{ 
    float a = 2, b = -2; 
  
    // Prints the number (1.41421) 
    cout << sqrt(a) << endl; 
  
    // Prints "nan" exception 
    // sqrt(-2) is complex number 
    cout << sqrt(b) << endl; 
  
    return 0; 
} 

//P9
// C++ code to check for NaN exception 
// using "==" operator 
#include<iostream> 
#include<cmath> // for sqrt() 
using namespace std; 
int main() 
{ 
    float a = sqrt(2); 
    float b = sqrt(-2); 
  
    // Returns true, a is real number 
    // prints "Its a real number" 
    a==a? cout << "Its a real number" << endl: 
          cout << "Its NaN" << endl; 
  
    // Returns false, b is complex number 
    // prints "Its nan" 
    b==b? cout << "Its a real number" << endl: 
          cout << "Its NaN" << endl; 
  
    return 0; 
  
} 


//P10 
// C++ code to check for NaN exception 
// using "isnan()"  
#include<iostream> 
#include<cmath> // for sqrt() and isnan() 
using namespace std; 
int main() 
{ 
    float a = sqrt(2); 
    float b = sqrt(-2); 
      
    // Returns false as a  
    // is real number 
    isnan(a)? cout << "Its NaN" << endl: 
              cout << "Its a real number" << endl; 
      
    // Returns true as b is  NaN 
    isnan(b)? cout << "Its NaN" << endl: 
              cout << "Its a real number" << endl; 
      
    return 0;     
}  

//P11   call of overloaded 'fun(NULL)' is ambiguous  
//      NULL is typically defined as (void *)0 and conversion of NULL to integral types is allowed  

// C++ program to demontrate problem with NULL 
#include <bits/stdc++.h> 
using namespace std; 
  
// function with integer argument 
int fun(int N)   { cout << "fun(int)"; } 
  
// Overloaded function with char pointer argument 
int fun(char* s)  { cout << "fun(char *)"; } 
  
int main()  
{ 
    // Ideally, it should have called fun(char *), 
    // but it causes compiler error. 
    fun(NULL);   
}   

//P12   OP :- False  
// This program compiles 
#include<iostream> 
using namespace std; 
  
int main()  
{ 
   int *ptr = nullptr; 
  
   // Below line compiles 
   if (ptr) { cout << "true"; }     
   else { cout << "false"; }     
}  

//P13 

// C++ program to show comparisons with nullptr 
#include <bits/stdc++.h> 
using namespace std; 
  
// Driver program to test behavior of nullptr 
int main() 
{ 
    // creating two variables of nullptr_t type  
    // i.e., with value equal to nullptr 
    nullptr_t np1, np2; 
  
    // <= and >= comparison always return true 
    if (np1 >= np2) 
        cout << "can compare" << endl; 
    else
        cout << "can not compare" << endl; 
  
    // Initialize a pointer with value equal to np1 
    char *x = np1;  // same as x = nullptr (or x = NULL 
                    // will also work)  
    if (x == nullptr) 
        cout << "x is null" << endl; 
    else
        cout << "x is not null" << endl; 
  
    return 0; 
}  

