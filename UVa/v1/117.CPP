#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define size 30
#define inf 1<<29
int adj[size][size],degree[size];

void ini(void)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			adj[i][j]=inf;
		degree[i]=0;
	}
	return;
}

int main()
{
	int i,j,k,s,t,sum,flag,len,u,v;
	char p[300];
	while(1)
	{
		flag=sum=0;
		ini();
		while(scanf("%s",p)==1)
		{
			flag=1;
			if(!strcmp(p,"deadend"))
				break;
			len=strlen(p);
			u=p[0]-'a';
			v=p[len-1]-'a';
			degree[u]++;
			degree[v]++;
			adj[u][v]=adj[v][u]=len;
			sum+=len;
		}
		if(!flag)
			break;
		s=t=-1;
		for(flag=i=0;i<26;i++)
			if(degree[i]%2)
			{
				flag=1;
				if(s==-1)
					s=i;
				else if(t==-1)
					t=i;
			}
		if(!flag)
		{
			printf("%d\n",sum);
			continue;
		}
		for(k=0;k<26;k++)
			for(i=0;i<26;i++)
				for(j=0;j<26;j++)
					if(adj[i][k]+adj[k][j]<adj[i][j])
						adj[i][j]=adj[i][k]+adj[k][j];
		printf("%d\n",sum+adj[s][t]);
	}
	return 0;
}

