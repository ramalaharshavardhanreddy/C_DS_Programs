/*P4.7 Program to understand the use of comma operator*/
/* comma operator used in 2 contexts 1) A separator Ex:- int a = 1, 2, 3;
 *                                   2) An Operator Ex:- a = 1, 2, 3;
 * --When comma is used as an operator, the operands will be evaluated from 
 *   LEFT to RIGHT.
 * -- int var = sum(a(), b()); when comma is used as a separator, the order in 
 *    which two expressions (separated by comma) are evaluated is NOT DEFINED. 
 */ 
#include<stdio.h>

/* Function Prototypes */
int comma_1(void);
int comma_2(void); 
int comma_3(void); 
int comma_4(void);
int comma_5(void);

int main(void)
{
	int a,b,c,sum;
	sum = (a=8,b=7,c=9,a+b+c);	
	printf("Sum=%d\n",sum); 
    
    /* Functions to show the various properties of comma operator */  
    comma_1();
    comma_2();
    comma_3();
    comma_4();
    comma_5();

	return 0;
}
int comma_1(void)
{
    /* comma is the last operator in precedence table. So comma should be 
     * carefully used on right side of an assignment expression. 
    */
    int a = 10, b; 
    b = 20, a;   // b = 20 
    printf(" b = %d ", b); 
    getchar(); 
    return 0; 
}
int comma_2(void)
{
    /* Putting a bracket with comma makes b = a (or 10). */
    int a = 10, b; 
    b = (20, a); // b = a 
    printf(" b = %d ", b); 
    getchar(); 
    return 0; 

}
int comma_3(void)
{
    /* Comma works just as a separator  So compilation Error */
    int a = 1, 2, 3; 
    printf("%d", a); 
    return 0; 
}
int comma_4(void)
{
    /* Comma works as an operator. Precedence of comma operator is least in 
     * operator precedence table. So the assignment operator takes precedence 
     * over comma and the expression a = 1, 2, 3; becomes equivalent to 
     * (a = 1), 2, 3
     * */
    int a; 
    a = 1, 2, 3; 
    printf("%d", a); //a = 1;
    return 0; 
}
int comma_5(void)
{
    /* The result of comma operator cannot be used as l-value in c  */
    int x=5, y=10
    (x, y) = 20;
    printf("%d", y);  // Undefined in C-Language
}
