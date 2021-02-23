#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		int ans=0;
		while(n>1)
		{
			if(n==2)
			{
				ans++;
				n--;
			}
			ans+=(n/3);
			n= n/3 + n%3;
		}
		printf("%d\n",ans);
	}
	return 0;
}