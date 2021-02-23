//Number Theory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

int pr[80000];
bool p[1000005];

int gene(int n)
{
    int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	
	j=1;
	pr[0]=2;
	for(i=3;i<=n;i++)
	{
		if(!p[i])
        {
			pr[j]=i;
			j++;
        }
	}
    return j;
}

int fr[1000005];
int ans[1000005];

int main()
{
	int m = gene(1000000);
	fr[1] = 1;
	ans[1] = 1;
	int i,j,mx = 1, got = 1;
	for(i=2;i<=1000000;i++)
	{
		if(!p[i])
			fr[i] = 2;
		else
		{
			int temp = i,cnt = 0;
			for(j=0;pr[j]*pr[j]<=temp;j++)
				if(temp%pr[j]==0)
				{
					while(temp%pr[j]==0)
						cnt++,temp/=pr[j];
					break;
				}
			fr[i] = (cnt+1) * (fr[temp]);
		}

		if(fr[i]>=mx)
			mx = fr[i], got = i;
		ans[i] = got;
	}
//	for(i=2;i<=36;i++)
//		printf("%d\n",fr[i]);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}