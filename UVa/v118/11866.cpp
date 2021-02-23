#include<stdio.h>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define LL long long

LL s1(LL a,LL b)
{
	return ( (b*(b+1))/2 - (a*(a-1))/2 );
}

LL s2(LL a,LL b)
{
	a--;
	return ( (b*(b+1)*(2*b+1))/6 - (a*(a+1)*(2*a+1))/6 );
}

int main()
{
	int t,i,j;
	LL x,y,v,u,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		v = y-x;
		u = y/2;
		ans = (x<=u)* ( (s2(x,u)+s1(x,u))/2 - (u-x+1)*((x*(x-1))/2) );
	//	printf("%lld\n",ans);
		ans+= (u<v)* (( (y*y+y)*(v-u) - (2*y+1)*s1(u+1,v) + s2(u+1,v) - (v-u)*x*(x-1) )/2);
	//	printf("%lld\n",ans);
		ans+= (u<v)* ( (3*y+2)*s1(u+1,v) - (y*y+y)*(v-u) - 2*s2(u+1,v) );
	//	printf("%lld\n",ans);
		v = (v+1>=x)*v + (v+1<x)*(x-1);
		ans+= (v<y)* ( (y+1)*((1-x)*(y-v)+s1(v+1,y)) - s2(v+1,y) + (x-1)*s1(v+1,y) );

		printf("%lld\n",ans);
	}
	return 0;
}