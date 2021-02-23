#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long long long
//#define Long __int64
#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

char s[505][505];
int ans[505][505];
int row,col,tim;
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};

bool valid(int r,int c)
{
	return (r>=0 && c>=0 && r<row && c<col);
}

void dfs(int r,int c)
{
	int i;
	char f=s[r][c];
	ans[r][c]=tim;
	Foro(i,8)
		if(valid(r+dx[i],c+dy[i]) && s[r+dx[i]][c+dy[i]]==f && !ans[r+dx[i]][c+dy[i]])		
			dfs(r+dx[i],c+dy[i]);
}

int main()
{
	char buf[1005],d[10];
	bool f=true;
	int i,j,bs,dbs,spaces[505],temp,k,mk;
	while(f)
	{
		row=0;
		while(gets(buf))
		{
			if(buf[0]=='%')
				break;
			j=bs=0;
			while(sscanf(buf+bs,"%s%n",d,&dbs)==1)
				s[row][j]=d[0],j++,bs+=dbs;
			col=j;
			row++;
		}
		if(buf[0]!='%')
			f=false;
		Foro(i,row)
			Foro(j,col)
				ans[i][j]=0;
		Foro(j,col)
			spaces[j]=0;
		tim=0;
		Foro(i,row)
			Foro(j,col)
				if(!ans[i][j])
					++tim,dfs(i,j);
		Foro(i,row)
			Foro(j,col)
			{
				temp=ans[i][j];
				for(k=0;temp>0;++k) temp/=10;
				if(k>spaces[j])
				{
					spaces[j]=k;
					if(k>mk) mk=k;
				}
			}
		--spaces[0];
		Foro(i,row)
		{
			Foro(j,col)
			{
				temp=ans[i][j];
				for(k=0;temp>0;++k) temp/=10;
				for(;k<=spaces[j];++k)
				{
					printf(" ");
				}
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
		printf("%%\n");
	}
	return 0;
}
