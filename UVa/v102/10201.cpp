#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))

struct station
{
	int d,pr;
}st[105];

int dp[205][105],dis,n;

int make(int cap,int now)
{
	int i,j;
	if(cap<0)
		return inf;
	if(dp[cap][now]!=-1)
		return dp[cap][now];
	if(dis==st[now].d)
	{
		if(cap>=100)
			return 0;
		else
			return (100-cap)*st[now].pr;
	}
	if(now==n || dis<st[now+1].d)
	{
		if((dis-st[now].d)+100<=cap)
			return 0;
		else if((dis-st[now].d)+100<=200)
			return (dis-st[now].d+100-cap)*st[now].pr;
		return inf;
	}
	
	dp[cap][now]=inf;
	for(i=0;i+cap<=200;i++)
	{
		if(i && !now)
			break;
		j=i*st[now].pr+make(cap+i-(st[now+1].d-st[now].d),now+1);
		if(j<inf && j>dp[cap][now])
			break;
		dp[cap][now]=Min(dp[cap][now],j);
	}
	return dp[cap][now];
}

int main()
{
	int ans,t,i,j,cs;
	char buf[100];
	gets(buf);
	sscanf(buf,"%d",&t);
	gets(buf);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		gets(buf);
		sscanf(buf,"%d",&dis);
		st[0].d=0;
		n=1;
		while(gets(buf) && strlen(buf)>0)
			sscanf(buf,"%d%d",&st[n].d,&st[n].pr),n++;
		n--;
		for(i=0;i<=200;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=-1;
		if(!n)
		{
			if(!dis)
				printf("0\n");
			else
				printf("Impossible\n");
			continue;
		}
		ans=make(100,0);
		if(ans==inf)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}