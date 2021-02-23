#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	char buf[size] ,*t;
	while(gets(buf))
	{
		int s[2][size];
		int i=0;
		t=strtok(buf," \n\r");
		while(t!=NULL)
		{
			sscanf(t,"%d",&s[0][i]);
                        i++;
			t=strtok(NULL," \r\n");
		}
		int n1=i,n2;
		gets(buf);
		i=0;
                t=strtok(buf," \n\r");
		while(t!=NULL)
		{
			sscanf(t,"%d",&s[1][i]);
			i++;
			t=strtok(NULL," \n\r");
		}
		n2=i;
		int match=0;
		for(i=0;i<n1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				if(s[0][i]==s[1][j])match++;
			}
		}
		if(match==n1)
		{
			if(n1==n2)printf("A equals B\n");
			else if(n1<n2)printf("A is a proper subset of B\n");
		}
		else if(match==n2)
		{
			if(n2<n1)printf("B is a proper subset of A\n");
                }
		else if(!match)printf("A and B are disjoint\n");
		else printf("I'm confused!\n");
	}               

}













