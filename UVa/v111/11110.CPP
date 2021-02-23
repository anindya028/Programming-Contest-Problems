#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int mat[105][105],n,d;
void dfs(int r,int c)
{
	if(r>0)
		if(mat[r-1][c]==d)
		{
			mat[r-1][c]=1000;
			dfs(r-1,c);
		}
	if(r<(n-1))
		if(mat[r+1][c]==d)
		{
			mat[r+1][c]=1000;
			dfs(r+1,c);
		}
	if(c>0)
		if(mat[r][c-1]==d)
		{
			mat[r][c-1]=1000;
			dfs(r,c-1);
		}
	if(c<(n-1))
		if(mat[r][c+1]==d)
		{
			mat[r][c+1]=1000;
			dfs(r,c+1);
		}
	mat[r][c]=1000;
	return ;
}

int main()
{
	int i,j,p,q,cnt,bs,dbs,flag;
	char s[10000];
	while(gets(s))
	{
		sscanf(s,"%d",&n);
		if(!n)break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=0;
		flag=1;
		for(i=0;i<n-1;i++)
		{
			gets(s);
			bs=dbs=0;
			cnt=0;
			while(sscanf(s+bs,"%d%d%n",&p,&q,&dbs)==2)
			{
				bs+=dbs;
				cnt++;
				mat[p-1][q-1]=i+1;
			}
		}
		cnt=0;
		for(i=0;i<n && cnt<=n;i++)
			for(j=0;j<n && cnt<=n;j++)
				if(mat[i][j]!=1000)
				{
					cnt++;
					d=mat[i][j];
					mat[i][j]=1000;
					dfs(i,j);
				}
		if(cnt==n)
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 0;
}

