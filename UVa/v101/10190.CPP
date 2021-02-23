#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long n,m,a[40],k,i,flag;
	while(scanf("%ld%ld",&n,&m)==2)
	{

		a[0]=n;
		flag=1;
		if(!m||!n)
		{
			printf("Boring!\n");
			continue;
		}
		if(n==1||m==1)
		{
			printf("Boring!\n");
			continue;
		}
		for(i=1;a[i-1]!=1;i++)
		{
			if(a[i-1]%m)
			{
				flag=0;
				break;
                        }
			else a[i]=a[i-1]/m;
		}
		if(!flag)printf("Boring!\n");
		else
		{
                	printf("%ld",a[0]);
			for(k=1;k<i;k++)printf(" %ld",a[k]);
			printf("\n");
		}
	}
	return 0;
}













