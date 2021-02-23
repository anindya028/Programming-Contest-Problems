/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define maxnode 501
#define MIN(a,b) ((a)<(b)?(a):(b))
#define inf 1000000000
int visited[maxnode],dist[maxnode],mat[maxnode][maxnode];
void dijkstra(int n,int source)
{
	int i,min,pos;
	for(i=0;i<n;i++)
	{
		dist[i]=inf;
		visited[i]=0;
	}
	dist[source]=0;
	while(1)
	{
		min=inf;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(dist[i]<min)
				{
					min=dist[i];
					pos=i;
				}
		if(min==inf)break;
		visited[pos]=1;
		for(i=0;i<n;i++)
			if(mat[pos][i]<inf)
			{
				dist[i]=MIN(dist[i],dist[pos]+mat[pos][i]);
			}
	}
	return;
}
int main()
{
	int n,r,i,j,c1,c2,cost,cs=0;
	while(scanf("%d%d",&n,&r)==2)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=inf;
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&c1,&c2,&cost);
			mat[c1][c2]=mat[c2][c1]=cost;
		}
		dijkstra(n,0);
		if(dist[n-1]>=inf)printf("Set #%d\n?\n",++cs);
		else printf("Set #%d\n%d\n",++cs,dist[n-1]);
	}
	return 0;
}
*/
#include<stdio.h>

#define INF 10000000
#define SIZE 505
#define min(a,b) (((a)<(b))?(a):(b))

enum{BACK=0,RIDE};

int d[SIZE][2],mat[SIZE][SIZE];
int n,e;
bool f[SIZE][2];

void dijkstra();

int main()
{
	int i,j,a,b,c,kase=1;
	while(scanf(" %d %d",&n,&e)==2) 
	{
		for(i=0;i<n;i++) 
			for(f[i][BACK]=f[i][RIDE] = 0,d[i][BACK]=d[i][RIDE]=INF,j=0;j<n;j++)
				mat[i][j] = INF;
		for(i=0;i<e;i++) 
			scanf(" %d %d %d",&a,&b,&c), mat[a][b] = min(mat[a][b],c), mat[b][a] = min(mat[b][a],c);
		printf("Set #%d\n",kase++);
		dijkstra();
	}
	return 0;
}

void dijkstra()
{
	int i,j,mn,posx,posy;
	d[0][RIDE] = 0;
	//f[0][RIDE] = 1;

	while(1) 
	{
		for(mn=INF,i=0;i<n;i++) 
			for(j=0;j<2;j++) 
				if(!f[i][j]) 
					if(d[i][j] < mn) 
						mn = d[i][j],posx=i,posy=j;
		if(mn == INF) break;
		f[posx][posy] = 1;
		for(i=0;i<n;i++) 
			d[i][1-posy] = min(d[i][1-posy], d[posx][posy] + mat[posx][i]);
	}

	if(d[n-1][RIDE] >= INF) printf("?\n");
	else printf("%d\n",d[n-1][RIDE]);
}