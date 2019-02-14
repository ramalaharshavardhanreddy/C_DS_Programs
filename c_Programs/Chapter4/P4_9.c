/*P4.9 Program to understand the sizeof operator*/
#include<stdio.h>
int main(void)
{
	int var;
	printf("Size of int=%lu\n",sizeof(int));
	printf("Size of float=%lu\n",sizeof(float));
	printf("Size of var=%lu\n",sizeof(var));
	printf("Size of an integer constant=%lu\n",sizeof(45));  
	return 0;
}
