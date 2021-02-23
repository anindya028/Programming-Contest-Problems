#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define eps 1e-10
#define pye 2*acos(0.0)
int main()
{
	int n,i,j,k;
	double ar1,ar2,x[100],y[100],t[100],r,th,ar;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
                ar=0;
		for(j=0;j<n;j++)
		{
			scanf("%lf",&t[j]);
                        ar1=0;
			for(i=0;;i++)
			{
				scanf("%lf%lf",&x[i],&y[i]);
				if(i)
				{
					if(fabs(x[0]-x[i])<eps && fabs(y[0]-y[i])<eps)break;
				}
			}
			for(k=0;k<i;k++)
			{
				ar1+=(x[k]*y[k+1]);
			}
			for(k=1;k<=i;k++)
			{
				ar1-=(x[k]*y[k-1]);
			}
			ar1=fabs(ar1);
			ar1*=t[j];
                        ar+=ar1;
		}
		scanf("%lf%lf",&r,&th);
		ar2=pye*r*r*th*2;
		printf("%.0lf\n",floor((ar/ar2)+eps));
	}
	return 0;
}













