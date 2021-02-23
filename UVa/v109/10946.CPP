#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

char s[60][60];
int x,y,freq;
char d;
struct ans
{
	char c;
	int f;
}a[3000];
void dfs(int r,int c)
{
	if(r>0)
		if(s[r-1][c]==d)
		{
			s[r-1][c]='*';
			freq++;
			dfs(r-1,c);
		}
	if(r<(x-1))
		if(s[r+1][c]==d)
		{
			s[r+1][c]='*';
			freq++;
			dfs(r+1,c);
		}
	if(c>0)
		if(s[r][c-1]==d)
		{
			s[r][c-1]='*';
			freq++;
			dfs(r,c-1);
		}
	if(c<(y-1))
		if(s[r][c+1]==d)
		{
			s[r][c+1]='*';
			freq++;
			dfs(r,c+1);
		}
	return;
}
bool operator<(ans p,ans q)
{
	if(p.f==q.f)
		return p.c<q.c;
	return p.f>q.f;
}

int main()
{
	int i,cnt,cs=0,j;
	while(scanf("%d%d",&x,&y)==2)
	{
		if(!x && !y)break;
		for(i=0;i<x;i++)
			scanf("%s",s[i]);
		for(i=cnt=0;i<x;i++)
			for(j=0;j<y;j++)
				if(s[i][j]!='.' && s[i][j]!='*')
				{
					freq=1;
					d=s[i][j];
					s[i][j]='*';
					dfs(i,j);
					a[cnt].f=freq;
					a[cnt].c=d;
					cnt++;
				}
		sort(a,a+cnt);
		printf("Problem %d:\n",++cs);
		for(i=0;i<cnt;i++)
			printf("%c %d\n",a[i].c,a[i].f);
	}
	return 0;
}













