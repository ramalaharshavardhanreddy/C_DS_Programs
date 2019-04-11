//P1  
#include<iostream> 
using namespace std; 
  
int main() 
{ 
  int x = 10; 
  
  // ref is a reference to x. 
  int& ref = x; 
  
  // Value of x is now changed to 20 
  ref = 20; 
  cout << "x = " << x << endl ; 
  
  // Value of x is now changed to 30 
  x = 30; 
  cout << "ref = " << ref << endl ; 
  
  return 0; 
}  

//P2 
//  references to swap two variables 
#include<iostream> 
using namespace std; 
  
void swap (int& first, int& second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 
int main() 
{ 
    int a = 2, b = 3; 
    swap( a, b ); 
    cout << a << " " << b; 
    return 0; 
} 

//P3  Need to get clarity .... 
#include<iostream> 
using namespace std; 
  
int &fun() 
{ 
    static int x = 10;                        // op :- 30
    return x; 
} 
int main() 
{ 
    fun() = 30; 
    cout << fun(); 
    return 0; 
}

 
//P4 
#include<iostream> 
using namespace std; 
  
int fun(int &x)                      //  error: invalid initialization of non-const reference of type ‘int&’  
{                                    //  from an rvalue of type int&’ from an rvalue of type ‘int’
    return x; 
} 
int main() 
{ 
    cout << fun(10); 
    return 0; 
}  

//P5 
#include<iostream> 
using namespace std; 
  
void swap(char * &str1, char * &str2) 
{ 
  char *temp = str1; 
  str1 = str2; 
  str2 = temp; 
} 
int main() 
{ 
  char *str1 = "GEEKS"; 
  char *str2 = "FOR GEEKS"; 
  swap(str1, str2); 
  cout<<"str1 is "<<str1<<endl;         // op:- str1 is FOR GEEKS
  cout<<"str2 is "<<str2<<endl;         //      str2 is GEEKS 
  return 0; 
}  

//P6   
#include<iostream> 
using namespace std; 
  
int main() 
{ 
   int x = 10; 
   int *ptr = &x; 
   int &*ptr1 = ptr;    // op:-  error: cannot declare pointer to ‘int&’ 
// Correct Statement is :-  int &ptr1 = *ptr; 
} 
  
//P7
//Reference to Pointer
#include<iostream> 
using namespace std; 

int g_n = 42;
void func_ref_to_ptr(int*&);
int main()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ref_to_ptr()" << std::endl;

    std::cout << "Before :" << *pn << std::endl; // display 23

    func_ref_to_ptr(pn);

    std::cout << "After :" << *pn << std::endl; // display 42
}

void func_ref_to_ptr(int*& pp)
{
    pp = &g_n;
}

//P8
//Returning Reference 

#include<iostream> 
using namespace std; 

int g_n = 42;

int& func_ret_ref(); 
int main()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ret_ref()" << std::endl;

    std::cout << "Before :" << *pn << std::endl; // display 23

    pn = &func_ret_ref();

    std::cout << "After :" << *pn << std::endl; // display 42
}

int& func_ret_ref()
{
    return g_n;
}


//P9

#include<iostream>
#include<typeinfo>
using namespace std; 

void test(int*&);
int main()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ref_to_ptr type testing " << std::endl;
    test(pn);
}
void test(int*& rpInt)
{
  std::cout << "type of *&rpInt: " << typeid(rpInt).name() 
    << std::endl;//will show int *

}
