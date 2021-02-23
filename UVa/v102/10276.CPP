//Good linear DP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int tow[51],i,j,n;
	tow[0]=0;
	tow[1]=1;
	tow[2]=3;
	for(i=3,j=4;i<=50;i+=2,j+=2)
	{
		tow[i]=tow[i-1]+j;
		tow[i+1]=tow[i]+j;
	}
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			printf("%d\n",tow[j]);
		}
	}
	return 0;
}













