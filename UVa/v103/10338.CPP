//Easy Math
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
unsigned long long fact[21];
int main()
{
	unsigned long long ans,i,n,j;
	char s[25];
        int *freq;
	fact[0]=1;
	for(i=1;i<=20;i++)fact[i]=fact[i-1]*i;
	scanf("%llu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
                freq=(int *)calloc(127,sizeof(int));
		for(j=0;s[j];j++)freq[s[j]]++;
		ans=fact[strlen(s)];
		for(j=63;j<95;j++)ans/=fact[freq[j]];
		printf("Data set %llu: %llu\n",i+1,ans);
	}
	return 0;
}













