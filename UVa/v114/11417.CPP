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

int gcd(int m,int n)
{
	if(!n) return m;
	return gcd(n,m%n);
}

int ans[505];

int main()
{
	int n;
	register int i,j;
	ans[1]=0;
	for(i=2;i<501;++i)
	{
		ans[i]=ans[i-1];
		for(j=1;j<i;++j)
			ans[i]+=gcd(i,j);
	}
	while(scanf("%d",&n)==1 && n)
		printf("%d\n",ans[n]);
	return 0;
}
