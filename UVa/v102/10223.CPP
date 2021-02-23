#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	unsigned long n,i;
	unsigned long cat[]={0,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
	while(scanf("%lu",&n)==1)
	{
		for(i=1;i<20;i++)
		{
			if(cat[i]==n)
			{
				printf("%lu\n",i);
				break;
			}
		}
	}
	return 0;
}













