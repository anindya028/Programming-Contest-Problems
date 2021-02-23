#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int h[250005],pr[250005],cum[250005];
bool p[250005];
int gene(void)
{
	int i,j;
	h[0]=1;
	for(i=1;i<250003;i++)
		h[i]=4*i+1;
	for(i=1;i<503;i++)
		if(!p[i])
			for(j=h[i]*h[i];j<1000003;j+=4*h[i])
				p[j/4]=1;
	p[0]=1;
	for(j=i=0;i<250003;i++)
		if(!p[i])
		{
			pr[j]=h[i];
			j++;
		}
	return j;
}
int main()
{
	int n,m,i,j;
	m=gene();
	cum[0]=0;
	for(j=1;j<250003;j++)
	{
		if(!p[j])
		{
			cum[j]=cum[j-1];
			continue;
		}
		for(i=0;i<m;i++)
			if(h[j]%pr[i]==0)
			{
				if(!p[(h[j]/pr[i])/4])
					cum[j]=cum[j-1]+1;
				else cum[j]=cum[j-1];
				break;
			}
	}
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("%d %d\n",n,cum[n/4]);
	}
	return 0;
}













