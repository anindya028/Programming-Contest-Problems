#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 50005

struct tripple
{
	int a,b,c;
	bool got;
}ans[size];

int main()
{
	int i,j,k,t,n;
	for(i=0;i<size;i++)
		ans[i].got=false;
	for(i=0;(3*i*i)<size;i++)
		for(j=i;(i*i+2*j*j)<size;j++)
			for(k=j;(k*k+i*i+j*j)<size;k++)
				if(!ans[k*k+i*i+j*j].got)
				{
					ans[k*k+i*i+j*j].got=true;
					ans[k*k+i*i+j*j].a=i;
					ans[k*k+i*i+j*j].b=j;
					ans[k*k+i*i+j*j].c=k;
				}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(ans[n].got)printf("%d %d %d\n",ans[n].a,ans[n].b,ans[n].c);
		else printf("-1\n");
	}
	return 0;
}

