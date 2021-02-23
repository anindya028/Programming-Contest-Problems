#include<stdio.h>
#include<assert.h>
#include<algorithm>
#include<set>

using namespace std;

#define inf (1<<29)
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

struct pack
{
	int no,st,nd;
}p[1005];

int main()
{
	int mes[5],n,m,i,cs=0,s[5];
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		cs++;
		for(i=0;i<n;i++)
			mes[i] = i,
			scanf("%d",&s[i]);

		for(i=0;i<m;i++)
			scanf("%d%d%d",&p[i].no,&p[i].st,&p[i].nd),p[i].no--;
		
		int ans = inf;
		do
		{
			int fin = 0, last = 0;
			
			set< pair<int,int> > seg[6];
			set< pair<int,int> >::iterator it,it1;

			int cur = 0, sz = 0;
			for(i=0;i<m;i++)
			{
				//on byte
				if(p[i].no!=mes[fin])
				{
					seg[p[i].no].insert(make_pair(p[i].st,p[i].nd));
					sz += (p[i].nd - p[i].st + 1);
					cur = Max(cur,sz);
					continue;
				}

				//try to pass packet
				int f = 0;
				seg[p[i].no].insert(make_pair(p[i].st,p[i].nd));
				it = seg[mes[fin]].begin();

				while(1)
				{
					if(it == seg[mes[fin]].end())
						break;
					if(it->first>last+1)
						break;
					if(it->first == p[i].st)
						f = 1;
					else
						sz -= (it->second - it->first + 1);

					last = it->second;
					it1 = it;
					it++;

					seg[mes[fin]].erase(it1);
					
					if(last==s[mes[fin]] && (fin<n-1))
					{
						fin++;
						last = 0;
						it = seg[mes[fin]].begin();
					}
				}

				if(!f)
				{
					sz += (p[i].nd - p[i].st + 1);
					cur = Max(cur,sz);
				}
			}

			ans = Min(ans,cur);
		}while(next_permutation(mes,mes+n));

		printf("Case %d: %d\n\n",cs,ans);
	}
	return 0;
}