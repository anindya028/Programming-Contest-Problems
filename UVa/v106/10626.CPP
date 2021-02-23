#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define Min(a,b) (((a)<(b))?(a):(b))

int main()
{
	int t,n1,n5,n10,c,ans,given;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&c,&n1,&n5,&n10);
		if(n10>=c)
		{
			printf("%d\n",c);
			continue;
		}
		if((n10+n5/2)>=c)
		{
			printf("%d\n",n10+(c-n10)*2);
			continue;
		}
		if((n10+n5)>=c)
		{
			given=0;
			while((n10+n5)>=c)
			{
				n10++;
				n5-=2;
				given++;
			}
			n10--;
			n5+=2;
			given--;
			ans=given+n10+n5*4;
			printf("%d\n",ans);
			continue;
		}
		if((2*n10+n5)>=c)
		{
			given=0;
			while((2*n10+n5)>=c)
			{
				given++;
				n10--;
				c--;
			}
			given--;
			n10++;
			ans=given+n10*4+(n10+n5)*4;
			printf("%d\n",ans);
			continue;
		}
		ans=n10*4+(n10+n5)*4+(c-2*n10-n5)*8;
		printf("%d\n",ans);
	}
	return 0;
}
