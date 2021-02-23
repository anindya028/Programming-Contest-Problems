#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

#define mod 1000000
int ans[105][105];

int make(int n,int k)
{
	int i;
	if(n==0 || k==1)
		return 1;
	if(k==2)
		return n+1;
	if(ans[n][k])
		return ans[n][k];
	for(i=0;i<=n;i++)
		ans[n][k]=(ans[n][k]+make(n-i,k-1))%mod;
	return ans[n][k];
}

int main()
{
	int i,j,n,k;
	for(i=1;i<103;i++)
		for(j=0;j<103;j++)
			ans[i][j]=0;
	while(scanf("%d%d",&n,&k)==2 && n && k)
		printf("%d\n",make(n,k)%mod);
	return 0;
}
