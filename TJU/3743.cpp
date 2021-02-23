#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))

typedef pair<int,int> pii;

vector<pii> vp,vp1;

int main()
{
	int n,cs=0,i,r,c,j;
	while(scanf("%d",&n)==1 && n)
	{
		if(cs)
			printf("\n");
		cs++;

		vp.clear(),vp1.clear();
		for(i=0;i<n;i++)
			scanf("%d%d",&r,&c),vp.push_back(make_pair(r,c));
		printf("Case %d:\n",cs);
		vp1=vp;
		sort(vp1.begin(),vp1.end());

		for(i=0;i<vp.size();i++)
		{
			int got=0;
			for(j=0;j<vp1.size();j++)
				if(vp1[j].first>vp[i].first && vp1[j].second>vp[i].second)
				{
					printf("%d %d\n",vp1[j].first,vp1[j].second);
					got=1;
					break;
				}
			if(!got)
				printf("-1 -1\n");
		}
		
	}
	return 0;
}