#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

char given[100];
int len;
struct palin
{
	char s[100];
}p[100];

bool ispal(int st,int end)
{
	while(st<end)
	{
		if(given[st]!=given[end])
			return false;
		st++;
		end--;
	}
	return true;
}

bool operator<(palin a,palin b)
{
	return strcmp(a.s,b.s)<0;
}

int main()
{
	int i,j,k,ans,cnt,n,l;
	while(gets(given))
	{
		if(given[0]=='\0')
			continue;
		ans=0;
		len=strlen(given);
		for(i=1;i<=len;i++)
		{
			cnt=n=0;
			for(j=0;(j+i-1)<len;j++)
			{
				if(ispal(j,j+i-1))
				{
					for(k=0,l=j;l<j+i;l++,k++)
						p[n].s[k]=given[l];
					p[n].s[k]='\0';
					n++;
				}
			}
			sort(p,p+n);
			for(j=0;j<n;j++)
			{
				cnt++;
				while((j+1)<n && !strcmp(p[j].s,p[j+1].s))
					j++;
			}
			ans+=cnt;
		}
		printf("The string '%s' contains %d palindromes.\n",given,ans);
	}
	return 0;
}
