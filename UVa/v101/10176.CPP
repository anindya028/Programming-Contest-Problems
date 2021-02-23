#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
long long bigmod(long long b,long long p,long long m)
{
   long long a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0)
   { 
      a = bigmod(b,p/2,m); 
      return (a*a) % m; 
   }
   else
   { 
      return ((b % m) * bigmod(b,p-1,m)) % m; 
   } 
}
int main()
{
	char s[10005],c;
        int i,len,mod;
	while(scanf("%c",&c)==1)
	{
		mod=i=0;
		s[i++]=c;
		while(scanf("%c",&c)==1)
		{
			if(c=='#')break;
            if(!isdigit(c))continue;
			s[i++]=c;
		}
		scanf("%c",&c);
                s[i]='\0';
		len=strlen(s);
		for(i=0;s[i];i++)
		{
			if(s[i]=='1')
                        {
				mod+=bigmod(2,len-i-1,131071);
				mod%=131071;
			}
		}
		if(mod)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}













