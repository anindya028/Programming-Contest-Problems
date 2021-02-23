#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int freq[1000][26],*ftemp;
int main()
{
	int i=0,j,count,k,flag;
	char temp[20];
	while(gets(temp) && temp[0]!='#')
	{
		for(j=0;temp[j];j++)freq[i][temp[j]-'a']++;
                i++;
	}
	while(gets(temp) && temp[0]!='#')
	{
		ftemp=(int *)calloc(26,sizeof(int));
                count=0;
		for(j=0;temp[j];j++)
		{
			if(islower(temp[j]))ftemp[temp[j]-'a']++;
		}
		for(j=0;j<i;j++)
		{
                	flag=1;
			for(k=0;k<26;k++)
			{
				if(freq[j][k]>ftemp[k])
				{
					flag=0;
					break;
				}
			}
			if(flag)count++;
		}
		printf("%d\n",count);
		free(ftemp);
	}
	return 0;
}













