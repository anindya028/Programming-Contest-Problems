//Very good Number theory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;

//#define Long __int64
#define Long long long

#define size 2000002
int pr[285000];
bool p[size];
int gene(int n)
{
	int root=ceil(sqrt(n));
    int i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}

int phi[size*2];
Long cum[size*2],ans;

int main()
{
	int n;
	register int i,j;
	int m=gene(size*2);
	cum[2]=phi[2]=1;
	for(i=3;i<size*2;i++)
	{
		if(!p[(i-1)/2] && i%2)
		{
			phi[i]=i-1;
			cum[i]=cum[i-1]+phi[i];
			continue;
		}
		for(j=0;pr[j]*pr[j]<=i;j++)
			if(i%pr[j]==0)
			{
				if((i/pr[j])%pr[j]==0)
					phi[i]=phi[i/pr[j]]*pr[j];
				else
					phi[i]=phi[i/pr[j]]*phi[pr[j]];
				break;
			}
		cum[i]=cum[i-1]+phi[i];
	}
	while(scanf("%d",&n)==1 && n)
	{
		ans=cum[n];
		for(i=2;2*i<=n;i++)
				ans+=(Long)(i)*cum[n/i];
		printf("%lld\n",ans);
	}
	return 0;
}
