#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
#define inf 1<<28

struct word
{
	char s[15];
	int len;
}w[205];
int adj[205][205];

int comp(char a[],char b[])
{
	int i,cnt=0;
	for(i=0;a[i];i++)
		if(a[i]!=b[i])
			cnt++;
	if(cnt<2)return cnt;
	else return inf;
}

int main()
{
	int t,n,cs,u,v;
	register int i,j,k;
	char a[15],b[15],str[100];
	gets(str);
	sscanf(str,"%d",&t);
	gets(str);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		n=0;
		for(i=0;i<203;i++)
		{
			for(j=0;j<203;j++)
				adj[i][j]=inf;
			adj[i][i]=0;
		}
		while(gets(str) && str[0]!='*' && sscanf(str,"%s",w[n].s)==1)
		{
			w[n].len=strlen(w[n].s);
			n++;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(w[i].len==w[j].len)
					adj[i][j]=adj[j][i]=comp(w[i].s,w[j].s);

		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(adj[i][k]+adj[k][j]<adj[i][j])
						adj[i][j]=adj[i][k]+adj[k][j];
		while(gets(str))
		{
			if(strlen(str)==0)
				break;
			sscanf(str,"%s%s",a,b);
			for(i=0;i<n;i++)
				if(!strcmp(w[i].s,a))
				{
					u=i;
					break;
				}
			for(i=0;i<n;i++)
				if(!strcmp(w[i].s,b))
				{
					v=i;
					break;
				}

			printf("%s %s %d\n",a,b,adj[u][v]);
		}
	}
	return 0;
}
