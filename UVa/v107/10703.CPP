#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int w,h,r,c,r1,r2,c1,c2,p,mat[505][505],j,temp;
	int count,inf=0;       	
	while(scanf("%d%d%d",&w,&h,&p)==3)
	{
		if(!w)break;
		for(r=1;r<=w;r++)
			for(c=1;c<=h;c++)
				mat[r][c]=1;
		for(j=count=0;j<p;j++)
		{
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			if(r1>r2)
			{
				temp=r1;
				r1=r2;
				r2=temp;
			}
			if(c1>c2)
			{
				temp=c1;
				c1=c2;
				c2=temp;
			}
			for(r=r1;r<=r2;r++)
				for(c=c1;c<=c2;c++)
					mat[r][c]=inf;
        }
		for(r=1;r<=w;r++)
			for(c=1;c<=h;c++)
				count+=mat[r][c];
		if(!count)printf("There is no empty spots.\n");
		else if(count==1)printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n",count);
	}
	return 0;
}



























