#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int sig[15],i,j,n,ans,*freq,len,flag,cs=0,min;
	char s[50];
	while(gets(s))
	{
		len=strlen(s);
		for(i=j=0;i<=len-2;i+=3)
		{
			sig[j]=(s[i]-'0')*10+s[i+1]-'0';
			if(!j)min=sig[j];
			else if(sig[j]<min)min=sig[j];
			j++;
		}
		n=j;
		freq=(int *)calloc(3602,sizeof(int));
		for(i=flag=0;i<n;i++)
		{
			for(j=sig[i]-5+1;j<3602;j++)
			{
				freq[j]=1;
				if(j%sig[i]==0 && (j/sig[i])%2==0)j+=(sig[i]-5);
			}
		}
		for(i=min;i<3602;i++)
		{
			if(!freq[i])
			{
				ans=i-1;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("Set %d is unable to synch after one hour.\n",++cs);
			continue;
		}
		free(freq);
		printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",++cs,ans/60,ans%60);
	}
	return 0;
}













