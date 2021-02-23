#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int *freq1,*freq2,i,flag,cs,j;
	long long n,num1,num2;
	char s1[15],s2[15];
	scanf("%d",&cs);
	for(j=0;j<cs;j++)
	{
		if(j)printf("\n");
		scanf("%lld",&n);
		num1=n;
		num2=1;
		while(1)
		{
			freq1=(int *)calloc(10,sizeof(int));
			freq2=(int *)calloc(10,sizeof(int));
			sprintf(s1,"%lld",num1);
			sprintf(s2,"%lld",num2);
			if(strlen(s1)>10)break;
			for(i=0,flag=1;s1[i] && flag;i++)
			{
				if(freq1[s1[i]-'0'])flag=0;
				else freq1[s1[i]-'0']=1;
			}
			for(i=0;s2[i] && flag;i++)
			{
				if(freq2[s2[i]-'0'])flag=0;
				else freq2[s2[i]-'0']=1;
			}
			if(flag)printf("%lld / %lld = %lld\n",num1,num2,n);
			num1+=n;
			num2++;
			free(freq1);
			free(freq2);
		}
	}
	return 0;
}













