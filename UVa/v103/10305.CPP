//Topological sorting
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

enum{WHITE=0,GREY,BLACK};
#define size 105
struct node
{
	int d,f,col,no;
}ver[size];
int tim;
bool adj[size][size];

void DFS_VISIT(int root,int n)
{
	int i;
	ver[root].col=GREY;
	ver[root].d=++tim;
	for(i=0;i<n;i++)
		if(adj[root][i] && ver[i].col==WHITE)
			DFS_VISIT(i,n);
	ver[root].f=++tim;
	ver[root].col=BLACK;
	return;
}

void DFS(int n)
{
	int i;
	for(i=0;i<n;i++)
		ver[i].col=WHITE;
	for(i=0;i<n;i++)
		if(ver[i].col==WHITE)
			DFS_VISIT(i,n);
	return;
}

bool operator<(node a,node b)
{
	return a.f>b.f;
}

int main()
{
	int n,m,i,j,u,v;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				adj[i][j]=false;
			ver[i].no=i+1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			adj[u-1][v-1]=true;
		}
		tim=0;
		DFS(n);
		sort(ver,ver+n);
		printf("%d",ver[0].no);
		for(i=1;i<n;i++)
			printf(" %d",ver[i].no);
		printf("\n");
	}
	return 0;
}

