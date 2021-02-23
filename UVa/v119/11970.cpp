#include<stdio.h>

int ans[100000];

int main()
{
	int t,n,cs = 0,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d:",++cs);
		int m = 0;
		for(i=1;i*i<n;i++)
			if((n-i*i)%i==0)
				ans[m++] = n - i*i;
		m--;
		while(m>=0)
			printf(" %d",ans[m]),m--;
		printf("\n");
	}
	return 0;
}