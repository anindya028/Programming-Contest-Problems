#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

#define SIZE 50

class edge
{
public:
	int x,y;
	int oposit(int p)
	{
		if(p==x)return y;
		return x;
	}
};

int N,M;
list<int> L[SIZE];
edge E[SIZE];

int getcnt(int node, bool s[])
{
	int max,j;
	list<int>::iterator i;
	bool s2[SIZE];

	for(j=0;j<M;j++)
		s2[j]=s[j];

	max=0;
	for(i=L[node].begin();i!=L[node].end();i++)
	{
		if(s[*i]==false)
		{
			s2[*i]=true;
			int x=1+getcnt(E[*i].oposit(node),s2);
			s2[*i]=false;

			if(x>max)
				max=x;
		}
	}
	return max;
}

int main(void)
{
	int i,p,q,j;
	while(true)
	{
		scanf("%d%d",&N,&M);
		if(N==0 && M==0)break;
		
		for(i=0;i<N;i++)L[i].clear();
		for(i=0;i<M;i++)
		{
			scanf("%d%d",&p,&q);
			E[i].x=p;
			E[i].y=q;
			L[p].push_back(i);
			L[q].push_back(i);
		}
		
		int max=-1;
		for(i=0;i<N;i++)
		{
			bool seen[SIZE];
			for(j=0;j<M;j++)
				seen[j]=false;
			int x=getcnt(i,seen);
			if(x>max)
				max=x;
		}
		printf("%d\n",max);
	}
	return 0;
}