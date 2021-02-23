#include<stdio.h>

int main()
{
	int b,d,n,ans;
	while(scanf("%d%d%d",&b,&d,&n)==3)
	{
		ans=0;
		int now,carry=0,prev=d;
		do
		{
			ans++;
			now=(prev*n+carry)%b;
			carry=(prev*n+carry)/b;
			prev=now;
		}while(!(now==d && !carry));
		printf("%d\n",ans);
	}
	return 0;
}