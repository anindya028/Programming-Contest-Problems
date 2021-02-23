#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,i,found=1,j,printed=0,k;
	char alpha[300],plain[300],buf[10000];
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		if(i)printf("\n");
		gets(alpha);
		gets(plain);
		printf("%s\n%s\n",plain,alpha);
		while(gets(buf) && *buf)
		{
			for(k=0;buf[k];k++)
			{
				found=0;
				for(j=0;alpha[j];j++)
					if(alpha[j]==buf[k])
					{
						found=1;
						printf("%c",plain[j]);
						break;
					}
				if(!found)printf("%c",buf[k]);
			}
			printf("\n");
		}
	}
	return 0;
}













