#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
#define LL long long
LL modp;

struct pll
{
	LL fir,sec;
	pll(){fir=0,sec=0;}
	pll(LL _fir,LL _sec){fir=_fir,sec=_sec;}
	void print()
	{
		if(!fir)
			printf("%lld\n",sec);
		else
			printf("%lld%.16lld\n",fir,sec);
	}
}two[70];

pll operator+(pll a,pll b)
{
	return pll((a.sec+b.sec)/modp+a.fir+b.fir,(a.sec+b.sec)%modp);
}

pll operator-(pll a,pll b)
{
	pll ret;
	ret.sec=a.sec-b.sec;
	ret.fir=a.fir-b.fir;
	if(ret.sec<0)
		ret.sec+=modp,ret.fir-=1;
	return ret;
}

pll operator*(pll a,LL b)
{
	return pll(a.fir*b+(a.sec*b)/modp,(a.sec*b)%modp);
}

int m;

struct node
{
	pll val;
	node *next[2];
	int done;
	node()
	{
		int i;
		val = pll(0,0);
		done=0;
		for(i=0;i<2;i++)
			next[i]=NULL;
	}
	~node()
	{
		int i;
		for(i=0;i<2;i++)
			delete next[i];
	}
};

node *root;
struct str
{
	char pref[80];
	int len;
}g[20005];

bool operator<(str a,str b)
{
	return a.len>b.len;
}

pll trie_add(node *now,int id,int pos)
{
	int i;
	if(g[id].pref[pos]=='*')
	{
		if(now->done)
			return pll(0,0);
		now->done=1;
		now->val=two[m-pos]-now->val;
		return now->val;
	}

	int v=g[id].pref[pos]-'0';
	if(!now->next[v])
		now->next[v]= new node();
	pll got = trie_add(now->next[v],id,pos+1);
	now->val = now->val + got;
	return got;
}

char s[80];

void trie_visit(node *now,int pos)
{
	if(s[pos]=='*')
	{
		now->val.print();
		return;
	}

	int v=s[pos]-'0';
	trie_visit(now->next[v],pos+1);
}

int main()
{
	modp=100000000;
	modp*=modp;
	two[0]=pll(0,1);
	int i;
	for(i=1;i<=65;i++)
		two[i]=two[i-1]*2;
	
	int n,k;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		for(i=0;i<n;i++)
			scanf("%s",&g[i].pref),g[i].len=strlen(g[i].pref);
		g[n].pref[0]='*',g[n].pref[1]=0,g[n].len=1;
		n++;
		sort(g,g+n);
		root = new node();
		for(i=0;i<n;i++)
			trie_add(root,i,0);
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%s",s);
			trie_visit(root,0);
		}
		printf("\n");
	}
	return 0;
}