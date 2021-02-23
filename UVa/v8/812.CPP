#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

struct yard
{
	int b,box[25],cum[25],mx,mxpos,n,seg[25];
}y[55];
bool final[1050],temp[1050];

int main()
{
	int cs=0,i,w,j,k,sum,taken,num,printed,tot;
	while(scanf("%d",&w)==1)
	{
		if(!w)break;
		if(cs)
			printf("\n");
		for(i=0;i<1050;i++)
			final[i]=temp[i]=false;
		for(i=sum=taken=tot=0;i<w;i++)
		{
			scanf("%d",&y[i].b);
			tot+=y[i].b;
			y[i].mx=0;
			y[i].n=0;
			if(y[i].b==0)
				continue;
			for(j=0;j<y[i].b;j++)
			{
				scanf("%d",&y[i].box[j]);
				y[i].box[j]=10-y[i].box[j];
			}
			y[i].cum[0]=y[i].box[0];
			if(y[i].cum[0]>y[i].mx)
				y[i].mx=y[i].cum[0];
			for(j=1;j<y[i].b;j++)
			{
				y[i].cum[j]=y[i].cum[j-1]+y[i].box[j];
				if(y[i].cum[j]>y[i].mx)
					y[i].mx=y[i].cum[j];
			}
			sum+=y[i].mx;
			for(j=0;j<y[i].b;j++)
				if(y[i].mx==y[i].cum[j])
				{
					y[i].mxpos=j;
					break;
				}
			if(y[i].mx==0)
				y[i].mxpos=-1;
			taken+=(y[i].mxpos+1);
			for(j=y[i].mxpos+1;j<y[i].b;j++)
				if(y[i].cum[j]==y[i].mx)
				{
					y[i].seg[y[i].n]=j-y[i].mxpos;
					y[i].n++;
				}
		}

		printf("Workyards %d\n",++cs);
		printf("Maximum profit is %d.\n",sum);
		final[taken]=true;
		num=1;
		for(i=0;i<w;i++)
			if(y[i].n>0)
			{
				for(j=taken;j<1025;j++)
					temp[i]=false;
				for(j=0;j<y[i].n;j++)
					for(k=tot;k>=taken;k--)
						if(final[k])
							if(k+y[i].seg[j]<=tot)
								temp[k+y[i].seg[j]]=true;
								
				for(j=taken;j<=tot;j++)
					if(temp[j] && !final[j])
					{
						final[j]=true;
						num++;
					}
			}

		printf("Number of pruls to buy:");
		printed=0;
		for(i=taken;i<=tot && printed<num && printed<10;i++)
			if(final[i])
			{
				printf(" %d",i);
				printed++;
			}
		printf("\n");
	}
	return 0;
}

