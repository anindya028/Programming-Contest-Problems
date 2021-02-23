#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char given[100];
char ori[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"};
char mir[]={"A***3**HIL*JM*O***2TUVWXY51SE*Z**8*"};
int  len;
int ispalin(void)
{
	int i,j;
	i=0,j=len-1;
	while(i<j)
	{
		if(given[i]!=given[j])return 0;
		i++;
		j--;
	}
	return 1;
}
int ismirror(void)
{
	int i,j;
	i=0,j=len-1;
	while(i<j)
	{
		if(isdigit(given[i]))
		{
			if(mir[given[i]-'0'+25]!=given[j])return 0;
			i++;
			j--;
		}
		else
		{
			if(mir[given[i]-'A']!=given[j])return 0;
			i++;
			j--;
		}
	}
	if(len%2)
	{
		if(isdigit(given[(int)len/2]))
		{
			if(mir[given[(int)len/2]-'0'+25]!=given[(int)len/2])return 0;
		}
		else
		{
			if(mir[given[(int)len/2]-'A']!=given[(int)len/2])return 0;
		}
	}
	return 1;
}
int main()
{
	int ispal,ismir;
	while(scanf("%s",given)==1)
	{
		len=strlen(given);
		ispal=ispalin();
		ismir=ismirror();
		if(ismir&&ispal)printf("%s -- is a mirrored palindrome.\n\n",given);
		else if(ismir)printf("%s -- is a mirrored string.\n\n",given);
		else if(ispal)printf("%s -- is a regular palindrome.\n\n",given);
		else printf("%s -- is not a palindrome.\n\n",given);
	}
	return 0;
}













