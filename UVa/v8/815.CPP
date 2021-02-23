#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define myabs(a) (((a)>0)?(a):-(a))
int elev[1000];

int main()
{
	int n,m,tot,area,cnt,i,vol,cs=0;
	double lev;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		tot=n*m;
		for(i=0;i<tot;i++)
			scanf("%d",&elev[i]);
		sort(elev,elev+tot);
		scanf("%d",&vol);
		area=0;
		i=0;
		cnt=0;
		while(vol>0 && (i+1)<tot)
		{
			area+=100;
			cnt++;
			if(area*myabs(elev[i+1]-elev[i])>vol)
			{
				lev=elev[i]+vol/(double)area;
				vol=0;
				break;
			}
			else
			{
				vol-=area*myabs(elev[i+1]-elev[i]);
				if(vol==0)
					lev=elev[i+1];
				i++;

			}
		}
		if(vol>0)
		{
			cnt++;
			area+=100;
			lev=elev[tot-1]+vol/(double)area;
		}
		printf("Region %d\n",++cs);
		printf("Water level is %.2lf meters.\n",lev);
		printf("%.2lf percent of the region is under water.\n\n",100*cnt/(double)tot);
	}
	return 0;
}
