#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> idx[1000005];
int is[1000005];

int main()
{
	int i,n,m,v,k,cs=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		cs++;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v);
			if(is[v]!=cs)
				idx[v].clear();
			idx[v].push_back(i);
			is[v] = cs;
		}

		for(i=0;i<m;i++)
		{
			scanf("%d%d",&k,&v);
			if(is[v]!=cs || k>idx[v].size())
				printf("0\n");
			else
				printf("%d\n",idx[v][k-1]);
		}
	}
	return 0;
}