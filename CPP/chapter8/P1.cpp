//P1 
// The output of this program can be different 
// in different runs. Note that the program 
// prints address of a variable and a variable 
// can be assigned different address in different 
// runs. 
#include <stdio.h> 
  
int main() 
{ 
    int x; 
  
    // Prints address of x 
    printf("%p", &x); 
  
    return 0; 
} 

//P2 
// C program to demonstrate declaration of 
// pointer variables. 
#include <stdio.h> 
int main() 
{ 
    int x = 10; 
  
    // 1) Since there is * in declaration, ptr 
    // becomes a pointer varaible (a variable 
    // that stores address of another variable) 
    // 2) Since there is int before *, ptr is 
    // pointer to an integer type variable 
    int *ptr; 
  
    // & operator before x is used to get address 
    // of x. The address of x is assigned to ptr. 
    ptr = &x; 
  
    return 0; 
}

//P3 
// C program to demonstrate use of * for pointers in C 
#include <stdio.h> 
  
int main() 
{ 
    // A normal integer variable 
    int Var = 10; 
  
    // A pointer variable that holds address of var. 
    int *ptr = &Var; 
  
    // This line prints value at address stored in ptr. 
    // Value stored is value of variable "var" 
    printf("Value of Var = %d\n", *ptr); 
  
    // The output of this line may be different in different 
    // runs even on same machine. 
    printf("Address of Var = %p\n", ptr); 
  
    // We can also use ptr as lvalue (Left hand 
    // side of assignment) 
    *ptr = 20; // Value at address is now 20 
  
    // This prints 20 
    printf("After doing *ptr = 20, *ptr is %d\n", *ptr); 
  
    return 0; 
} 

//P4 
// C++ program to illustrate Pointer Arithmetic 
// in C/C++ 
#include <bits/stdc++.h> 
  
// Driver program 
int main() 
{ 
    // Declare an array 
    int v[3] = {10, 100, 200}; 
  
    // Declare pointer variable 
    int *ptr; 
  
    // Assign the address of v[0] to ptr 
    ptr = v; 
  
    for (int i = 0; i < 3; i++) 
    { 
        printf("Value of *ptr = %d\n", *ptr); 
        printf("Value of ptr = %p\n\n", ptr); 
  
        // Increment pointer ptr by 1 
        ptr++; 
    } 
} 

//P5 
// C++ program to illustrate Array Name as Pointers in C++ 
#include <bits/stdc++.h> 
using namespace std; 
  
void geeks() 
{ 
    // Declare an array 
    int val[3] = { 5, 10, 15}; 
  
    // Declare pointer variable 
    int *ptr; 
  
    // Assign address of val[0] to ptr. 
    // We can use ptr=&val[0];(both are same) 
    ptr = val ; 
    cout << "Elements of the array are: "; 
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2]; 
  
    return; 
} 
  
// Driver program 
int main() 
{ 
    geeks(); 
    return 0; 
}  


