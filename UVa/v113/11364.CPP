//Adhoc
#include<stdio.h>
	
int main()
{
	int n,i,mx,mn,t,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mx=-1;
		mn=1000000;
		for(i=0;i<n;i++)
		{
			scanf("%d",&d);
			if(d<mn)
				mn=d;
			if(d>mx)
				mx=d;
		}
		printf("%d\n",(mx-mn)*2);
	}
	return 0;
}
