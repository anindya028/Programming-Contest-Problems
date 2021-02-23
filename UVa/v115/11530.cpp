#include<stdio.h>

int val[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main()
{
	int t,cs,i,sum;
	char s[100];
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=0;cs<t;cs++)
	{
		gets(s);
		for(i=sum=0;s[i];i++)
			if(s[i]==' ')
				sum+=1;
			else
				sum+=val[s[i]-'a'];
		printf("Case #%d: %d\n",cs+1,sum);
	}
	return 0;
}
