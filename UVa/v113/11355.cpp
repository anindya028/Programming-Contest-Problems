#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define pye 2.*acos(0.0)
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))

struct point
{
	double x,y;
}p1,p2;

double getangle(double dx,double dy)
{
	if(Z(dx))
		return (dy>0?pye/2:3.*pye/2);
	if(Z(dy))
		return (dx>0?0.:pye);
	if(dy<0)
		return atan2(dy,dx)+2*pye;
	return atan2(dy,dx);
}

vector< pair<double,double> > seg,ans;

int main()
{
	int t,cs,i,n;
	double r,tot;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%lf",&n,&r);
		if(!n)
		{
			printf("Case %d: %.2lf%%\n",cs+1,100.0);
			continue;
		}
		seg.clear();
		ans.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
			double st,nd;
			st=getangle(p1.x,p1.y);
			nd=getangle(p2.x,p2.y);
			if(nd<st)
				swap(st,nd);
			if(nd-st>pye)
			{
				seg.push_back(make_pair(0,st));
				seg.push_back(make_pair(nd,2*pye));
			}
			else
				seg.push_back(make_pair(st,nd));
		}
		sort(seg.begin(),seg.end());
		ans.push_back(seg[0]);
		int j=0;
		for(i=1;i<seg.size();i++)
		{
			if(seg[i].second<ans[j].second || E(seg[i].second,ans[j].second))
				continue;
			if(seg[i].first<ans[j].second || E(seg[i].first,ans[j].second))
				ans[j].second=seg[i].second;
			else
				j++,ans.push_back(seg[i]);
		}
		tot=0.0;
		for(i=0;i<ans.size();i++)
			tot+=(ans[i].second-ans[i].first);
		tot=(2*pye-tot)/(2*pye);
		printf("Case %d: %.2lf%%\n",cs+1,tot*100.0);
	}
	return 0;
}