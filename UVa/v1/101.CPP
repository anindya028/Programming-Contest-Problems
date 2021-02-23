#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int is[30],n;
vector<int> pile[30];

void func1(int a,int b)
{
	int i,j,u,v;
	for(i=0;pile[is[a]][i]!=a;i++);
	j=pile[is[a]].size()-1;
	while(j>i)
	{
		is[pile[is[a]][j]]=pile[is[a]][j];
		pile[pile[is[a]][j]].pb(pile[is[a]][j]);
		j--;
		pile[is[a]].pop_back();
	}
	for(u=0;pile[is[b]][u]!=b;u++);
	v=pile[is[b]].size()-1;
	while(v>u)
	{
		is[pile[is[b]][v]]=pile[is[b]][v];
		pile[pile[is[b]][v]].pb(pile[is[b]][v]);
		v--;
		pile[is[b]].pop_back();
	}
	pile[is[a]].pop_back();
	is[a]=is[b];
	pile[is[b]].pb(a);
	return;
}

void func2(int a,int b)
{
	int i,j,u,v;
	for(i=0;pile[is[a]][i]!=a;i++);
	j=pile[is[a]].size()-1;
	while(j>i)
	{
		is[pile[is[a]][j]]=pile[is[a]][j];
		pile[pile[is[a]][j]].pb(pile[is[a]][j]);
		j--;
		pile[is[a]].pop_back();
	}
	pile[is[a]].pop_back();
	is[a]=is[b];
	pile[is[b]].pb(a);
	return;
}

void func3(int a,int b)
{
	int i,j,u,v,k=is[a];
	for(u=0;pile[is[b]][u]!=b;u++);
	v=pile[is[b]].size()-1;
	while(v>u)
	{
		is[pile[is[b]][v]]=pile[is[b]][v];
		pile[pile[is[b]][v]].pb(pile[is[b]][v]);
		v--;
		pile[is[b]].pop_back();
	}
	for(i=0;pile[k][i]!=a;i++);
	for(j=i;j<pile[k].size();j++)
	{
		is[pile[k][j]]=is[b];
		pile[is[b]].pb(pile[k][j]);
	}
	j--;
	while(j>=i)
		pile[k].pop_back(),j--;
	return;
}

void func4(int a,int b)
{
	int i,j,u,v,k=is[a];
	for(i=0;pile[k][i]!=a;i++);
	for(j=i;j<pile[k].size();j++)
	{
		is[pile[k][j]]=is[b];
		pile[is[b]].pb(pile[k][j]);
	}
	j--;
	while(j>=i)
		pile[k].pop_back(),j--;
	return;
}

int main()
{
	int i,a,b,j;
	char s[50],s1[50],s2[50];
	while(gets(s) && sscanf(s,"%d",&n)==1)
	{
		Foro(i,n)
			is[i]=i,pile[i].clear(),pile[i].pb(i);

		while(gets(s) && strcmp(s,"quit"))
		{
			sscanf(s,"%s%d%s%d",s1,&a,s2,&b);
			if(a==b || is[a]==is[b])
				continue;
			if(!strcmp(s1,"move") && !strcmp(s2,"onto"))
				func1(a,b);
			else if(!strcmp(s1,"move") && !strcmp(s2,"over"))
				func2(a,b);
			else if(!strcmp(s1,"pile") && !strcmp(s2,"onto"))
				func3(a,b);
			else 
				func4(a,b);
		}
		Foro(i,n)
		{
			printf("%d:",i);
			Forc(j,pile[i])
				printf(" %d",pile[i][j]);
			printf("\n");
		}
	}
	return 0;
}

