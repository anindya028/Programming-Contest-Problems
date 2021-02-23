#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
char num[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char s[2][100];
int minbase(int a)
{
	int i,max=1;
        for(i=0;s[a][i];i++)
	{
		if(isalpha(s[a][i]))
		{
			if((s[a][i]-'A'+10)>max)max=s[a][i]-'A'+10;
		}
		else
		{
			if((s[a][i]-'0')>max)max=s[a][i]-'0';
		}
	}
	return max+1;
}
unsigned long long legal(int base,int sel)
{
	int i,len=strlen(s[sel]);
	unsigned long long ans=0;
	for(i=0;s[sel][i];i++)
		if(isalpha(s[sel][i]))
		{
			ans+=((unsigned long long)(s[sel][i]-'A'+10)*(unsigned long long)pow(base,len-i-1));
		}
		else
		{
			ans+=((unsigned long long)(s[sel][i]-'0')*(unsigned long long)pow(base,len-i-1));
		}
	return ans;
}
int main()
{
	unsigned long long ans1,ans2;
        int i,j,found;
	while(scanf("%s%s",s[0],s[1])==2)
	{
		found=0;
		i=minbase(0);
		for(;i<=36 && !found;i++)
		{
			ans1=legal(i,0);
			for(j=minbase(1);j<=36;j++)
			{
				ans2=legal(j,1);
				if(ans1==ans2)
				{
					found=1;
					printf("%s (base %d) = %s (base %d)\n",s[0],i,s[1],j);
					break;
				}
			}
		}
		if(!found)printf("%s is not equal to %s in any base 2..36\n",s[0],s[1]);
	}
	return 0;
}













