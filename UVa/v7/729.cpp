#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int *taken,len,lev,k,length;
int s[100],given[100],tot;
char s1[100];

struct comb
{
      char sd[100];
}ans[13000]; 

bool operator<(comb a,comb b)
{
     return strcmp(a.sd,b.sd)<0;
}

void gene(int lev)
{
	int i=0,flag;
	if(lev==len)
	{
		for(i=0;i<length;i++)
		   s1[i]='0';
    s1[i]='\0';
    for(i=0;i<len;i++)
        s1[s[i]]='1'; 
		strcpy(ans[tot++].sd,s1);    
		return;
	}
	if(lev)
		for(;given[i]<s[lev-1];i++);
	for(flag=0;i<length;i++)
	{
		if(!taken[i] && !flag)
		{
			s[lev]=given[i];
			lev++;
			taken[i]=1;
			if(given[i]==given[i+1])flag=1;
			gene(lev);
			lev--;
			taken[i]=0;
		}
		else if(given[i]!=given[i+1])
			flag=0;
	}
	return;
}

int main()
{
  int i,cs,t;  
	scanf("%d",&t);
	for(cs=0;cs<t;++cs)
	{
    if(cs)
       printf("\n");                 
    scanf("%d%d",&length,&len);        
		taken=(int *)calloc(length,sizeof(int));
		for(i=0;i<length;i++)
		   given[i]=i;
    tot=0;    
		gene(0);
		sort(ans,ans+tot);
		for(i=0;i<tot;i++)
		   printf("%s\n",ans[i].sd);
		free(taken);
	}
	return 0;
}
