//Adhoc
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<map>
using namespace std;

struct ingred
{
	char s[100];
}sam;
bool operator<(const ingred &a,const ingred &b)
{
	return strcmp(a.s,b.s)<0;
}
bool operator==(const ingred &a,const ingred &b)
{
	return !strcmp(a.s,b.s);
}

struct recipi
{
	int cost;
	char name[100];
}rec[105];
bool operator<(recipi a,recipi b)
{
	if(a.cost==b.cost)
		return strcmp(a.name,b.name)<0;
	return a.cost<b.cost;
}

int main()
{
	int t,m,n,k,b,c,cnt,x,sum;
	register int i,j;
	map<ingred,int> fast;
	char ss[100],sss[100];
	scanf("%d",&t);
	while(t--)
	{
		gets(sss);
		gets(sss);
		for(i=0;sss[i];i++)
			printf("%c",toupper(sss[i]));
		printf("\n");
		scanf("%d%d%d",&m,&n,&b);
		for(i=0;i<m;i++)
		{
			scanf("%s%d",sam.s,&c);
			fast[sam]=c;
		}
		for(i=cnt=0;i<n;i++)
		{
			gets(ss);
			gets(ss);
			scanf("%d",&k);
			for(j=sum=0;j<k;j++)
			{
				scanf("%s%d",sam.s,&x);
				sum+=x*fast[sam];
			}
			if(sum<=b)
			{
				rec[cnt].cost=sum;
				strcpy(rec[cnt].name,ss);
				cnt++;
			}
		}
		if(!cnt)
		{
			printf("Too expensive!\n\n");
		}
		else
		{
			sort(rec,rec+cnt);
			for(i=0;i<cnt;i++)
				printf("%s\n",rec[i].name);
			printf("\n");
		}
		fast.clear();
	}
	return 0;
}













