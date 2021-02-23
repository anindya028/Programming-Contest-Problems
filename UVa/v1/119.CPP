#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long lon
struct gift
{
	char name[15];
	long gain;
}*g;
int main()
{
	int n,m,d,i,j,k,cs=0;
	char nam[15];
	while(scanf("%d",&n)==1)
        {
		if(cs)printf("\n");
		g=(gift *)calloc(n,sizeof(gift));
		for(i=0;i<n;i++)
		{
			scanf("%s",g[i].name);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",nam,&m,&d);
			for(j=0;j<n;j++)
			{
				if(!strcmp(g[j].name,nam))
				{
					if(m&&d)g[j].gain-=(m-(m%d));
                	                //else if(!d)g[j].gain+=m;
					break;
				}
			}
			for(j=0;j<d;j++)
			{
				scanf("%s",nam);
				for(k=0;k<n;k++)
				{
					if(!strcmp(g[k].name,nam))
					{
						if(m&&d)g[k].gain+=(m/d);
						break;
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%s %ld\n",g[i].name,g[i].gain);
		}
		cs++;
	}
	return 0;
}













