#include<stdio.h>
#include<string.h>

#define SIZE 90009

char rowflag[SIZE];
int colflag[SIZE],colf[SIZE];

int main()
{
	int i,j,n,m,t,row,col,x,ct,box,flagged,ii;

	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d%d",&n,&m);

		memset(rowflag,0,sizeof(rowflag));
		memset(colflag,0,sizeof(colflag));
		memset(colf,0,sizeof(colf));

		while(m--)
		{
			scanf("%d%d",&i,&j);
			
			row=i+j-1;
			col=n-i+j;
			rowflag[row]=1;
			colf[col]=colflag[col]=1;
		}
		
		
		for(i=2;i<2*n;i++)
		{
			colf[i]+=colf[i-2];
		}

		ct=0;
		for(i=1;i<2*n;i++)
		{
			if(!rowflag[i])
			{
				if(i==1 || i==2*n-1)
				{
					if(colflag[n]==0)
						ct++;
				}
				else 
				{
					if(i>n) ii=2*n-i;
					else ii=i;

					flagged=colf[n+ii-1]-colf[n-ii+1];
					if(colflag[n-ii+1]) flagged++;

					if(i<=n) box=i;
					else box=2*n-i;

					ct+=box-flagged;
				}
			}
		}

		printf("Case #%d: %d\n",x,ct);
	}

	return 0;
}