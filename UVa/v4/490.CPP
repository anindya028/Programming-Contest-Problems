#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[100][105];
        int i=0,j,k,max=0,len;
	while(gets(s[i]))
	{
		len=strlen(s[i]);
                if(len>max)max=len;
		i++;
        }
	for(j=0;j<max;j++)
	{
		for(k=i-1;k>=0;k--)
		{
			if(s[k][j])printf("%c",s[k][j]);
			else
			{
				s[k][j+1]='\0';
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}













