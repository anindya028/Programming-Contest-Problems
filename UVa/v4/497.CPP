//L.I.S->O(n^2)->length & the sequence->bottom_up
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int h[1000],*l,max,len,i,j,*parent,*seq,n,k;
	char temp[12];
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		if(k)printf("\n");
        	scanf("%d",&h[0]);
		l=(int *)calloc(1000,sizeof(int));
		parent=(int *)calloc(1000,sizeof(int));
		seq=(int *)calloc(1000,sizeof(int));
		len=0;
		l[0]=1;	
         	i=1;
		gets(temp);
		while(gets(temp)&&temp[0])
		{	
			sscanf(temp,"%d",&h[i]);
			max=0;
			for(j=0;j<i;j++)
			{
				if(h[j]<h[i])
				{
					if(l[j]>max)
					{
						max=l[j];
                                       	        parent[i]=j;
					}
				}
	     		}
			l[i]=max+1;
			if(l[i]>len)
			{
				len=l[i];
				seq[0]=i;
			}
			i++;
		}
		if(i==1)
		{
			printf("Max hits: 1\n");
			printf("%d\n",h[0]);
			continue;
		}
		for(j=1;j<len;j++)
		{
			seq[j]=parent[seq[j-1]];
		}
		printf("Max hits: %d\n",len);
		for(i=len-1;i>=0;i--)printf("%d\n",h[seq[i]]);
        }
	return 0;
}













