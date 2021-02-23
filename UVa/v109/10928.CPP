#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

struct node
{
	int id,deg;
}lis[1005];

bool operator<(node a,node b)
{
	if(a.deg==b.deg)
		return a.id<b.id;
	return a.deg<b.deg;
}

int main()
{
	int n,p,i,bs,dbs,cs,k;
	char s[5000];
	gets(s);
	sscanf(s,"%d",&n);
	for(cs=0;cs<n;cs++)
	{
		gets(s);
		if(cs)
			gets(s);
		sscanf(s,"%d",&p);
		for(i=0;i<p;i++)
		{
			lis[i].deg=0;
			lis[i].id=i+1;
			gets(s);
			bs=dbs=0;
			while(sscanf(s+bs,"%d%n",&k,&dbs)==1)
			{
				lis[i].deg++;
				bs+=dbs;
			}
		}
		sort(lis,lis+p);
		printf("%d",lis[0].id);
		i=1;
		while(i<p && lis[i].deg==lis[i-1].deg)
		{
			printf(" %d",lis[i].id);
			i++;
		}
		printf("\n");
	}
	return 0;
}
