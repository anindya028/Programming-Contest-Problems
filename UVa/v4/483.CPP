#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
        char temp;
	while(i<j)
	{
		temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
void main()
{
	char s[1000000],b[size][size],c[size][size];
        int i,j,m,k;
	while(gets(s))
	{
		if(s[0]==EOF)break;
		for(i=0,j=0,m=0,k=0;s[i];i++,m++)
 		{
			if(s[i]!=' '&&s[i]!='\t')b[j][m]=s[i];
			else
			{
                        	b[j][m]=NULL;
				j++;
				m=-1;
			}
		}
                b[j][m]=NULL;
		for(k=0;k<=j;k++)
 		{
       			rev(b[k]);
       			printf("%s",b[k]);
       			if(k!=j)printf("%c",' ');
		}
                printf("\n");
        }
}













