#include<stdio.h>
#include<algorithm>
#include<string>
#include<set>
#include<vector>

using namespace std;

char a[2][1505][20];
int ans;

struct node
{
	int val;
	node *next[26];

	node()
	{
		int i;
		val=0;
		for(i=0;i<26;i++)
			next[i]=NULL;
	}
	~node()
	{
		int i;
		for(i=0;i<26;i++)
			delete next[i];
	}
}*root;

int k[2];

void update(node *now,int pos,int is)
{
	if(!a[is][k[is]][pos] && !is)
		is++,pos=0;

	if(!a[is][k[is]][pos] && is)
	{
		if(!now->val)
			ans++;
		now->val=1;
		return;
	}
	
	int v=a[is][k[is]][pos]-'a';
	if(!now->next[v])
		now->next[v]=new node();

	update(now->next[v],pos+1,is);
}

int main()
{
	int n,m,i,j,t,cs;
	char s[20];
	
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=0;cs<t;cs++)
	{
		gets(s);
		sscanf(s,"%d%d",&n,&m);

		for(i=0;i<n;i++)
			gets(a[0][i]);

		for(i=0;i<m;i++)
			gets(a[1][i]);
		
		root=new node();
		for(i=ans=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				k[0]=i,k[1]=j;
				update(root,0,0);
			}
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}