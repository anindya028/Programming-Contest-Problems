#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using  namespace std;
//#define Long __int64
//#define Long long long
struct ana
{
	char s[1000];
	int freq[130];
};
bool operator<(ana x,ana y)
{
	return strcmp(x.s,y.s)<0;
}
int main()
{
	int i=0,j,k,l=0,flag,n;
	ana *a;
	char temp[10];
	gets(temp);
	sscanf(temp,"%d",&n);
	gets(temp);
	while(n--)
	{
			a=(ana *)calloc(105,sizeof(ana));
			i=0;
	while(gets(a[i].s))
	{
		if(a[i].s[0]=='\0'||a[i].s[0]==EOF)break;
		for(j=0;a[i].s[j];j++)
			a[i].freq[a[i].s[j]]++;
                i++;
	}
	sort(a,a+i);
	for(j=0;j<i-1;j++)
	{
		for(k=j+1;k<i;k++)
		{
                	flag=1;
			for(l=0;l<129;l++)
			{
				if(l==32||l==9)continue;
				if(a[j].freq[l]!=a[k].freq[l])
				{
					flag=0;
					break;
				}
			}
			if(flag)printf("%s = %s\n",a[j].s,a[k].s);
		}
	}
	if(n)printf("\n");
	free(a);
	}
	return 0;
}













