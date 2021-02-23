#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	char s1[1005],s2[1005];
	int i,*fs1,*fs2,j,n;
	while(gets(s1))
	{
		gets(s2);
		fs1=(int *)calloc(130,sizeof(int));
		fs2=(int *)calloc(130,sizeof(int));
		for(i=0;s1[i];i++)fs1[tolower(s1[i])]++;
		for(i=0;s2[i];i++)fs2[tolower(s2[i])]++;
		for(i=95;i<129;i++)
		{
			if(fs1[i]&&fs2[i])
			{
				n=min(fs1[i],fs2[i]);
				for(j=0;j<n;j++)printf("%c",i);
			}
		}
		printf("\n");
		free(fs1);
		free(fs2);
        }
	return 0;
}













