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
#define LL long long
typedef pair<int,int> pii;

multiset<int> now;

int main()
{
	multiset<int>::iterator it;
	int n,i,k,j,m;
	while(scanf("%d",&n)==1 && n)
	{
		now.clear();
		LL ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
				scanf("%d",&k),now.insert(k);
			int u,v;
			it=now.begin();
			u=*it;
			now.erase(it);
			it=now.end();
			it--;
			v=*it;
			now.erase(it);
			ans+=(v-u);
		}
		printf("%lld\n",ans);
	}
	return 0;
}