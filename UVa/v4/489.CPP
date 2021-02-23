#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char s[1000],t[1000];
	int *sfreq,*tfreq,i,counts,count,round,flag;
	while(scanf("%d",&round)==1)
	{
		if(round==-1)break;
		scanf("%s",s);
		scanf("%s",t);
		sfreq=(int *)calloc(128,sizeof(int));
		tfreq=(int *)calloc(128,sizeof(int));
		for(i=counts=0;s[i];i++)
		{
			if(!sfreq[s[i]])
			{
				sfreq[s[i]]=1;
				counts++;
			}
		}
		for(i=count=flag=0;t[i] && counts;i++)
		{
			if(sfreq[t[i]] && !tfreq[t[i]])
			{
				counts--;
				tfreq[t[i]]=1;
                                if(!counts)flag=1;
			}
			else if(!tfreq[t[i]])
			{
				tfreq[t[i]]=1;
				count++;
			}
			if(count==7)
			{
				flag=2;
				break;
			}
		}
		if(flag==1)printf("Round %d\nYou win.\n",round);
		else if(flag==2)printf("Round %d\nYou lose.\n",round);
		else printf("Round %d\nYou chickened out.\n",round);
		free(sfreq);
		free(tfreq);
        }
	return 0;
}













