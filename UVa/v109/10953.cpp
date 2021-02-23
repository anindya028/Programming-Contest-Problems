#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

double p[10],dp[60][15];
char s[55];
int r;

double make(int pos,int now)
{
	if(!s[pos])
	{
		if(now==r)
			return 1.;
		return 0.;
	}
	
	if(dp[pos][now]>-1)
		return dp[pos][now];
	dp[pos][now]=0.;

	int i;
	if(s[pos]!='*')
		dp[pos][now]=make(pos+1,(now*10+s[pos]-'0')%11);
	else
		for(i=0;i<10;i++)
			dp[pos][now]+= p[i]*make(pos+1,(now*10+i)%11);
	
	return dp[pos][now];
}

int main()
{
	int n,q,i,j,cs=0;
	double k;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%lf",&j,&k),p[j]=k;
		scanf("%d",&q);
		printf("Case %d:\n",++cs);
		while(q--)
		{
			scanf("%s%d",s,&r);
			for(i=0;s[i];i++)
				for(j=0;j<14;j++)
					dp[i][j]=-1;
			printf("%.8lf\n",make(0,0));
		}
	}
	return 0;
}