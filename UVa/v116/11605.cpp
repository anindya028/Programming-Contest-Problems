#include<stdio.h>
#include<math.h>

int main()
{
	int x,y,z,i,j,k,n,t,cs;
	double p,ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&n);
		ans=0.;
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++)
				for(k=1;k<=z;k++)
				{
					p=((x-i)*i+x+(x-i+1)*(i-1))/(double)(x*x);
					p*=((y-j)*j+y+(y-j+1)*(j-1))/(double)(y*y);
					p*=((z-k)*k+z+(z-k+1)*(k-1))/(double)(z*z);
					double now=pow(2*p-1,(double)n);
					if(n%2)
						ans+=((1+now)/2);
					else
						ans+=((1-now)/2);
				}
	
		printf("Case %d: %.9lf\n",cs+1,ans);
	}
	return 0;
}
