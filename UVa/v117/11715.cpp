#include<stdio.h>
#include<math.h>

int main()
{
	int cs,i=0;
	double u,v,t,a,s;
	while(scanf("%d",&cs)==1 && cs)
	{
		/*
		1 u v t
		2 u v a
		3 u a s
		4 v a s
		*/
		if(cs==1)
		{
			scanf("%lf%lf%lf",&u,&v,&t);
			printf("Case %d: %.3lf %.3lf\n",++i,(v+u)*t/2,(v-u)/t);
		}
		else if(cs==2)
		{
			scanf("%lf%lf%lf",&u,&v,&a);
			printf("Case %d: %.3lf %.3lf\n",++i,(v*v-u*u)/(2*a),(v-u)/a);
		}
		else if(cs==3)
		{
			scanf("%lf%lf%lf",&u,&a,&s);
			v=sqrt(u*u+2*a*s);
			printf("Case %d: %.3lf %.3lf\n",++i,v,(v-u)/a);
		}
		else
		{
			scanf("%lf%lf%lf",&v,&a,&s);
			u=sqrt(v*v-2*a*s);
			printf("Case %d: %.3lf %.3lf\n",++i,u,(v-u)/a);
		}
	}
	return 0;
}
