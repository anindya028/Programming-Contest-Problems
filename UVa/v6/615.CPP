#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 1<<29
int main()
{
	int mat[105][105],c[105][105],node[105],i,j,k,e,n,cs=0,p,q,found,root,flag;
	while(scanf("%d%d",&j,&k)==2)
	{
		if(j==-1 && k==-1)
			break;
		for(i=0;i<102;i++)
			for(e=0;e<102;e++)
			{
				mat[i][e]=inf;
				c[i][e]=0;
			}
		e=n=0;
		while(j && k)
		{
			e++;
			found=0;
			for(i=0;i<n;i++)
				if(node[i]==j)
				{
					p=i;
					found=1;
					break;
				}
			if(!found)
			{
				p=n;
				node[n]=j;
				n++;
			}
			found=0;
			for(i=0;i<n;i++)
				if(node[i]==k)
				{
					q=i;
					found=1;
					break;
				}
			if(!found)
			{
				q=n;
				node[n]=k;
				n++;
			}
			if(mat[p][q]==inf)
			{
				mat[p][q]=1;
				c[p][q]++;
			}
			else
				c[p][q]++;
			scanf("%d%d",&j,&k);
		}
		if(!e)
		{
			printf("Case %d is a tree.\n",++cs);
			continue;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if((mat[i][k]+mat[k][j])<inf)
					{
						c[i][j]++;
						if(mat[i][k]+mat[k][j]<mat[i][j])
							mat[i][j]=mat[i][k]+mat[k][j];
					}
		found=0;
		for(i=0;i<n;i++)
		{
			flag=1;
			for(j=0;j<n;j++)
				if(c[j][i])
					flag=0;
			if(flag)
			{
				found=1;
				root=i;
				break;
			}
		}
		if(!found)
		{
			printf("Case %d is not a tree.\n",++cs);
			continue;
		}
		flag=1;
		for(i=0;i<n;i++)
			if(c[root][i]!=1 && i!=root)
				flag=0;
		if(!flag)
			printf("Case %d is not a tree.\n",++cs);
		else
			printf("Case %d is a tree.\n",++cs);
	}
	return 0;
}













