#include<stdio.h>

#define LL long long

int d[100005],sig[100005];

int main()
{
	int i,j;
	d[1] = 1;
	sig[1] = 1;
	for(i=2;i<=100000;i++)
	{
		for(j=1;j*j<=i;j++)
			if(i%j==0)
			{
				d[i]++;
				sig[i]+=j;
				if(i/j != j)
					d[i]++,
					sig[i] += (i/j);
			}
	}
	int t,a,b,k;
	LL g,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);
		g = h = 0;
		for(i=a;i<=b;i++)
			if(i%k==0)
				g += d[i],
				h += sig[i];
		printf("%lld %lld\n",g,h);
	}
	return 0;
}