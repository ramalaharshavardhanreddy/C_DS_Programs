//P1 
#include<iostream> 
using namespace std; 
  
/* local variable is same as a member's name */
class Test 
{ 
private: 
   int x; 
public: 
   void setX (int x) 
   { 
       // The 'this' pointer is used to retrieve the object's x 
       // hidden by the local variable 'x' 
       this->x = x; 
   } 
   void print() { cout << "x = " << x << endl; } 
}; 
  
int main() 
{ 
   Test obj; 
   int x = 20; 
   obj.setX(x); 
   obj.print(); 
   return 0; 
} 

//P2  

#include<iostream> 
using namespace std; 
  
class Test 
{ 
private: 
  int x; 
  int y; 
public: 
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; } 
  Test &setX(int a) { x = a; return *this; } 
  Test &setY(int b) { y = b; return *this; } 
  void print() { cout << "x = " << x << " y = " << y << endl; } 
}; 
  
int main() 
{ 
  Test obj1(5, 5); 
  
  // Chained function calls.  All calls modify the same object 
  // as the same object is returned by reference 
  obj1.setX(10).setY(20); 
  
  obj1.print(); 
  return 0; 
} 


//P3 

#include<iostream> 
using namespace std; 
  
class Test 
{ 
private: 
  int x; 
  int y; 
public: 
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; } 
  static void fun1() { cout << "Inside fun1()"; } 
  // static void fun2() { cout << "Inside fun2()"; this->fun1(); }  // Error Static func can not have this pointer 
  void fun2() { cout << "Inside fun2()"; this->fun1(); }
  
}; 
int main() 
{ 
  Test obj; 
  obj.fun2(); 
  return 0; 
} 

//Op  :-  "Inside fun2()" Inside fun1() 


// Type of ‘this’ pointer in C++  
#include<iostream> 
class X { 
   void fun() const { 
  
    // this is passed as hidden argument to fun(). 
    // Type of this is const X* const 
    } 
};   


#include<iostream> 
class X { 
   void fun() volatile { 
  
     // this is passed as hidden argument to fun(). 
     // Type of this is volatile X* const 
    } 
};   


#include<iostream> 
class X { 
   void fun() const volatile { 
  
     // this is passed as hidden argument to fun(). 
     // Type of this is const volatile X* const 
    } 
};   

//P4  
class A 
{ 
  public: 
    void fun() 
    { 
        delete this; 
    } 
}; 
  
int main() 
{ 
  /* Following is Valid */
  A *ptr = new A; 
  ptr->fun(); 
  ptr = NULL; // make ptr NULL to make sure that things are not accessed using ptr.  
  
  
  /* And following is Invalid: Undefined Behavior */
  A a; 
  a.fun(); 
  
  getchar(); 
  return 0; 
}  

#include<iostream> 
using namespace std; 
  
class A 
{ 
  int x; 
  public: 
    A() { x = 0;} 
    void fun() { 
      delete this; 
  
      /* Invalid: Undefined Behavior */
      cout<<x; 
    } 
}; 




