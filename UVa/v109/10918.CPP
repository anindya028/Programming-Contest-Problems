#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

int ans[50];

int main()
{
	ans[0]=1;
	ans[2]=3;
	int i,n,j;
	for(i=4;i<=30;i+=2)
	{
		ans[i]+=3*ans[i-2];
		for(j=4;j<=i;j+=2)
			ans[i]+=2*ans[i-j];
	}
	while(scanf("%d",&n)==1)
	{
		if(n==-1)
			break;
		printf("%d\n",ans[n]);
	}
	return 0;
}

