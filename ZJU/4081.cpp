#include<stdio.h>
#include<algorithm>

using namespace std;

int f(int a,int b)
{
	int i,cnt=0;
	for(i=0;i<23;i++)
		cnt += ((a & (1<<i)) != (b & (1<<i)));
	return cnt;
}

int main()
{
	int m,n,a[105],b[105],t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		sort(a,a+m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			int got=10000,idx,j;
			for(j=0;j<m;j++)
			{
				int now=f(a[j],b[i]);
				if(now<got)
					got=now,idx=j;
			}
			printf("%d\n",a[idx]);
		}
	}
	return 0;
}