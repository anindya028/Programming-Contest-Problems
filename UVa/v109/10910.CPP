#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int p;
int c[71][71][71];
int count(int n,int t)
{
	int i,k=0;
	if(c[n][t][p])
		return c[n][t][p]; 
	if(n==1)
	{
		c[n][t][p]=1;
		return 1;
	}
	for(i=p;i<=(t-(n-1)*p);i++)
	{
		if(c[n-1][t-i][p])
			k+=c[n-1][t-i][p];
		else k+=count(n-1,t-i);
	}
	c[n][t][p]=k;
	return k;
}
int main()
{
	int n,t,cs,i;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d%d%d",&n,&t,&p);
		printf("%d\n",count(n,t));
	}
	return 0;
}













