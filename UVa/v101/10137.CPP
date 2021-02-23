//greedy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
#include<vector>
#include<string>
using namespace std;	

int main()
{
	int i,coin[1005],n,ext,sum,x;
	double d;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=sum=0;i<n;i++)
			scanf("%lf",&d),coin[i]=(int)(d*100+0.1),sum+=coin[i];
		ext=sum%n;
		x=sum/n;
		for(i=0;i<n && ext;i++)
		{
			if(coin[i]>x && ext)
			{
				coin[i]--;
				ext--;
			}
		}
		for(i=ext=0;i<n;i++)
			if(coin[i]>x)
				ext+=(coin[i]-x);
		printf("$%.2lf\n",ext/100.);
	}
	return 0;
}
