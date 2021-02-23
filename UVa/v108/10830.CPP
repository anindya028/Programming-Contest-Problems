#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
#define Long long long
int main()
{
	long n,i,j=0;
        Long ans,temp;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		if(n<4)
		{
			printf("Case %ld: 0\n",j+1);
			j++;
			continue;
		}
                ans=0;
		for(i=2;i*i<n;i++)
		{
			temp=n/i;
			ans+=((temp-i+1)*i+temp*(temp+1)/2-i*(i+1)/2);
		}
		if(i*i==n)ans+=i;
		printf("Case %ld: %lld\n",j+1,ans);
		j++;
	}
	return 0;
}













