#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
void ex_euclid(int a,int b,int *d,int *x,int *y)
{
	int x1,y1,d1;
	if(b==0)
	{
		*d=a;
		*x=1;
		*y=0;
            return;
	}
	ex_euclid(b,a%b,&d1,&x1,&y1);
	*d=d1;
	*x=y1;
	*y=x1-(a/b)*y1;
}
int main()
{
	int a,b,d,x,y,t;
	while(scanf("%d%d",&a,&b)==2)
	{
		ex_euclid(a,b,&d,&x,&y);
		printf("%d %d %d\n",x,y,d);
	}
	return 0;
}













