#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[1000];
      int  *freq,i,max;
	while(gets(s))
	{
		if(s[0]==EOF)break;
                freq=(int *)calloc(128,sizeof(int));
		for(i=0,max=0;s[i];i++)
			if(isalpha(s[i]))
			{
				freq[s[i]]++;
				if(freq[s[i]]>max)max=freq[s[i]];
			}
		for(i=0;i<128;i++)
			if(freq[i]==max)printf("%c",i);
		printf(" %d\n",max);
                free(freq);
	}
	return 0;
}













