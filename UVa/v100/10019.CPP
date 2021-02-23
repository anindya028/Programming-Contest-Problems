#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
long ans;
long convert(void)
{
	long count=0;
	while(ans)
	{
		if(ans%2)count++;
		ans/=2;
	}
	return count;
}
int main()
{
	long n,m,i,j,len;
        char temp[100];
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&m);
                        ans=m;
			printf("%ld",convert());
			sprintf(temp,"%ld",m);
			ans=0;
                        len=strlen(temp);
			for(j=0;temp[j];j++)ans+=(temp[j]-'0')*(long)pow(16,len-j-1);
			printf(" %ld\n",convert());
		}
	}
	return 0;
}













