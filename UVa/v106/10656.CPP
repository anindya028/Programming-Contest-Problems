#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,num[1000],i,freq;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
                freq=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(!num[i])freq++;
		}
		if(freq==n)
		{
			printf("0\n");
			continue;
                }
		for(i=0;;i++)
		{
			if(num[i])
			{
				printf("%d",num[i]);
				break;
			}
		}
		for(i++;i<n;i++)
		{
			if(num[i])printf(" %d",num[i]);
		}
		printf("\n");
	}
	return 0;
}













