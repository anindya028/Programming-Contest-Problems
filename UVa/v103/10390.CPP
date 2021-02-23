#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 10000
char s[size];
int freq[127];
struct con
{
	int offone;
	int righton;
}test[26];
int main()
{
	int i,n,j,totnum,totshare,num,bs,dbs;
	char garb,m,temp,guess;
	gets(s);
	sscanf(s,"%d",&n);
    
	gets(s);
	for(j=0;j<n;j++)
	{
		if(j)
			printf("\n");
		totnum=totshare=0;
		for(i=95;i<123;i++)
		{
			freq[i]=test[i-95].offone=test[i-95].righton=0;
		}
		if(gets(s))
		{
			for(i=0;s[i];i++)
			{
				freq[s[i]]++;
			}
			while(gets(s) && strlen(s)>0)
			{
				bs=0;
				sscanf(s+bs,"%c %n",&m,&dbs);
				bs+=dbs;
				if(sscanf(s+bs,"%c:%d%n",&guess,&num,&dbs)!=2)
					continue;
				bs+=dbs;
				totnum++;
				if(abs(freq[guess]-num)==1)
				{
					test[m-65].offone++;
					totshare++;
				}
				else if(freq[guess]==num)
				{
					test[m-65].righton++;
					totshare+=2;
				}
				while(sscanf(s+bs,",%c:%d%n",&guess,&num,&dbs)==2)
				{
					//if((scanf("%c%*c%d",&guess,&num)!=2)||(guess<95||guess>122))break;
					bs+=dbs;
					totnum++;
					if(abs(freq[guess]-num)==1)
					{
						test[m-65].offone++;
						totshare++;
					}
					else if(freq[guess]==num)
					{
						test[m-65].righton++;
						totshare+=2;
					}
				}
			}
			for(i=0;i<26;i++)
			{
				if(test[i].offone||test[i].righton)
				{
					printf("%c %.2lf\n",i+65,totnum*2.0*(test[i].offone+test[i].righton*2)/totshare);
				}
			}
		}
	}
	return 0;
}













