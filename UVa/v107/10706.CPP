#include<stdio.h>

int digits(int n)
{
    if(n<10) return 1;
    if(n<100) return 2;
    if(n<1000) return 3;
    if(n<10000) return 4;
    if(n<100000) return 5;
    if(n<1000000) return 6;
    if(n<10000000) return 7;
    if(n<100000000) return 8;
    if(n<1000000000) return 9;
    return 10;
}
void find(int n)
{
    unsigned int p,prev,notover,i;
    char str[15];

    p=prev=0;
    for(i=1;;i++)
	{
        prev+=digits(i);
        if(p+prev>=n)
		{
            notover=i;
            break;
        }
        p+=prev;
    }
    for(i=1;i<=notover;i++)
	{
        if(p+digits(i)>=n)
		{
            sprintf(str,"%u",i);
            printf("%c\n",str[n-p-1]);
            break;
        }
        else
            p+=digits(i);
    }
}
int main()
{
    int n,t;

    scanf("%d",&t);
    while(t--)
	{
        scanf("%d",&n);
        find(n);
    }
   
    return 0;
}








