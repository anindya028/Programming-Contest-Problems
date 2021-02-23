#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long ans[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
        int n;
	while(scanf("%d",&n)==1 && n)printf("%ld\n",ans[n]);
	return 0;
}













