#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char line1[100000],line2[100000],ch1,ch2,ans[100000];
	int cs,i,j,k,*freq1,*freq2,count,max1,max2;
	scanf("%d",&cs);
	gets(line1);
	for(i=0;i<cs;i++)
	{
		gets(line1);
		if(i)printf("\n");
		freq1=(int *)calloc(128,sizeof(int));
		freq2=(int *)calloc(128,sizeof(int));
		gets(line1);
		gets(line2);
		for(j=count=0;line1[j];++j)
			if(isalpha(line1[j]))
			{
				freq1[line1[j]]++;
				if(freq1[line1[j]]==1)
					count++;
			}
		for(j=0;line2[j];++j)
			if(isalpha(line2[j]))
				freq2[line2[j]]++;
		for(j=0;j<count;j++)
		{
			for(k=max1=0;line1[k];k++)
			{
				if(max1<freq1[line1[k]])
				{
					max1=freq1[line1[k]];
					ch1=line1[k];
				}
			}
			for(k=max2=0;line2[k];k++)
			{
				if(max2<freq2[line2[k]])
				{
					max2=freq2[line2[k]];
					ch2=line2[k];
				}
			}
			for(k=0;line2[k];k++)
			{
				if(line2[k]==ch2)
					ans[k]=ch1;
			}
			ans[k]='\0';
			freq1[ch1]=freq2[ch2]=0;
		}
		printf("%s\n",ans);
		free(freq1);
		free(freq2);
	}
	return 0;
}













