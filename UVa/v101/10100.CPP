#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
#define max 1005
char str1[max][50],str2[max][50],lcs[max][50];
int lcs_lnt(int l1,int  l2)
{
	int c[max][max]={0},b[max][max]={0};
	register int i,j;
	for(i=1;i<l1;i++)
	{
		for(j=1;j<l2;j++)
		{
			if(!strcmp(str1[i-1],str2[j-1]))
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else c[i][j]=c[i][j-1];
		}
	}
	return c[l1-1][l2-1];
}
int main()
{
	char temp[1005];
        int i,j,k,cs=0,l1,l2,got;
	while(gets(temp))
	{
		if(temp[0]=='\0')
		{
			gets(temp);
			printf("%2d. Blank!\n",++cs);
			continue;
		}
		for(i=0,j=0,k=0;temp[i];i++)
		{
			if(isalnum(temp[i]))
			{
                        	got=0;
				str1[j][k]=temp[i];
				k++;
			}
			else
			{
                        	got=1;
                             if(k)
							 {
									str1[j][k]='\0';
									j++;
							 }
				k=0;
			}
		}
		if(!got)str1[j][k]='\0';
		if(got)l1=j+1;
                else l1=j+2;
		gets(temp);
		if(temp[0]=='\0')
		{
			printf("%2d. Blank!\n",++cs);
			continue;
		}
		for(i=0,j=0,k=0;temp[i];i++)
		{
			if(isalnum(temp[i]))
			{
                        	got=0;
				str2[j][k]=temp[i];
				k++;
			}
			else
			{
                        	got=1;
                              if(k)
							  {
								  str2[j][k]='\0';
								j++;
							  }
				k=0;
			}
		}
		if(!got)str2[j][k]='\0';
		if(got)l2=j+1;
		else l2=j+2;
		printf("%2d. Length of longest match: %d\n",++cs,lcs_lnt(l1,l2));
	}
	return 0;
}













