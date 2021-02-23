#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
char num[]={"0123456789ABCDEF"};
unsigned long long ans;
char s[100],c[100];
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
	        temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}

int legal(int base)
{
	int i,len=strlen(s);
	for(i=0;s[i];i++)
		if(isalpha(s[i]))
		{
			if((s[i]-'A'+10)>=base)return 0;
			ans+=((unsigned long long)(s[i]-'A'+10)*(unsigned long long)pow(base,len-i-1));
		}
		else
		{
			if((s[i]-'0')>=base)return 0;
			ans+=((unsigned long long)(s[i]-'0')*(unsigned long long)pow(base,len-i-1));
		}
	return 1;
}
void convert(int base)
{
	int i=0;
	while(ans)
	{
		c[i]=num[ans%base];
		ans/=base;
		i++;
	}
	c[i]='\0';
	rev(c);
	return;
}
int main()
{
	int n1,n2;
	while(scanf("%d%d%s",&n1,&n2,s)==3)
	{
        	ans=0;
		if(legal(n1))
		{
			if(n2==10)printf("%s base %d = %llu base 10\n",s,n1,ans);
			else
			{
				if(!ans)
				{
					printf("%s base %d = 0 base %d\n",s,n1,n2);
					continue;
				}
				convert(n2);
				printf("%s base %d = %s base %d\n",s,n1,c,n2);
			}
		}
		else printf("%s is an illegal base %d number\n",s,n1);
	}
	return 0;
}













