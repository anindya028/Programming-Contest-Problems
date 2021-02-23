#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

vector<double> g;

double triarea(double a,double b,double c)
{
	double s;
	if(a+b>c && b+c>a && c+a>b)
	{
		s=(a+b+c)/2.;
		return sqrt(s*(s-a))*sqrt((s-b)*(s-c));
	}
	else
		return 0.;
}

int main()
{
	int n,t,i;
	scanf("%d",&t);
	double h,ans;
	while(t--)
	{
		scanf("%d",&n);
		g.clear();
		for(i=0;i<n;i++)
			scanf("%lf",&h),g.push_back(h);
		sort(g.begin(),g.end());
		reverse(g.begin(),g.end());
		ans=-1.;
		for(i=0;i+2<n;i++)
			ans=Max(ans,triarea(g[i],g[i+1],g[i+2]));
		printf("%.2lf\n",ans);
	}
	return 0;
}