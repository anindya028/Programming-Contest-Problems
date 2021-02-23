#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct point
{
	int x,y;
}p[5005];

char is[5002][5002];
vector<int> xx,yy;
map<int,int> mpx,mpy;

int main()
{
	int t,cs=0,i,n;
	scanf("%d",&t);
	while(t--)
	{
		cs++;
		xx.clear();
		yy.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y),xx.push_back(p[i].x),yy.push_back(p[i].y);
		sort(xx.begin(),xx.end());
		sort(yy.begin(),yy.end());
		mpx.clear();
		mpy.clear();
		int j=0;
		for(i=0;i<n;i++)
			if(mpx.find(xx[i])==mpx.end())
				mpx[xx[i]]=j,j++;
		j=0;
		for(i=0;i<n;i++)
			if(mpy.find(yy[i])==mpy.end())
				mpy[yy[i]]=j,j++;
		for(i=0;i<n;i++)
			p[i].x=mpx[p[i].x],p[i].y=mpy[p[i].y],
			is[p[i].x][p[i].y]=cs;

		int cnt=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(p[i].x!=p[j].x && p[i].y!=p[j].y)
					if(is[p[i].x][p[j].y]==cs && is[p[j].x][p[i].y]==cs)
						cnt++;
		printf("Case %d: %d\n",cs,cnt/2);
	}
	return 0;
}