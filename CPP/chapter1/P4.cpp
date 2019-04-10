#if 1 
/*  P1:  ‘a’ is declared as a char and its valid range is -128 to +127. When ‘a’ become 128 through a++, the range is 
		  exceeded and as a result the first number from negative side of the range (i.e. -128) gets assigned to a. 
		  Hence the condition “a <= 225” is satisfied and control remains within the loop. */ 

// C++ program to demonstrate 
// the problem with 'char' 
#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    for (char a = 0; a <= 225; a++) 
        cout << a; 
    return 0; 
} 

#endif  

#if 1  

/* P2:- This code will print ‘1’ infinite times */ 

// C++ program to demonstrate 
// the problem with 'bool' 
#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    // declaring Boolean 
    // variable with true value 
    bool a = true; 
  
    for (a = 1; a <= 5; a++) 
        cout << a; 
  
    return 0; 
}

#endif 

#if 1 
/* P3:- The Loop is is indefinite , short  valid range is -32768 to +32767. */ 

// C++ program to demonstrate 
// the problem with 'short' 
#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    // declaring short variable 
    short a; 
  
    for (a = 32767; a < 32770; a++) 
        cout << a << "\n"; 
  
    return 0; 
}

#endif  

#if 1
/* P4:- The Loop is is indefinite , unsigned short  valid range is 0 to +65535.*/ 
// C++ program to demonstrate 
// the problem with 'unsigned short' 
#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    unsigned short a; 
  
    for (a = 65532; a < 65536; a++) 
        cout << a << "\n"; 
  
    return 0; 
} 
#endif  

