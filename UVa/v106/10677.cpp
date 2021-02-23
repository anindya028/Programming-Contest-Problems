#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int calc(int n,int b1,int b2)
{
	int ret=0,k=1;
	while(n)
		ret+=(n%b1)*k,k*=b2,n/=b1;
	return ret;
}

int main()
{
	int b1,b2,r1,r2,i,ans,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&b1,&b2,&r1,&r2);
		ans=0;
		for(i=r2-1;i>r1;i--)
		{
			int a2=calc(i,b1,b2);
			if(a2%i==0)
			{
				ans=i;
				break;
			}
		}
		if(ans)
			printf("%d\n",ans);
		else
			printf("Non-existent.\n");
	}
	return 0;
}