#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define  max(a,b) ((a>b)?(a):(b))
struct Node
{
	int x,y;
}node[205];
double cost(int i,int j)
{
	return sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
}
int main()
{
	double mat[205][205];
	int n,cs=0;
	register int i,j,k;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			scanf("%d%d",&node[i].x,&node[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=mat[j][i]=cost(i,j);
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					if(max(mat[i][k],mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=max(mat[i][k],mat[k][j]);
				}
		printf("Scenario #%d\n",++cs);
		printf("Frog Distance = %.3lf\n\n",mat[0][1]);
	}
	return 0;
}













