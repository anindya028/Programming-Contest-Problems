#include<stdio.h>

int num[10005];

int main()
{
	int n,i,cnt;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&num[i]);
		num[0]=num[n];
		num[n+1]=num[1];
		for(i=1,cnt=0;i<=n;i++)
			if((num[i]>num[i-1] && num[i]>num[i+1]) || (num[i]<num[i-1] && num[i]<num[i+1]))
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}