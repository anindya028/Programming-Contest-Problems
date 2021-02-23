#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int code[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	int *freq,i,j;
	char s[50],ans[50];
	while(scanf("%s",s)==1)
	{
		if(s[0]==EOF)break;
		freq=(int *)calloc(7,sizeof(int));
		for(i=0,j=0;s[i];i++)
		{
			if(code[s[i]-'A'])
			{
				if(!freq[code[s[i]-'A']])
				{
					ans[j]=code[s[i]-'A']+'0';
					j++;
					free(freq);
					freq=(int *)calloc(7,sizeof(int));
					freq[code[s[i]-'A']]++;
				}
				
			}
			else
			{
				free(freq);
				freq=(int *)calloc(7,sizeof(int));
			}
		}
		ans[j]='\0';
		printf("%s\n",ans);
		free(freq);
	}
	return 0;
}













