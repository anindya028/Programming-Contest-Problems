#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char s[55][5];
	char buf[50000];
	int i,j,n,t,bs,dbs;
	gets(buf);
	sscanf(buf,"%d",&t);
	while(t--)
	{
		gets(buf);
		n=0;
		bs=dbs=0;
		while(sscanf(buf+bs,"%s%n",s[n],&dbs)==1)
			bs+=dbs,n++;
		int in[55]={0},out[55]={0},f;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue;
				if(s[i][1]!=s[j][0])
					out[i]++,in[j]++;
			}
		f=1;
		for(i=0;i<n;i++)
			if(in[i]!=out[i])
			{
				f=0;
				break;
			}
		for(i=0;i<n;i++)
			if(!in[i] && !out[i])
				f=0;
		if(f)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}
	return 0;
}