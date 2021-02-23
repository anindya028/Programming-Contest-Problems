#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int p,q,r,s;
	long double ans,i,j,k,l;
	while(scanf("%d%d%d%d",&p,&q,&r,&s)==4)
	{
		if(q>p/2)q=p-q;
		if(s>r/2)s=r-s;
		for(ans=1.,i=q+1.,j=k=1.,l=s+1.;i<=p||j<=(p-q)||k<=(r-s)||l<=r;i++,j++,k++,l++)
		{
			if(i<=p&&j<=(p-q)&&k<=(r-s)&&l<=r)ans=ans*i*k/(j*l);
			else if(i>p &&j<=(p-q)&&k<=(r-s)&&l<=r)ans=ans*k/(j*l);
			else if(i<=p&&j>(p-q)&&k<=(r-s)&&l<=r)ans=ans*i*k/(l);
			else if(i<=p&&j<=(p-q)&&k>(r-s)&&l<=r)ans=ans*i/(j*l);
			else if(i<=p&&j<=(p-q)&&k<=(r-s)&&l>r)ans=ans*i*k/(j);
			else if(i>p&&j>(p-q)&&k<=(r-s)&&l<=r)ans=ans*k/(l);
			else if(i>p&&j<=(p-q)&&k>(r-s)&&l<=r)ans=ans/(j*l);
			else if(i>p&&j<=(p-q)&&k<=(r-s)&&l>r)ans=ans*k/(j);
			else if(i<=p&&j>(p-q)&&k>(r-s)&&l<=r)ans=ans*i/(l);
			else if(i<=p&&j>(p-q)&&k<=(r-s)&&l>r)ans=ans*i*k;
			else if(i<=p&&j<=(p-q)&&k>(r-s)&&l>r)ans=ans*i/(j);
			else if(i>p&&j>(p-q)&&k>(r-s)&&l<=r)ans=ans/(l);
			else if(i>p&&j>(p-q)&&k<=(r-s)&&l>r)ans=ans*k;
			else if(i<=p&&j>(p-q)&&k>(r-s)&&l>r)ans=ans*i;
		}
		printf("%.5Lf\n",ans);
	}
	return 0;
}













