#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define myabs(a) (((a)>0)?(a):-(a))

struct person
{
	char name[100];
	int am;
}p[50];

bool operator<(person x,person y)
{
	return x.am>y.am;
}

int main()
{
	int n,t,u,v,i,j,c,cs=0,flag;
	char a[50],b[50];
	while(scanf("%d%d",&n,&t)==2)
	{
		if(!n && !t)
			break;
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",p[i].name);
			p[i].am=0;
		}
		for(i=0;i<t;i++)
		{
			scanf("%s%s%d",a,b,&c);
			for(j=0;j<n;j++)
			{
				if(!strcmp(p[j].name,a))
				{
					u=j;
					break;
				}
			}
			for(j=0;j<n;j++)
			{
				if(!strcmp(p[j].name,b))
				{
					v=j;
					break;
				}
			}
			p[u].am-=c;
			p[v].am+=c;
		}
		sort(p,p+n);
		i=0;
		j=n-1;
		printf("Case #%d\n",++cs);
		while(i<j && p[i].am>0 && p[j].am<0)
		{
			if(!flag)
				flag=1;
			if(p[i].am<myabs(p[j].am))
			{
				printf("%s %s %d\n",p[i].name,p[j].name,p[i].am);
				p[j].am
					+=p[i].am;
				p[i].am=0;
				i++;
			}
			else if(p[i].am==myabs(p[j].am))
			{
				printf("%s %s %d\n",p[i].name,p[j].name,p[i].am);
				p[j].am=p[i].am=0;
				i++;
				j--;
			}
			else
			{
				printf("%s %s %d\n",p[i].name,p[j].name,myabs(p[j].am));
				p[i].am+=p[j].am;
				p[j].am=0;
				j--;
			}
		}
		//if(!flag)printf("\n");
		printf("\n");
	}
	return 0;
}

