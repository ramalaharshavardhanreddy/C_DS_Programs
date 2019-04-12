//P1 
// C++ program to illustrate dynamic allocation 
// and deallocation of memory using new and delete 
#include <iostream> 
using namespace std; 
  
int main () 
{ 
    // Pointer initialization to null 
    int* p = NULL; 
  
    // Request memory for the variable 
    // using new operator 
    p = new(nothrow) int; 
    if (!p) 
        cout << "allocation of memory failed\n"; 
    else
    { 
        // Store value at allocated address 
        *p = 29; 
        cout << "Value of p: " << *p << endl; 
    } 
  
    // Request block of memory 
    // using new operator 
    float *r = new float(75.25); 
  
    cout << "Value of r: " << *r << endl; 
  
    // Request block of memory of size n 
    int n = 5; 
    int *q = new(nothrow) int[n]; 
  
    if (!q) 
        cout << "allocation of memory failed\n"; 
    else
    { 
        for (int i = 0; i < n; i++) 
            q[i] = i+1; 
  
        cout << "Value store in block of memory: "; 
        for (int i = 0; i < n; i++) 
            cout << q[i] << " "; 
    } 
  
    // freed the allocated memory 
    delete p; 
    delete r; 
  
    // freed the block of allocated memory 
    delete[] q; 
  
    return 0; 
} 

//P2   OP :-  10  , new calls constructors 
#include<iostream> 
  
using namespace std; 
  
int main() 
{ 
   int *n = new int(10); // initialization with new() 
   cout << *n; 
   getchar(); 
   return 0; 
}  

//P3 delete vs free 
#include<stdio.h> 
#include<stdlib.h> 
int main() 
{ 
    int x; 
    int *ptr1 = &x; 
    int *ptr2 = (int *)malloc(sizeof(int)); 
    int *ptr3 = new int; 
    int *ptr4 = NULL; 
  
    /* delete Should NOT be used like below because x is allocated  
        on stack frame */
    delete ptr1;   
  
    /* delete Should NOT be used like below because x is allocated  
        using malloc() */
    delete ptr2;   
  
    /* Correct uses of delete */
    delete ptr3; 
    delete ptr4; 
  
    getchar(); 
    return 0; 
}  

//P4 
// CPP code to demonstrate the get_temporary_buffer 
// to sort an array 
  
#include <iostream> 
#include <algorithm> 
#include <memory> 
using namespace std; 
void sorting(int b[], int n) 
{ 
    int i, c = 0; 
    for (i = 0; i < n; i++) { 
        if (b[i] % 2 == 0) { 
            c++; 
        } 
    } 
    cout << "The total even numbers are:  " << c << endl; 
    cout << "original array :"
         << " "; 
    cout << "\n"; 
    for (i = 0; i < 10; i++) { 
        cout << b[i] << " "; 
    } 
    cout << "\n"; 
    pair<int*, ptrdiff_t> p = get_temporary_buffer<int>(10); 
  
    // copy the contents in temporary buffer with pair 
    uninitialized_copy(b, b + p.second, p.first); 
  
    cout << "sorted array :" << endl; 
    for (i = 0; i < p.second; i++) { 
        sort(p.first, p.first + p.second); 
        cout << p.first[i] << " "; 
    } 
} 
// driver program to test above function 
int main() 
{ 
    int b[] = { 8, 9, 2, 1, 10, 14, 37, 18, 17, 5 }; 
    int n = sizeof(b) / sizeof(b[0]); 
    sorting(b, n); 
    return 0; 
}   


//P5 
// CPP code to sort the characters  
// alphabetically using std::get_temporary_buffer 
#include <iostream> 
#include <algorithm> 
#include <memory> 
#include <string.h> 
using namespace std; 
void sorting(char b[], int n) 
{ 
    int i; 
    pair<char*, ptrdiff_t> p = get_temporary_buffer<char>(n); 
  
    // copy the contents in temporary buffer with pair 
    uninitialized_copy(b, b + p.second, p.first); 
  
    cout << "sorted characters are :" << endl; 
    for (i = 0; i < p.second; i++) { 
        sort(p.first, p.first + p.second); 
        cout << p.first[i] << " "; 
        // to release the temporary buffer 
        return_temporary_buffer(p.first); 
    } 
} 
// driver program to test above function 
int main() 
{ 
    char str[] = { 'b', 'g', 'y', 'v', 'p' }; 
    int c; 
    c = strlen(str); 
  
    sorting(str, c); 
    return 0; 
}  



