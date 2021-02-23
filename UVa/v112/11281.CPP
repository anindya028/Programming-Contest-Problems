#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define eps 1e-10
#define myabs(a) (((a)>0)?(a):-(a))

bool obtuse_tri(double d1,double d2,double d3)
{
	return (((d1*d1+d2*d2)<d3*d3) || ((d3*d3+d2*d2)<d1*d1) || ((d1*d1+d3*d3)<d2*d2));
}

double triarea(double d1,double d2,double d3)
{
	double s=(d1+d2+d3)/2;
	return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

int main()
{
	int m,n,i,j,k,*f;
	double hole[105],r,a,b,c;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%lf",&hole[i]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(obtuse_tri(a,b,c) || triarea(a,b,c)<eps)
			r=Max(a,Max(b,c))/2.;
		else 
			r=(a*b*c)/(4*triarea(a,b,c));
		k=0;
		f=(int *)calloc(m+1,sizeof(int));
		for(j=1;j<=m;j++)
			if(hole[j]>(r*2) || myabs(hole[j]-2*r)<eps)
			{
				f[j]=1;
				k++;
			}
		if(!k)
			printf("Peg %c will not fit into any holes\n",65+i);
		else
		{
			printf("Peg %c will fit into hole(s):",65+i);
			for(j=1;j<=m;j++)
				if(f[j])
					printf(" %d",j);
			printf("\n");
		}
		free(f);
	}
	return 0;
}













