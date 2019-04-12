//P1  program where fun() is able to modify local variable x of main().  
void fun(int &x) { 
    x = 20; 
} 
  
int main() { 
    int x = 10; 
    fun(x); 
    cout<<"New value of x is "<<x; 
    return 0; 
}  
//OP :-  New value of x is 20  

//P2 it prints “This is Pet Class”. 

#include <iostream> 
#include<string> 
  
using namespace std; 
  
class Pet { 
public: 
    virtual string getDescription() const { 
        return "This is Pet class"; 
    } 
}; 
  
class Dog : public Pet { 
public: 
    virtual string getDescription() const { 
        return "This is Dog class"; 
    } 
}; 
  
void describe(Pet p) { // Slices the derived class object 
    cout<<p.getDescription()<<endl; 
} 
  
int main() { 
    Dog d; 
    describe(d); 
    return 0; 
} 


//P3  it correctly prints “This is Dog Class”  

#include <iostream> 
#include<string> 
  
using namespace std; 
  
class Pet { 
public: 
    virtual string getDescription() const { 
        return "This is Pet class"; 
    } 
}; 
  
class Dog : public Pet { 
public: 
    virtual string getDescription() const { 
        return "This is Dog class"; 
    } 
}; 
  
void describe(const Pet &p) { // Doesn't slice the derived class object. 
    cout<<p.getDescription()<<endl; 
} 
  
int main() { 
    Dog d; 
    describe(d); 
    return 0; 
} 

//P4   OP:- In base
//          In derived

#include<iostream> 
using namespace std; 
  
class base { 
public: 
    virtual void show() {  // Note the virtual keyword here 
        cout<<"In base \n"; 
    } 
}; 
  
  
class derived: public base { 
public: 
    void show() { 
        cout<<"In derived \n"; 
    } 
}; 
  
// Since we pass b as reference, we achieve run time polymorphism here. 
void print(base &b) { 
    b.show(); 
} 
  
int main(void) { 
    base b; 
    derived d; 
    print(b); 
    print(d); 
    return 0; 
}


//P5    Smart Pointer  

#include<iostream> 
using namespace std; 
  
class SmartPtr 
{ 
   int *ptr;  // Actual pointer 
public: 
   // Constructor: Refer https://www.geeksforgeeks.org/g-fact-93/ 
   // for use of explicit keyword  
   explicit SmartPtr(int *p = NULL) { ptr = p; }  
  
   // Destructor 
   ~SmartPtr() { delete(ptr); }   
  
   // Overloading dereferencing operator 
   int &operator *() {  return *ptr; } 
}; 
  
int main() 
{ 
    SmartPtr ptr(new int()); 
    *ptr = 20; 
    cout << *ptr; 
  
    // We don't need to call delete ptr: when the object  
    // ptr goes out of scope, destructor for it is automatically 
    // called and destructor does delete ptr. 
  
    return 0; 
}



//P6 smart pointer class that works for all types 

#include<iostream> 
using namespace std; 
  
// A generic smart pointer class 
template <class T> 
class SmartPtr 
{ 
   T *ptr;  // Actual pointer 
public: 
   // Constructor 
   explicit SmartPtr(T *p = NULL) { ptr = p; } 
  
   // Destructor 
   ~SmartPtr() { delete(ptr); } 
  
   // Overloading dereferncing operator 
   T & operator * () {  return *ptr; } 
  
   // Overloding arrow operator so that members of T can be accessed 
   // like a pointer (useful if T represents a class or struct or  
   // union type) 
   T * operator -> () { return ptr; } 
}; 
  
int main() 
{ 
    SmartPtr<int> ptr(new int()); 
    *ptr = 20; 
    cout << *ptr; 
    return 0; 
}


// What is explicit constructor in c++ ? 
// What is the use of explicit keyword in c++? 

#include<iostream> 
using namespace std; 

classBase { 
    int b_var;
  public:
    Base() {}
    Base(int var) : b_var(var) {} 
    void print() { cout << b_var << endl;} 
}; 

void  fu(Base b) { 
    b.print(); 
}

int  main() { 
    Base obj1(10);  // Normal call to constructor 
    Base obj2 = 20; // implicit call to constructor  

    fun(obj1);      // Normal call to constructor  
    fun(30);        // implicit call to constructor 
    return  0; 

}

/* op :- 10 
 *       30 
 */   



#include<iostream> 
using namespace std; 

classBase { 
    int b_var;
  public:
    Base() {}
    explicit Base(int var) : b_var(var) {} 
    void print() { cout << b_var << endl;} 
}; 

void  fu(Base b) { 
    b.print(); 
}

int  main() { 
    Base obj1(10);  // Normal call to constructor 
    Base obj2 = 20; // implicit call to constructor  

    fun(obj1);      // Normal call to constructor  
    fun(30);        // implicit call to constructor 
    return  0; 

}
/* OP :-  Compile time error  */  

