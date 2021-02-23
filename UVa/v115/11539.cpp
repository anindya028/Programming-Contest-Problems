#include<stdio.h>

#define inf 1<<29
#define Max(a,b) (((a)>(b))?(a):(b))

struct node
{
	int val;

	node *next[26];

	node()
	{
		int i;
		val=-1;
		for(i=0;i<26;i++)
			next[i]=NULL;
	}
	~node()
	{
		int i;
		for(i=0;i<26;i++)
			delete next[i];
	}
};

node *root;
char s[10005];
int w,n,p,mx;

void trie_add(node *now,int pos)
{
	if(!s[pos])
	{
		mx=Max(mx,pos);
		now->val=w;
		return;
	}

	int v=s[pos]-'a';
	if(!now->next[v])
		now->next[v]=new node();

	trie_add(now->next[v],pos+1);
}

int dp[10005];

int make(int pos)
{
	if(!s[pos])
		return 0;
	if(dp[pos]!=-inf)
		return dp[pos];
	
	dp[pos]=-p+make(pos+1);

	node *now;
	int i,j;
	now=root;
	
	for(i=0;i<mx && s[pos+i];i++)
	{
		int v=s[pos+i]-'a';
		if(now->next[v])
		{
			if(now->next[v]->val!=-1) 
				j=now->next[v]->val+make(pos+i+1),
				dp[pos]=Max(dp[pos],j);
			now=now->next[v];
		}
		else
			break;
	}
	return dp[pos];
}
	
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d%d",&n,&p);
		root=new node();
		for(i=0;i<n;i++)
		{
			scanf("%s%d",s,&w);
			trie_add(root,0);
		}
		scanf("%s",s);
		for(i=0;s[i];i++)
			dp[i]=-inf;
		printf("Case %d: %d\n",j+1,make(0));
	}
	return 0;
}