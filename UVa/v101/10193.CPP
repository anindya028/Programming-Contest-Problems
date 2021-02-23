#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000
char num[2][100];
long gcd (long m,long n )
{
	if(!m)return n;
	return gcd ((n%m),m);
}
int main()
{
	int n,i,j,len1,len2;
        long n1,n2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        	n1=n2=0;
		scanf("%s%s",num[0],num[1]);
		len1=strlen(num[0]);
                len2=strlen(num[1]);
		for(j=0;num[0][j];j++)
		{
			if(num[0][j]=='1')n1+=(long)pow(2,(len1-j-1));
		}
		for(j=0;num[1][j];j++)
		{
			if(num[1][j]=='1')n2+=(long)pow(2,(len2-j-1));
		}
		if(gcd(n1,n2)!=1)printf("Pair #%d: All you need is love!\n",i+1);
		else printf("Pair #%d: Love is not all you need!\n",i+1);
	}
	return 0;
}













