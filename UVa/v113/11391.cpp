#include<stdio.h>
#include<string.h>

int dp[5][5][1<<16];
int r,c;

int dr[]={1,0,-1,1,-1,1,0,-1};
int dc[]={1,1,1,0,0,-1,-1,-1};

bool ok(int r1,int c1)
{
	return (r1>=0 && r1<r && c1>=0 && c1<c);
}

int make(int rem,int now)
{
	if(rem==1)
		return 1;
	if(dp[r][c][now]!=-1)
			return dp[r][c][now];
	dp[r][c][now]=0;
	int i,j;
	for(i=0;i<r*c;i++)
		if(now & 1<<i)
		{
			int nr=i/c,nc=i%c;
			for(j=0;j<8;j++)
				if(ok(nr+dr[j],nc+dc[j]) && ( now & 1<<( (nr+dr[j])*c + nc+dc[j] ) ) )
					if(ok(nr+2*dr[j],nc+2*dc[j]) && !( now & 1<<( (nr+2*dr[j])*c + nc+2*dc[j] ) ) )
						dp[r][c][now]+= make(rem-1,now - (1<<i) - (1<<( (nr+dr[j])*c + nc+dc[j] )) + (1<<( (nr+2*dr[j])*c + nc+2*dc[j] )) );
		}
	return dp[r][c][now];
}

int main()
{
	int t,i,now,j,k,n,cs=0;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&t);
	while(t--)
	{
		now=0;
		scanf("%d%d%d",&r,&c,&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&j,&k),j--,k--,now+=(1<<(j*c+k));
		printf("Case %d: %d\n",++cs,make(n,now));
	}
	return 0;
}