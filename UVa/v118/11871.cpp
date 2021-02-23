#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>

using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define pii pair<int,int>

char mat[2005][2005];
int cum[2005][2005];

stack< pii > s;

int main()
{
	int i, j, k, u, v, r, c, t, cs, w;
	scanf("%d",&t);
	for(cs = 0; cs<t;cs++)
	{
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
		{
			scanf("%d%d",&k,&u);
			v = 0;
			for(j=0;j<k;j++)
			{
				scanf("%d",&w);
				while(w--)
					mat[i][v] = u, v++;
				u = 1 - u;
			}
		}
		for(i=0;i<c;i++)
		{
			cum[r-1][i] = 1 - mat[r-1][i];
			for(j=r-2;j>=0;j--)
				cum[j][i] = cum[j+1][i]*(1 - mat[j][i]) + (1 - mat[j][i]);
		}

		int max_area = 0;
		for(k = 0; k < r; k++)
		{
			for(i=0;i<c;i++)
			{
				if(s.empty())
				{
					s.push(make_pair(i,0));
					continue;
				}
				pair<int,int> now = s.top(); // now.first = index of this element, 
											//	now.second = how far we can go to left with this element's height
				int cur_width = 0;			//  how far current height can be extended to left	
				while(cum[k][now.first] > cum[k][i])
				{
					max_area = Max(max_area,cum[k][now.first]*(now.second + i - now.first));
					cur_width += (now.second + 1);
					s.pop();
					if(s.empty())break;
					now = s.top();
				}
				s.push(make_pair(i,cur_width));
			}
			while(!s.empty())
			{
				pair<int,int> now = s.top();
				max_area = Max(max_area,cum[k][now.first]*(now.second + c - now.first));
				s.pop();
			}
		}
		printf("Case %d: %d\n", cs+1, max_area);
	}
	return 0;
}