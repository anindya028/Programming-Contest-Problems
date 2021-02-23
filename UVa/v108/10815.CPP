#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<list>
using namespace std;
	
struct word
{
	char s[50];
}w[100000];

bool operator<(word a,word b)
{
	return strcmp(a.s,b.s)<0;
}

int main()
{
	int i,n,j;
	char g[50],h[500];
	n=0;
	while(gets(h))
	{
		for(i=j=0;h[i];i++)
			if(isalpha(h[i]))
			{
				g[j]=tolower(h[i]);
				j++;
			}
			else if(j)
			{
				g[j]='\0';
				strcpy(w[n].s,g);
				n++;
				j=0;
			}
		if(j)
		{
			g[j]='\0';
			strcpy(w[n].s,g);
			n++;
			j=0;
		}
	}
	sort(w,w+n);
	for(i=0;i<n;i++)
		if(!i || strcmp(w[i].s,w[i-1].s)!=0)
			printf("%s\n",w[i].s);
	return 0;
}
