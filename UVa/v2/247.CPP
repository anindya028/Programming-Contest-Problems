#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;


bool mat[30][30];
bool node[30];

char g[30][100];

int main()
{
	int n,m,cs=0,i,j,u,got,v,k;
	char a[100],b[100];
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m) 
			break;
		if(cs)
			printf("\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				mat[i][j]=false;
			node[i]=false;
		}
		got=0;
		for(i=0;i<m;i++)
		{
			scanf("%s%s",a,b);
			u=-1;
			for(j=0;j<got;j++)
			{
				if(!strcmp(g[j],a))
				{
					u=j;
					break;
				}
			}
			if(u==-1)
			{
				strcpy(g[got],a);
				u=got;
				got++;
			}
			v=-1;
			for(j=0;j<got;j++)
			{
				if(!strcmp(g[j],b))
				{
					v=j;
					break;
				}
			}
			if(v==-1)
			{
				strcpy(g[got],b);
				v=got;
				got++;
			}
			mat[u][v]=true;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					mat[i][j]=mat[i][j] | (mat[i][k] & mat[k][j]);
		printf("Calling circles for data set %d:\n",++cs);
		for(i=0;i<n;i++)
			if(!node[i])
			{
				printf("%s",g[i]);
				node[i]=true;
			
				for(j=0;j<n;j++)
					if(!node[j] && mat[i][j] && mat[j][i])
					{
						printf(", %s",g[j]);
						node[j]=true;
					}
				printf("\n");
			}
	}
	return 0;
}

