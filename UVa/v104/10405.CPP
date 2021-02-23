//LCS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define max 1005
char str1[max],str2[max]; 
int lcs_length(void)
{
	int c[max][max]={0},b[max][max]={0},l1,l2;
	l1=strlen(str1)+1;
	l2=strlen(str2)+1;
	register int i,j;
	for(i=1;i<l1;i++)
	{
		for(j=1;j<l2;j++)
		{
			if(str1[i-1]==str2[j-1])
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
	while(gets(str1))
	{
		gets(str2);
		printf("%d\n",lcs_length());
	}
	return 0;
}













