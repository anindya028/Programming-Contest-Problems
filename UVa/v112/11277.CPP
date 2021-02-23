#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define pye 2*acos(0.0)
#define myabs(a) (((a)>0)?(a):-(a))
#define eps 1e-9
double l[100];
int n;

double triarea(double a,double b,double c)
{
	double s=(a+b+c)/2.;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

double sumup(double r)
{
	double sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(l[i]>2*r)return 4*pye;
		sum+=acos(1-(l[i]*l[i])/(2*r*r));
	}
	return sum;
}

double binsearch(void)
{
	double low=eps,high=pow(10,12),mid,s;
	while((high-low)>eps)
	{
		mid=(low+high)/2.;
		s=sumup(mid);
		if(myabs(s-2*pye)<eps)return mid;
		else if(s<2*pye)high=mid;
		else low=mid;
	}
	s=sumup(mid);
	if((s-2*pye)<1e-6)return mid;
	else return -1.;
}

int main()
{
	int t,i;
	double s,r,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&l[i]);
			if(l[i]>max)
				max=l[i];
			s+=l[i];
		}
		if((s-max)<(max+eps))
		{
			printf("0.000\n");
			continue;
		}
		r=binsearch();
		if(r<0)
		{
			printf("0.000\n");
			continue;
		}
		s=0;
		for(i=0;i<n;i++)
			s+=triarea(r,r,l[i]);
		printf("%.3lf\n",s);
	}
	return 0;
}
