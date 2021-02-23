#include<stdio.h>

int main()
{
    int i,n;
    while(scanf("%d",&n)==1 && n)
    {
         int sum=0;                                                   
         for(i=0;;i++)
         {
                  sum+=(1<<i);
                  if(sum>=n) break;
         }
         printf("%d\n",i);                         
    }
    return 0;    
}
