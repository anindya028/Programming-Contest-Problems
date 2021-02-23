#include<stdio.h>
#include<string.h>

#define Max(a,b) (((a)>(b))?(a):(b))

char s[500];
int ans;

struct node
{
	int frq;
	node *next[2];
	
	node(){
		frq = 0;
		next[0] = next[1] = NULL;
	}
	~node(){
		delete next[0];
		delete next[1];
	}
};

node *root;

void trie_add(node *now,int pos)
{
	now->frq++;
	ans=Max(ans,now->frq*pos);

	if(!s[pos])
		return;
	int v=s[pos]-'0';

	if(!now->next[v])
		now->next[v]=new node();

	trie_add(now->next[v],pos+1);
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		root= new node();
		for(i=0;i<n;i++)
			scanf("%s",s),trie_add(root,0);
		printf("%d\n",ans);
	}
	return 0;
}
