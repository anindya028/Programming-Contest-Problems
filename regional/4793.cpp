#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define mabs(a) ((a)>0?(a):-(a))

int row[4],col[4],dd[4];
int ans,m,n;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int vis[10][10],deg[10][10];

void bktk(int r,int c,int step)
{
	if(r<0 || c<0 || r>=m || c>=n)
		return;
	if(vis[r][c])
		return;

	int i,fl=1;
	for(i=0;i<4;i++)
		if(r==row[i] && c==col[i])
			if(dd[i]!=step)
				fl=0;

	if(!fl)
		return;

	if(r==row[3] && c==col[3])
	{
		ans++;
		return;
	}
	
	//opt 1
	for(i=0;i<4;i++)
	{
		if(vis[row[i]][col[i]])
			continue;
		int v=abs(r-row[i])+abs(c-col[i]);
		if(v+step>dd[i])
		{
			fl=0;
			break;
		}
	}

	if(!fl)
		return;

	//opt 2
	if(!r || r==m-1)
		if(c && c<n-1)
			if(!vis[r][c-1] && !vis[r][c+1])
				fl=0;
	if(!c || c==n-1)
		if(r && r<m-1)
			if(!vis[r-1][c] && !vis[r+1][c])
				fl=0;
	if(!fl)
		return;	

	//opt 3
	int cnt=0;
	for(i=0;i<4;i++)
		if(r+dr[i]>=0 && c+dc[i]>=0 && r+dr[i]<m && c+dc[i]<n)
		{
			deg[r+dr[i]][c+dc[i]]++;
			if(deg[r+dr[i]][c+dc[i]]>=3 && !vis[r+dr[i]][c+dc[i]])
				cnt++;
		}
		
	if(cnt>1)
		goto done;

	vis[r][c]=1;

	for(i=0;i<4;i++)
		bktk(r+dr[i],c+dc[i],step+1);

	vis[r][c]=0;

done:;
	for(i=0;i<4;i++)
		if(r+dr[i]>=0 && c+dc[i]>=0 && r+dr[i]<m && c+dc[i]<n)
			deg[r+dr[i]][c+dc[i]]--;
}

int main()
{
	int cs=0,i;
	while(scanf("%d%d",&m,&n)==2)
	{
		if(!m && !n)
			break;
		for(i=0;i<3;i++)
			scanf("%d%d",&row[i],&col[i]),dd[i]=((i+1)*m*n)/4;
		row[i]=0,col[i]=1,dd[i]=((i+1)*m*n)/4;
		
		ans=0;
		bktk(0,0,1);

		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}