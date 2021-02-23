#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define inf 1e9
#define eps 1e-9
#define mabs(a) ((a)>0?(a):-(a))
#define Z(a) (mabs(a)<eps)

double f(int n,double x,double *a)
{
	int i;
	double s=0;
	for(i=0;i<=n;i++)
		s+=a[i]*pow(x,i);
	return s;
}

double bisect(int n,double *a,double lm,double um,int fx)
{
	double x,y,LMT=1e-13;
	int iter=200;
	while(iter--)
	{
		x=(um+lm)/2.;
		y=f(n,x,a);
	//	if(mabs(y)<LMT || um-lm<LMT)
	//		break;
	//	else
	//	{
			if(fx==1)
			{
				if(y>LMT)
					um=x;
				else
					lm=x;
			}
			else
			{
				if(y>LMT)
					lm=x;
				else
					um=x;
			}
	//	}
	}
	return x;
}

void diff(int n,double *a,double *b)
{
	int i;
	for(i=0;i<=n;i++)
		b[i]=(i+1)*a[i+1];
	if(b[n]<0)
		for(i=0;i<=n;i++)
			b[i]=-b[i];
}

int main()
{
	int i,j,k,n,r[105],cs=0;
	double a[105][105],x[105][105],y[105],D;

	while(scanf("%d",&n)==1 && n)
	{
		for(i=n;i>=0;i--)
			scanf("%lf",&a[n][i]);
	
		printf("Equation %d:",++cs);
		if(n==1)
		{
			double v=-a[1][0]/a[1][1];
			printf(" %.4lf\n",v);
			continue;
		}

		for(i=n-1;i>=2;i--)
			diff(i,a[i+1],a[i]);
	
		D=a[2][1]*a[2][1] - 4*a[2][2]*a[2][0];
		if(D<0)
		{
			x[2][0]= -inf;
			x[2][1]= inf;
			r[2]=2;
		}
		else
		{
			x[2][0]=-inf;
			x[2][1]=(-a[2][1]-sqrt(D))/(2*a[2][2]);
			x[2][2]=(-a[2][1]+sqrt(D))/(2*a[2][2]);
			x[2][3]=inf;
			r[2]=4;
		}

		for(i=2;i<n;i++)
		{
			for(j=0;j<r[i];j++)
				y[j]=f(i+1,x[i][j],a[i+1]);
			k=0;
			x[i+1][k++]=-inf;
			for(j=0;j<r[i]-1;j++)
			{
				if((y[j]>0 || Z(y[j])) && (y[j+1]<0 || Z(y[j+1])))
					x[i+1][k++] = bisect(i+1,a[i+1],x[i][j],x[i][j+1],-1);
				else if((y[j]<0 || Z(y[j])) && (y[j+1]>0 || Z(y[j+1])))
					x[i+1][k++] = bisect(i+1,a[i+1],x[i][j],x[i][j+1],1);
			}
			x[i+1][k++]=inf;
			r[i+1]=k;
		}

		sort(x[n]+1,x[n]+r[n]-1);

		for(i=1;i<r[n]-1;i++)
			printf(" %.4lf",x[n][i]);
		printf("\n");
	}
	return 0;
}