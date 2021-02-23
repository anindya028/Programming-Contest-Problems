#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main()
{
	int t,i;
	char buf[2005];
	gets(buf);
	sscanf(buf,"%d",&t);
	while(t--)
	{
		gets(buf);
		int freq[256]={0},mx=-1;
		for(i=0;buf[i];i++)
			if(isalpha(buf[i]))
				freq[tolower(buf[i])]++;
		for(i=0;i<256;i++)
			if(freq[i]>mx)
				mx=freq[i];
		for(i=0;i<256;i++)
			if(mx==freq[i])
				printf("%c",i);
		printf("\n");
	}
	return 0;
}