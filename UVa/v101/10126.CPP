#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<list>
using namespace std;

struct word
{
	char s[60];
}w[10005];
	
bool operator<(word a,word b)
{
	return strcmp(a.s,b.s)<0;
}

int main()
{
	int oq,i,j,cnt,n,flag,cs=0;
	char buf[1050],temp[60];
	while(gets(buf))
	{
		if(sscanf(buf,"%d",&oq)!=1)
			continue;
		if(cs)
			printf("\n");
		n=0;
		while(gets(buf))
		{
			if(!strcmp(buf,"EndOfText"))
				break;
			for(i=j=0;buf[i];i++)
				if(isalpha(buf[i]))
				{
					temp[j]=tolower(buf[i]);
					j++;
				}
				else if(j)
				{
					temp[j]='\0';
					strcpy(w[n].s,temp);
					n++;
					j=0;
				}
			if(j)
			{
				temp[j]='\0';
				strcpy(w[n].s,temp);
				n++;
				j=0;
			}
		}
		sort(w,w+n);
		flag=0;
		for(i=0;i<n;i++)
		{
			cnt=1;
			while((i+1)<n && !strcmp(w[i+1].s,w[i].s))
			{
				i++;
				cnt++;
			}
			if(cnt==oq)
			{
				flag=1;
				printf("%s\n",w[i].s);
			}
		}
		++cs;
		if(!flag)
			printf("There is no such word.\n");
	}
	return 0;
}
