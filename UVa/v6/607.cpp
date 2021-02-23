#include<stdio.h>
#include<string.h>

#define sq(a) ((a)*(a))
#define mem(a) memset(a,-1,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define inf 1<<29

struct memo
{
	int no,cost;
}dp[1005];

bool operator<(memo a,memo b)
{
	if(a.no==b.no)
		return a.cost<b.cost;
	return a.no<b.no;
}

int len,c,n,topic[1005];

int calc(int t)
{
	if(!t) return t;
	if(t<=10)
		return -c;
	else
		return sq(t-10);
}

memo make(int pos)
{
	memo temp;
	if(pos==n)
	{
		temp.no=0,temp.cost=0;
		return temp;
	}
	if(dp[pos].no!=-1)
		return dp[pos];
	dp[pos].no=inf;
	int i,sum=0;
	for(i=pos;i<n && sum+topic[i]<=len;i++)
		sum+=topic[i],temp=make(i+1),
		temp.cost+=calc(len-sum),temp.no++,
		dp[pos]=Min(dp[pos],temp);
	return dp[pos];
}

int main()
{
	int i,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%d%d",&len,&c);
		for(i=0;i<n;i++)
			scanf("%d",&topic[i]);
		
		for(i=0;i<n;i++)
			dp[i].no=-1;
		memo ans=make(0);
		if(cs)
			printf("\n");
		printf("Case %d:\n",++cs);
		printf("Minimum number of lectures: %d\n",ans.no);
		printf("Total dissatisfaction index: %d\n",ans.cost);
	}
	return 0;
}
