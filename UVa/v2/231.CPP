//Easiest L.I.S->O(n^2)->only length->bottom_up
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int h[10000],l[10000],max,len,temp,k=0,i,j;
	while(scanf("%d",&temp)==1)
	{
		if(temp<0)break;
                if(k)printf("\n");
		h[0]=temp;
                l[0]=1;
                len=0;
		for(i=1;;i++)
		{
			scanf("%d",&h[i]);
			if(h[i]<0)break;
			max=0;
			for(j=0;j<i;j++)
			{
				if(h[i]<h[j])
				{
					if(l[j]>max)
					{
						max=l[j];
					}
				}
			}
			l[i]=max+1;
			if(l[i]>len)len=l[i];
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",k+1,len);
		k++;
	}
	return 0;
}













