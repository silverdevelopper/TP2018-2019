#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkedlist.h"

int main(int argc, char *argv[])
{

    int n,i;
    scanf("%d",&n);
    for(int i = 2; i < n; i++)
    {
      
        if(n%i==0)
        printf("%d  ",i);

    }
    
   
   
return 0;
}