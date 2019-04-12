//P1  
// C++ program to illustrate the use of auto_ptr 
#include<iostream> 
#include<memory> 
using namespace std; 
  
class A 
{ 
public: 
    void show() {  cout << "A::show()" << endl; } 
}; 
  
int main() 
{ 
    // p1 is an auto_ptr of type A 
    auto_ptr<A> p1(new A); 
    p1 -> show(); 
  
    // returns the memory address of p1 
    cout << p1.get() << endl; 
  
    // copy constructor called, this makes p1 empty. 
    auto_ptr <A> p2(p1); 
    p2 -> show(); 
  
    // p1 is empty now 
    cout << p1.get() << endl; 
  
    // p1 gets copied in p2 
    cout<< p2.get() << endl; 
  
    return 0; 
}  

/* OP:-  
			A::show()
            0x1b42c20
            A::show()
            0          
            0x1b42c20  
*/ 

//P2  
 // C++ program to illustrate the use of unique_ptr 
#include<iostream> 
#include<memory> 
using namespace std; 
  
class A 
{ 
public: 
    void show() 
    { 
        cout<<"A::show()"<<endl; 
    } 
}; 
  
int main() 
{ 
    unique_ptr<A> p1 (new A); 
    p1 -> show(); 
  
    // returns the memory address of p1 
    cout << p1.get() << endl; 
  
    // transfers ownership to p2 
    unique_ptr<A> p2 = move(p1); 
    p2 -> show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
  
    // transfers ownership to p3 
    unique_ptr<A> p3 = move (p2); 
    p3->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
    cout << p3.get() << endl; 
  
    return 0; 
}  
/*
		OP:-  A::show()
              0x1c4ac20
              A::show()
              0          // NULL
              0x1c4ac20
              A::show()
              0          // NULL
              0          // NULL
              0x1c4ac20
*/ 

//P3 
// C++ program to demonstrate shared_ptr 
#include<iostream> 
#include<memory> 
using namespace std; 
  
class A 
{ 
public: 
    void show() 
    { 
        cout<<"A::show()"<<endl; 
    } 
}; 
  
int main() 
{ 
    shared_ptr<A> p1 (new A); 
    cout << p1.get() << endl; 
    p1->show(); 
    shared_ptr<A> p2 (p1); 
    p2->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
  
    // Returns the number of shared_ptr objects 
    //referring to the same managed object. 
    cout << p1.use_count() << endl; 
    cout << p2.use_count() << endl; 
  
    // Relinquishes ownership of p1 on the object 
    //and pointer becomes NULL 
    p1.reset(); 
    cout << p1.get() << endl; 
    cout << p2.use_count() << endl; 
    cout << p2.get() << endl; 
  
    return 0; 
} 

/*   OP:-  
			0x1c41c20
            A::show()
            A::show()
            0x1c41c20
            0x1c41c20
            2
            2
            0          // NULL
            1
            0x1c41c20
*/ 


#include <iostream>
#include <memory> 

using  namespace std;  
class Entry {
public: 
    Entry() { 
           cout << "Created Entry " << endl;
    } 
    ~Entry() {
           cout << " Destoryed Entry!" << endl;  
    }

    void print()
    {cout << "Print function Called " << endl ; }
}; 

int  main()
{
    unique_ptr<Entry> entity (new Entry);
   
    cin.get();
    std::shared_ptr<Entry> e0; 
    {
        std::shared_ptr<Entry> sharedEntity (new Entry);
        std::weak_ptr<Entry> weakEntity  = sharedEntity; 
        e0 = sharedEntity; 

    } 

    std::cin.get(); 
}
// ompile  like g++ -std=c++0x -pedantic  file_name.cpp
