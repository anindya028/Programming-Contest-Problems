//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
char fing[10][10]={"qaz","wsx","edc","rfvtgb"," "," ","yhnujm","ik,","ol.","p;/"};
struct word
{
	char s[100];
}*ans;
bool operator<(word a,word b)
{
	int lena=strlen(a.s),lenb=strlen(b.s);
	if(lena>lenb)return 1;
	else if(lena==lenb)
	{
		if(strcmp(a.s,b.s)>=0)return 0;
		else return 1;
	}
	else return 0;
}
int main()
{
	int n,f,i,j,*freq,temp,flag,k,len;
	char t[100];
	while(scanf("%d%d",&f,&n)==2)
	{
		freq=(int *)calloc(128,sizeof(int));
		ans=(word *)calloc(n,sizeof(word));
		for(i=0;i<f;i++)
		{
			scanf("%d",&temp);
			for(j=0;fing[temp-1][j];j++)
				freq[fing[temp-1][j]]=1;
		}
		for(i=k=0;i<n;i++)
		{
			scanf("%s",t);
			for(j=0,flag=1;t[j];j++)
			{
				if(freq[t[j]])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				strcpy(ans[k].s,t);
				k++;
			}
		}
		sort(ans,ans+k);
		if(!k)printf("%d\n",k);
		else
		{
			k=1;
			len=strlen(ans[0].s);
			while(strlen(ans[k].s)==len)
				k++;
			for(i=0;i<(k-1);i++)
				for(j=i+1;j<k;j++)
					if(!strcmp(ans[i].s,ans[j].s))
						ans[j].s[0]='\0';
			sort(ans,ans+k);
			k=1;
			while(strlen(ans[k].s)==len)
				k++;
			printf("%d\n",k);
			for(i=0;i<k;i++)
				printf("%s\n",ans[i].s);
		}
		free(freq);
		free(ans);
	}
	return 0;
}













