#include<stdio.h>
#include<math.h>

#define Max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int a,b,n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		int ma,mb,m;
		ma=(int)floor(log((double)(a))/log(2.0) + 1e-8);
		mb=(int)floor(log((double)(b))/log(2.0) + 1e-8);
		m=Max(ma,mb);
		m=n-m;
		printf("%d\n",(1<<n) - 1 - (1<<m) + 2);
	}
	return 0;
}