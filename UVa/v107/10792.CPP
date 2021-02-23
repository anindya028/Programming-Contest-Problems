#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int i,n;
	double ab,r,h1,h2,d,alpha,beta,theta;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&r,&d,&h1);
		ab=2*sqrt(2*r*d-d*d);
		alpha=asin((r-h1)/r);
		beta=asin((r-d)/r);
		theta=alpha-beta;
		h2=h1+ab*sin(theta);
		printf("Case %d: %.4lf\n",i+1,h2);
	}
	return 0;
}













