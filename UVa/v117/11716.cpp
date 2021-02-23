#include<stdio.h>
#include<string.h>
#include<math.h>

char s[10005];

int main()
{
	int t,i,j;
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
		gets(s);
		int len=strlen(s);
		int n=floor(sqrt((double)len)+1e-6);
		if(n*n!=len)
		{
			printf("INVALID\n");
			continue;
		}
		for(j=0;j<n;j++)
			for(i=j;i<len;i+=n)
				printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}