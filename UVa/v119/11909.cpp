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
#define pye (2.*acos(0.0))

int main()
{
	int l,w,h,thet;
	while(scanf("%d%d%d%d",&l,&w,&h,&thet)==4)
	{
		double theta=thet;
		theta = theta*pye/180.0;
		double ans=l*h;
		if(l*tan(theta)<h+1e-9)
			ans-=(.5*l*l*tan(theta));
		
		else
		{
			theta = pye/2-theta;
			ans = .5*h*h*tan(theta);
		}
		printf("%.3lf mL\n",ans*w);
	}
	return 0;
}