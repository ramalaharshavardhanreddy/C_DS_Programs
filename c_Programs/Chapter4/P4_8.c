/*P4.8 Program to interchange the value of two variables using comma operator*/
#include<stdio.h>

/* Function Prototypes */ 
int Swap_using_operators1(void);
int Swap_using_operators2(void);
int Swap_using_operators3(void);

int main(void)
{
 	int a=8,b=7,temp;
	printf("a=%d, b=%d\n",a,b);
	temp=a,a=b,b=temp;
	printf("a=%d, b=%d\n",a,b);

    /* Various ways of Swaping */ 
    Swap_using_operators1();   /* Using +,-    */
    Swap_using_operators2();   /* Using *,/    */
    Swap_using_operators3();   /* Using Exor   */ 

	return 0;
}
int Swap_using_operators1(void)
{
    int a=10,b=20;
    printf("\n Before Swaping a=%d,b=%d \n",a,b);
    a=a+b;  // a=10+20 :: a=30 & b=20
    b=a-b;  // b=30-20 :: b=10 & a=30
    a=a-b;  // a=30-10 :: a=20 & b=10 
    printf("\n After Swaping a=%d,b=%d \n",a,b);
    return 0;
}
int Swap_using_operators2(void)
{

    int a=10,b=20;
    printf("\n Before Swaping a=%d,b=%d \n",a,b);
    a=a*b;  // a=10*20 :: a=200 & b=20
    b=a/b;  // b=200/20 :: b=10 & a=200
    a=a/b;  // a=200/10 :: a=20 & b=10 
    printf("\n After Swaping a=%d,b=%d \n",a,b);
    return 0;
}
int Swap_using_operators3(void)
{
    /*  0 XOR 0 = 0
     *  0 XOR 1 = 1
     *  1 XOR 0 = 1
     *  1 XOR 1 = 0 
     *  a XOR 0 = a
     *  a XOR 1 = a-bar
     *  a XOR a = 0
     */
    int a=10,b=20;
    printf("\n Before Swaping a=%d,b=%d \n",a,b);
    a=a^b;  // a=10^20 :: a=30 & b=20
    b=a^b;  // b=30^20 :: b=10 & a=30
    a=a^b;  // a=30^10 :: a=20 & b=10 
    printf("\n After Swaping a=%d,b=%d \n",a,b);
    return 0;

}
