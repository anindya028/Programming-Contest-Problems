#include<stdio.h>

int main()
{
	int n,b,w,h,i,p,a,j,mn;
	while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
	{
		mn=1<<29;
		for(i=0;i<h;i++)
		{
			scanf("%d",&p);
			for(j=0;j<w;j++)
			{
				scanf("%d",&a);
				if(a>=n && p*n<mn)
					mn=n*p;
			}
		}
		if(mn>b)
			printf("stay home\n");
		else
			printf("%d\n",mn);
	}
	return 0;
}
