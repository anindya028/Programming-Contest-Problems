#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define size 100
int main()
{
	long n,i,*freq,max=1,j;
	char s[1000];
        freq=(long *)calloc(26,sizeof(long));
	scanf("%ld",&n);
	for(i=0;i<=n;i++)
	{
		gets(s);
		for(j=0;s[j];j++)
		{
			if(islower(s[j]))
			{
				freq[s[j]-'a']++;
				if(freq[s[j]-'a']>max)max=freq[s[j]-'a'];
                        }
			else if(isupper(s[j]))
			{
				freq[s[j]-'A']++;
				if(freq[s[j]-'A']>max)max=freq[s[j]-'A'];
                        }
                }
	}
	for(;max;max--)
	{
		for(i=0;i<26;i++)
		{
			if(freq[i]==max)printf("%c %ld\n",'A'+i,max);
		}
	}
	free(freq);
	return 0;
}













