/************** program that produces different results in C and C++ **************/ 

//P1 :- program produces sizeof(int) as output in C, but sizeof(char) in C++ 
#include<stdio.h> 
int main() 
{ 
  printf("%d", sizeof('a')); 
  return 0; 
}  


//P2 It prints sizeof(int) in C and sizeof(struct T) in C++. 
#include <stdio.h> 
int T; 
   
int main() 
{ 
    struct T { double x; };  // In C++, this T hides the global variable T,  
                            // but not in C 
    printf("%d", sizeof(T)); 
	
	// output = 4 in C (which is size of int) 
	printf("%d", sizeof(1==1));
	
	// output = 1 in c++ (which is the size of boolean datatype) 
	cout << sizeof(1==1);  
    return 0; 
} 


// C program to demonstrate that direct 
// member initialization is not possible in C 
#include <stdio.h> 
  
struct Record { 
    int x = 7; 
}; 
  
// Driver Program 
int main() 
{ 
    struct Record s; 
    printf("%d", s.x); 
    return 0; 
} 
/* Output :  Compiler Error 
   6:8: error: expected ':', ', ', ';', '}' or  
  '__attribute__' before '=' token 
  int x = 7; 
        ^ 
  In function 'main': */   


// CPP program to initialize data member in c++ 
#include <iostream> 
using namespace std; 
  
struct Record { 
    int x = 7; 
}; 
  
// Driver Program 
int main() 
{ 
    Record s; 
    cout << s.x << endl; 
    return 0; 
} 
// Output 
// 7     

// C program with structure static member 
struct Record { 
    static int x; 
}; 
  
// Driver program 
int main() 
{ 
    return 0; 
} 
/* 6:5: error: expected specifier-qualifier-list  
   before 'static' 
     static int x; 
     ^*/


// C++ program with structure static member 
  struct Record { 
    static int x; 
}; 
// Driver program 
int main() 
{ 
    return 0; 
} 

// C program to demonstrate that Constructor is not allowed 
#include <stdio.h> 
  
struct Student { 
    int roll; 
    Student(int x) 
    { 
        roll = x; 
    } 
}; 
  
// Driver Program 
int main() 
{ 
    struct Student s(2); 
    printf("%d", s.x); 
    return 0; 
} 
/* Output :  Compiler Error 
   [Error] expected specifier-qualifier-list  
    before 'Student' 
   [Error] expected declaration specifiers or  
   '...' before numeric constant 
   [Error] 's' undeclared (first use  
   5555555555in this function) 
   In function 'main': */


// CPP program to initialize data member in c++ 
#include <iostream> 
using namespace std; 
  
struct Student { 
    int roll; 
    Student(int x) 
    { 
        roll = x; 
    } 
}; 
  
// Driver Program 
int main() 
{ 
    struct Student s(2); 
    cout << s.roll; 
    return 0; 
} 
// Output 
// 2 

// C program to illustrate empty structure 
#include <stdio.h> 
  
// empty structure 
struct Record { 
}; 
  
// Driver program 
int main() 
{ 
    struct Record s; 
    printf("%d\n", sizeof(s)); 
    return 0; 
} 
/* Output in C:

0
Output in C++:

1    
*/  

