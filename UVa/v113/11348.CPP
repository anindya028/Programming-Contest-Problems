#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct fend
{
	int m,st[60],u;
}f[60];

int main()
{
	int i,j,cs,t,n,cnt,*freq;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		freq=(int *)calloc(10005,sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&f[i].m);
			for(j=0;j<f[i].m;j++)
				scanf("%d",&f[i].st[j]);
			sort(f[i].st,f[i].st+f[i].m);
			for(j=0;j<f[i].m;j++)
			{
				freq[f[i].st[j]]++;
				while((j+1)<f[i].m)
				{
					if(f[i].st[j]==f[i].st[j+1])
						j++;
					else break;
				}
			}
			f[i].u=0;
		}
		for(i=cnt=0;i<n;i++)
		{
			for(j=0;j<f[i].m;j++)
			{
				if(freq[f[i].st[j]]==1)
				{
					f[i].u++;
					freq[f[i].st[j]]++;
					cnt++;
				}
			}
		}
		printf("Case %d:",cs+1);
		for(i=0;i<n;i++)
			printf(" %.6lf%%",(f[i].u*100.)/cnt);
		printf("\n");
		free(freq);
	}
	return 0;
}

