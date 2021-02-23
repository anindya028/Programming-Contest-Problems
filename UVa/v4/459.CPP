#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

enum{WHITE=0,GREY,BLACK};
#define size 105
bool adj[size][size];
int col[size],ans;

void DFS_VISIT(int root,int n)
{
	int i;
	col[root]=GREY;
	for(i=0;i<n;i++)
		if(adj[root][i])
			if(col[i]==WHITE)
				DFS_VISIT(i,n);
	col[root]=BLACK;
	return;
}

void DFS(int n)
{
	int i;
	for(i=0;i<n;i++)
		col[i]=WHITE;

	for(i=0;i<n;i++)	
		if(col[i]==WHITE)
		{
			ans++;
			DFS_VISIT(i,n);
		}
	return;
}

int main()
{
	char s[1000];
	int i,n,cs,t,j;
	scanf("%d",&t);
	gets(s);
	gets(s);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		//gets(s);
		gets(s);
		n=s[0]-'A'+1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				adj[i][j]=false;
		while(gets(s))
		{
			if(s[0]=='\0')
				break;
			i=0;
			while(!isalpha(s[i]))
				i++;
			j=i+1;
			while(!isalpha(s[j]))
				j++;
			adj[s[i]-'A'][s[j]-'A']=true;
			adj[s[j]-'A'][s[i]-'A']=true;
		}
		ans=0;
		DFS(n);
		printf("%d\n",ans);
	}
	return 0;
}

