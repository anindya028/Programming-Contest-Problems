//DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct bulb
{
	int v,k,c,l;
}b[1005];

bool operator<(bulb x,bulb y)
{
	return x.v<y.v;
}

int main()
{
	int n,i,j,cum[1005],opt[1005],mn;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&b[i].v,&b[i].k,&b[i].c,&b[i].l);
		sort(b,b+n);
		cum[0]=b[0].l;
		for(i=1;i<n;i++)
			cum[i]=cum[i-1]+b[i].l;
		opt[0]=b[0].k+b[0].c*b[0].l;
		for(i=1;i<n;i++)
		{
			mn=b[i].k+cum[i]*b[i].c;
			for(j=0;j<i;j++)
				if( (opt[j]+b[i].k+(cum[i]-cum[j])*b[i].c)<mn)
					mn=opt[j]+b[i].k+(cum[i]-cum[j])*b[i].c;
			opt[i]=mn;
		}
		printf("%d\n",opt[n-1]);
	}
	return 0;
}
