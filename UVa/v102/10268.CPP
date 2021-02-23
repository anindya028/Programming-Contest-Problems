#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char buf[1000001],*t;
	int i,x,a[500000],ans,m;
	while(gets(buf))
	{
		sscanf(buf,"%d",&x);
		gets(buf);
		i=0;
		t=strtok(buf," \n\r");
		while(t!=NULL)
		{
			sscanf(t,"%d",&a[i]);
			i++;
			t=strtok(NULL," \r\n");
		}
		m=i-1;
		for(i=ans=0;i<m;i++)
		{
			ans=(ans*x+(m-i)*a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}













