#include<stdio.h>
#include<string.h>

#define Max(a,b) (((a)>(b))?(a):(b))

char s[100000];

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

int main()
{
	int t;
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
		gets(s);
		int num[105];
		int n=0,i,j,bs=0,db;
		while(sscanf(s+bs,"%d%n",&num[n],&db)==1)
			n++,bs+=db;
		int ans=1;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				db=gcd(num[i],num[j]),ans=Max(ans,db);
		printf("%d\n",ans);
	}
	return 0;
}