#include<stdio.h>
#include<algorithm>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))

int n,mat[20][20];

int make(int row,int parity,int prev)
{
	if(row==n)
	{
		if(!parity)
			return 0;
		return -1;
	}
	int i,now=0,v=0;
	for(i=0;i<n;i++)
		if(parity & (1<<i))
		{
			if(!mat[row][i])
				now|=(1<<i),v++;
			else
				return -1;
		}
	for(i=0;i<n;i++)
		if(mat[row][i])
			now|=(1<<i);
	int next=0;
	for(i=0;i<n;i++)
	{
		int cnt=0;
		if(prev & (1<<i) )
			cnt++;
		if(i)
			if(now & (1<<(i-1)))
				cnt++;
		if(now & (1<<(i+1)))
			cnt++;
		if(mat[row+1][i])
			cnt++;
		if(cnt%2)
			next+=(1<<i);
	}
	i=make(row+1,next,now);
	if(i==-1)
		return -1;
	return i+v;
}

int main()
{
	int i,j,t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		memset(mat,0,sizeof(mat));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&mat[i][j]);
		int ans=-1;
		for(i=0;i<(1<<n);i++)
		{
			int v=0;
			for(j=0;j<n;j++)
				if(i & (1<<j))
				{
					if(!mat[0][j])
						v++;
				}
				else if(mat[0][j])
					v=-10000;
			if(v<0)
				continue;
			int next=0;
			for(j=0;j<n;j++)
			{
				int cnt=0;
				if(j)
					if(i & (1<<(j-1)))
						cnt++;
				if(i & (1<<(j+1)))
					cnt++;
				if(mat[1][j])
					cnt++;
				if(cnt%2)
					next|=(1<<j);
			}
			j=make(1,next,i);
			if(j==-1)
				continue;
			if(ans==-1)
				ans=v+j;
			else
				ans=Min(ans,v+j);
		}
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}