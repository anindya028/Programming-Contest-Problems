//FW + path print
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define inf 1000000

int main()
{
	char s[30][100],a[100],b[100];
	register int i,j,k;
	int mat[30][30],m,q,n,u,v,t,cur[30],parent[30][30],T,cs;
	scanf("%d",&T);
	for(cs=0;cs<T;cs++)
	{
		if(cs)
			printf("\n");

		scanf("%d%d",&m,&q);
		for(i=0;i<30;i++)
			for(j=0;j<30;j++)
			{
				mat[i][j]=inf;
				parent[i][j]=-1;
			}
		
		for(i=n=0;i<m;i++)
		{
			scanf("%s%s",a,b);
			u=-1;
			for(j=0;j<n;j++)
			{
				if(!strcmp(a,s[j]))
				{
					u=j;
					break;
				}
			}
			if(u==-1)
			{
				u=n;
				strcpy(s[n],a);
				n++;
			}
			v=-1;
			for(j=0;j<n;j++)
			{
				if(!strcmp(b,s[j]))
				{
					v=j;
					break;
				}
			}
			if(v==-1)
			{
				v=n;
				strcpy(s[n],b);
				n++;
			}
			mat[u][v]=mat[v][u]=1;
			parent[u][v]=u;
			parent[v][u]=v;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(mat[i][k]+mat[k][j]<mat[i][j])
					{
						mat[i][j]=mat[i][k]+mat[k][j];
						parent[i][j]=parent[k][j];
					}
		for(k=0;k<q;k++)
		{
			scanf("%s%s",a,b);
			u=-1;
			for(j=0;j<n;j++)
			{
				if(!strcmp(a,s[j]))
				{
					u=j;
					break;
				}
			}
			v=-1;
			for(j=0;j<n;j++)
			{
				if(!strcmp(b,s[j]))
				{
					v=j;
					break;
				}
			}
			cur[0]=v;
			t=v;
			for(i=1;parent[u][t]!=u;i++)
			{
				cur[i]=parent[u][t];
				t=parent[u][t];
			}
			cur[i]=u;
			for(j=i;j>=0;j--)
				printf("%c",s[cur[j]][0]);
			printf("\n");
		}
	}
	return 0;
}

