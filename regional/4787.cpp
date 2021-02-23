#include <cstdlib>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define LL long long
#define maxs 2009
set<int> sx,sy;
map<int,int> mpx,mpy;
char grid[maxs][maxs],vis[maxs][maxs];

struct bb
{
    int x1,x2,y1,y2;
}box[maxs];

int m,n,cs;

void dfs(int x,int y)
{
    if(x<0 || y<0)
        return;
    if(vis[y][x]==cs || grid[y][x]==cs)
        return;

    vis[y][x]=cs;

    dfs(x-1,y);
    dfs(x,y-1);
}

int main()
{
    int i,w,j;
	cs=0;
    while(scanf("%d%d%d",&m,&n,&w)==3)
    {
        if(!m || !n)
            break;

		swap(m,n);
		++cs;

		assert(cs<120);

        sx.clear();
        sy.clear();

        sx.insert(0);
        sx.insert(m-1);
		sx.insert(m);

        sy.insert(0);
        sy.insert(n-1);
		sy.insert(n);

        LL block=0;
        for(i=0;i<w;i++)
        {
            scanf("%d%d%d%d",&box[i].x1,&box[i].y1,&box[i].x2,&box[i].y2);

            block += (box[i].x2-box[i].x1+1);

            sx.insert(box[i].x1);
            sx.insert(box[i].x2+1);

            sy.insert(box[i].y1);
			sy.insert(box[i].y2+1);
        }

        vector<int> xx(sx.begin(),sx.end());
        vector<int> yy(sy.begin(),sy.end());

		mpx.clear();
		mpy.clear();

        for(i=0;i<xx.size();i++)
            mpx[xx[i]] = i;

        for(i=0;i<yy.size();i++)
            mpy[yy[i]] = i;
        
        for(i=0;i<w;i++)
        {
            int markx1 = mpx[box[i].x1];
			int markx2 = mpx[box[i].x2+1];
            
            int marky = mpy[box[i].y1];
    
            for(j=markx1;j<markx2;j++)
                grid[marky][j]=cs;
        }

		dfs(xx.size()-2,yy.size()-2);

        LL ans=m,nowx,nowy;
        ans*=n;
        ans-=block;

        for(i=0;i<xx.size()-1;i++)
        {
            nowx = xx[i+1] - xx[i];
            for(j=0;j<yy.size()-1;j++)
            {
                nowy = yy[j+1] - yy[j];
                if(vis[j][i]==cs)
                    ans-=(nowx*nowy);
            }
        }

        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}

