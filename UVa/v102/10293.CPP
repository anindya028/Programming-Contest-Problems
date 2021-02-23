#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	int *freq,i,len=0,flag=1,printed=0;
	freq=(int *)calloc(35,sizeof(int));
	char c;
	while((c=getchar())!=EOF)
	{
		if(isalnum(c))
		{
			len++;
			flag=1;
		}
		else if(c=='-'||c=='\''||c=='`'||c=='"')flag=0;
		else if(c=='#')
		{
			for(i=1;i<35;i++)
				if(freq[i])
				{
					printf("%d %d\n",i,freq[i]);
					printed=1;
				}
			flag=1;
			free(freq);
			freq=(int *)calloc(35,sizeof(int));
			len=0;
			if(printed)printf("\n");
			printed=0;
		}
		else //if(c==' '||c=='?'||c=='!'||c==','||c=='.')
		{
			if(flag)
			{
				freq[len]++;
				len=0;
				flag=1;
			}
		}
	}
        free(freq);
	return 0;
}













