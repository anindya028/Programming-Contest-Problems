#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
#define max 105
char str1[max][50],str2[max][50],lcs[max][50];
int lcswl;
void p_lcs(int b[max][max],int i,int j)
{
	if(i==0 || j==0)return;
	if(b[i][j]==1)
	{
		p_lcs(b,i-1,j-1);
		strcpy(lcs[lcswl++],str1[i-1]);
	}
	else if(b[i][j]==2)p_lcs(b,i-1,j);
	else p_lcs(b,i,j-1);
}
void lcs_lnt(int l1,int  l2)
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
	lcswl=0;
	p_lcs(b,l1-1,l2-1);
	j=c[l1-1][l2-1];
    printf("%s",lcs[0]);
	for(i=1;i<j;i++)printf(" %s",lcs[i]);
	printf("\n");
	return;
}
int main()
{
	char temp[50];
	int i,l1,l2,flag=1,j=0;
	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')continue;
		i=j=0;
		str1[i][0]=c;
		str1[i][1]='\0';
		while(c=getchar())
		{
			if(isspace(c))break;
			temp[j++]=c;
		}
		temp[j]='\0';
		strcat(str1[i++],temp);
		while(scanf("%s",temp)==1)
		{
			if(temp[0]=='#')break;
			if(i)strcpy(str1[i++],temp);
			else strcat(str1[i++],temp);
		}
	        l1=i+1;
        	i=0;
		while(scanf("%s",temp)==1)
		{
			if(temp[0]=='#')break;
			strcpy(str2[i++],temp);
		}
		l2=i+1;
		lcs_lnt(l1,l2);
		c=getchar();
	}
	return 0;
}













