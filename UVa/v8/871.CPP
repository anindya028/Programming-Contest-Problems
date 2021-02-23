#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long __int64
//#define Long long long
#define size 50

char s[size][size];
bool visited[size][size];
int cnt,row,col;

void visit(int r,int c)
{
	int i,j;
	if(r>=row || r<0 || c<0 || c>=col)
		return;
	if(visited[r][c] || s[r][c]=='0')
		return;
	if(s[r][c]=='1')
		cnt++,visited[r][c]=1;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			visit(r+i,c+j);
}

int main()
{
	int t,i,j,mx,cs;
	char line[1005];
	gets(line);
	sscanf(line,"%d",&t);
	gets(line);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		row=0;
		while(gets(line) && strlen(line)>0)
		{
			col=strlen(line);
			sscanf(line,"%s",s[row]);
			row++;
		}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				visited[i][j]=0;
		mx=0;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(s[i][j]=='1')
				{
					cnt=0;
					visit(i,j);
					if(cnt>mx)
						mx=cnt;
				}
		printf("%d\n",mx);
	}
	return 0;
}
