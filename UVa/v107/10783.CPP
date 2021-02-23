#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,l,h,i;
        scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&l,&h);
		if(l%2)l-=2;
		else l-=1;
		if(h%2==0)h-=1;
		printf("Case %d: %d\n",i+1,((h+1)/2)*((h+1)/2)-((l+1)/2)*((l+1)/2));
	}
	return 0;
}













