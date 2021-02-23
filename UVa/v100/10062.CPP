#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1001
struct seek
{
	long freq,value;
};
/*int sort_function(const void *a, const void *b)
{
	if(s[i].freq
}*/
int main()
{
	char s[size];
	seek *ans;
        int i,j=0,max,k;
	while(gets(s))
	{
		if(s[0]==EOF&&s[1]==NULL)break;
		if(j)printf("\n");
		ans=(seek *)calloc(128,sizeof(seek));
		for(i=0,max=0;s[i];i++)
		{
			ans[s[i]].freq++;
                        if(!max||max<ans[s[i]].freq)max=ans[s[i]].freq;
			ans[s[i]].value=s[i];
		}
		//qsort((void *)ans,128, sizeof(ans[0]),sort_function);
		for(i=1;i<=max;i++)
		{
			for(k=127;k>0;k--)
                        {
				if(ans[k].freq==i)printf("%ld %ld\n",ans[k].value,ans[k].freq);
                        }
		}
		j++;
        }
	return 0;
}













