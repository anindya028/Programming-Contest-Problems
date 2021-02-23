#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	double cordx[1005],cordy[1005],dx,dy,gx,gy,d1,d2;
	int n,i,flag;
	while(scanf("%d%lf%lf%lf%lf",&n,&gx,&gy,&dx,&dy)==5)
	{
		for(i=0;i<n;i++)scanf("%lf%lf",&cordx[i],&cordy[i]);
		for(i=flag=0;i<n;i++)
		{
			d1=sqrt((cordx[i]-dx)*(cordx[i]-dx)+(cordy[i]-dy)*(cordy[i]-dy));
			d2=sqrt((cordx[i]-gx)*(cordx[i]-gx)+(cordy[i]-gy)*(cordy[i]-gy));
			if(d1>=(2*d2))
			{
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",cordx[i],cordy[i]);
				flag=1;
				break;
			}
		}
		if(!flag)printf("The gopher cannot escape.\n");
	}
	return 0;
}













