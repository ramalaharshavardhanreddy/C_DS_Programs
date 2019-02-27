/************ Geeks for Geeks Bitwise Algorithms **********************/ 
/* Q1 :- Detect if two integers have opposite signs */ 

/* if two integers having different signs their MSB bit will be different so 
 * Exor of those 2 bits will give the value 1 , so the resultent Exor of 2 
 * different signs value will be negative Number. 
 * */ 

#include <stdio.h>
#define COUNT 4
int Test[][20]={{-7,7},
                {7,10},
                {-10,10},
                {-10,-10}
              };

int  test(int valA,int valB,int* ret)
{
    *ret = -1;
    int choice = 1;
    switch(choice)
    {
        case 1:    
            if((valA^valB)>=0)
                *ret = 0; /* same Sign */          
            else
                *ret = 1; /* opposit sign */ 
            break;
        case 2:
                /* 1-opposit sign and 0 for same sign
                 * (negative)?return 1 if if it positive : return 1 if it is 
                 * positive */
               *ret=(valA<0)?(valB>=0):(valB<0);
        default:
                break;
    }
}
int main()
{
    int i=0,ret;
    for(i=0;i<COUNT;i++){
        ret = -1;
        test(Test[i][0],Test[i][1],&ret);
        if(ret == 1)
            printf("\n  %d and %d : opposit signed Numbers\n",Test[i][0],
                    Test[i][1]);
        else if(ret == 0)
            printf("\n  %d and %d : Same signed Numbers\n",Test[i][0],
                    Test[i][1]);
        else 
            printf("\n Error \n");
    }
    return 0; 
}

/** Q2 :- Find the element that appears once */ 

