#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,i,ans,temp;
	while(scanf("%d",&n)==1)
	{
		if(n==1)
		{
			printf("1\n");
			continue;
		}
                if(n%2==0||n%5==0)continue;
		ans=1;
                temp=1;
		for(i=1;ans;i++)
		{
			temp=((10%n)*(temp%n))%n;
			ans+=temp;
			ans%=n;
		}
		printf("%d\n",i);
	}
	return 0;
}













