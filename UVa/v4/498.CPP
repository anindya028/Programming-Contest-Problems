#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	char buf[size],*t;
	int i,n,x[size],m,j;
        long ans;
	while(gets(buf))
	{
		int c[size];
		i=0;
		t=strtok(buf," \n\r");
		while(t!=NULL)
		{
			sscanf(t,"%d",&c[i]);
                        i++;
			t=strtok(NULL," \r\n");
		}
		n=i;
		if(gets(buf))
		{
			i=0;
			t=strtok(buf," \n\r");
			while(t!=NULL)
			{
				sscanf(t,"%d",&x[i]);
                        	i++;
				t=strtok(NULL," \r\n");
			}
		}
		m=i;
		for(i=0;i<m;i++)
		{
			ans=0;
			for(j=0;j<n;j++)
			{
				ans+=c[j]*pow(x[i],n-j-1);
			}
			if((i+1)!=m)printf("%ld ",ans);
			else printf("%ld",ans);
		}
		printf("\n");
	}
}













