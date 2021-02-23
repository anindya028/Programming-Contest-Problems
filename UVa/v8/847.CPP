#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long n,prev;
	while(scanf("%ld",&n)==1)
	{
		prev=2;
		while(n>1)
		{
			if(prev==2)
			{
				if(n%9==0)n/=9;
                                else n=(n/9)+1;
				prev=9;
			}
			else
			{
				if(n%2==0)n/=2;
				else n=(n/2)+1;
				prev=2;
			}
		}
		if(prev==9)printf("Stan wins.\n");
		else printf("Ollie wins.\n");
        }
	return 0;
}













