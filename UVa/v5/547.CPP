#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int ddf[3010];
	int i,j,k,num,len,prev,low,high,temp,cs=0,max;
	char s[15];
	for(i=0;i<3005;i++)
		ddf[i]=0;
	ddf[1]=1;
	for(i=2;i<3005;i++)
	{
		len=1;
		num=i;
		prev=0;
		while(num!=prev)
		{
			prev=num;
			num=0;
			for(j=1;j*j<=prev;j++)
			{
				if(prev%j==0)
				{
					sprintf(s,"%d",j);
					for(k=0;s[k];k++)
						num+=(s[k]-'0');
					if(j*j!=prev)
					{
						sprintf(s,"%d",prev/j);
						for(k=0;s[k];k++)
							num+=(s[k]-'0');
					}
				}
			}
			if(ddf[num])
			{
				len+=ddf[num];
				break;
			}
			len++;
		}
		ddf[i]=len;
	}
	while(scanf("%d%d",&low,&high)==2)
	{
		if(low==0 && high==0)
		{
			printf("Input%d: %d %d\n",++cs,low,high);
			printf("Output%d: \n",cs);
			continue;
		}
		printf("Input%d: %d %d\n",++cs,low,high);
		if(high<low)
		{
			temp=high;
			high=low;
			low=temp;
		}
		for(i=low,max=0;i<=high;i++)
			if(ddf[i]>max)
			{
				max=ddf[i];
				num=i;
			}
		printf("Output%d: %d",cs,num);
		prev=0;
		while(1)
		{
			prev=num;
			num=0;
			for(j=1;j*j<=prev;j++)
			{
				if(prev%j==0)
				{
					sprintf(s,"%d",j);
					for(k=0;s[k];k++)
						num+=(s[k]-'0');
					if(j*j!=prev)
					{
						sprintf(s,"%d",prev/j);
						for(k=0;s[k];k++)
							num+=(s[k]-'0');
					}
				}
			}
			if(num!=prev)printf(" %d",num);
			else break;
		}
		printf("\n");
	}
	return 0;
}













