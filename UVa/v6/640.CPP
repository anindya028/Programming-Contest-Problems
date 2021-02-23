#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
bool flag[1000053];
int main()
{
	long i,sum,j;
        char s[10];
	for(i=1;i<=1000000;i++)
	{
        	sum=i;
		sprintf(s,"%ld",i);
		for(j=0;s[j];j++)sum+=(s[j]-'0');
		flag[sum]=1;
		if(!flag[i])printf("%ld\n",i);
	}
	return 0;
}













