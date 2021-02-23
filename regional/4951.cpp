#include<stdio.h>
#include<algorithm>

using namespace std;
#define inf 1<<28

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

int main()
{
	int buy[1005][2],sell[1005][2],i,j,k,n,t,a,b,c;
	char ne[20],garb1[20],garb2[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=inf,b=0,c=0;
		int ida,idb;
		int nb=0,ns=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",ne);
			if(ne[0]=='b')
			{
				scanf("%d%s%s%d",&buy[nb][0],garb1,garb2,&buy[nb][1]);
				b=Max(buy[nb][1],b);
				if(b==buy[nb][1])
					idb=nb;
				nb++;
			}
			else
			{
				scanf("%d%s%s%d",&sell[ns][0],garb1,garb2,&sell[ns][1]);
				a=Min(sell[ns][1],a);
				if(a==sell[ns][1])
					ida=ns;
				ns++;
			}
			while(b>=a)
			{
				c=a;
				int v=Min(buy[idb][0],sell[ida][0]);
				buy[idb][0]-=v;
				if(!buy[idb][0])
				{
					b=0;
					for(j=0;j<nb;j++)
						if(buy[j][0])
							if(buy[j][1]>b)
								b=buy[j][1],idb=j;
				}
				sell[ida][0]-=v;	
				if(!sell[ida][0])
				{
					a=inf;
					for(k=0;k<ns;k++)
						if(sell[k][0])
							if(sell[k][1]<a)
								a=sell[k][1],ida=k;
				}
			}
			if(a==inf)
				printf("-");
			else
				printf("%d",a);
			if(!b)
				printf(" -");
			else printf(" %d",b);
			if(!c)
				printf(" -");
			else
				printf(" %d",c);
			printf("\n");
		}
	}
	return 0;
}