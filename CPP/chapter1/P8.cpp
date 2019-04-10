/* 
	// Array declaration by specifying size 
        int arr1[10]; 
          
        // With recent C/C++ versions, we can also 
        // declare an array of user specified size 
        int n = 10; 
        int arr2[n];
	  
	// Array declaration by initializing elements 
       int arr[] = { 10, 20, 30, 40 } 
         
       // Compiler creates an array of size 4. 
       // above is same as  "int arr[4] = {10, 20, 30, 40}" 
       

    // Array declaration by specifying size and initializing 
    // elements 
		int arr[6] = { 10, 20, 30, 40 } 
      
        // Compiler creates an array of size 6, initializes first 
        // 4 elements as specified by user and rest two elements as 0. 
        // above is same as  "int arr[] = {10, 20, 30, 40, 0, 0}" 
*/ 

#include <stdio.h> 
  
int main() 
{ 
    int arr[5]; 
    arr[0] = 5; 
    arr[2] = -10; 
    arr[3 / 2] = 2; // this is same as arr[1] = 2 
    arr[3] = arr[0]; 
  
    printf("%d %d %d %d", arr[0], arr[1], arr[2], arr[3]); 
  
    return 0; 
}  

// This C program compiles fine 
// as index out of bound 
// is not checked in C. 
  
#include <stdio.h> 
  
int main() 
{ 
    int arr[2]; 
  
    printf("%d ", arr[3]); 
    printf("%d ", arr[-2]); 
  
    return 0; 
}  

/* In C, it is not compiler error to initialize an array with more elements than specified size
    But it was not compile in c++ 
*/  
#include <stdio.h> 
int main() 
{ 
  
    // Array declaration by initializing it with more 
    // elements than specified size. 
    int arr[2] = { 10, 20, 30, 40, 50 }; 
  
    return 0; 
}  

// C program to demonstrate that array elements are stored 
// contiguous locations 
  
#include <stdio.h> 
int main() 
{ 
    // an array of 10 integers.  If arr[0] is stored at 
    // address x, then arr[1] is stored at x + sizeof(int) 
    // arr[2] is stored at x + sizeof(int) + sizeof(int) 
    // and so on. 
    int arr[5], i; 
  
    printf("Size of integer in this compiler is %lu\n", sizeof(int)); 
  
    for (i = 0; i < 5; i++) 
        // The use of '&' before a variable name, yields 
        // address of variable. 
        printf("Address arr[%d] is %p\n", i, &arr[i]); 
  
    return 0; 
} 

