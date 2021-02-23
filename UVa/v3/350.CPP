#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int z,l,i,m,prev,len,cs=0,*freq;
	while(scanf("%d%d%d%d",&z,&i,&m,&l)==4)
	{
		if(!z && !l && !m)break;
		freq=(int *)calloc(10000,sizeof(int));
		prev=l;
		len=0;
		freq[prev]=1;
		while(1)
		{
			prev=(((z%m)*(prev%m))+(i%m))%m;
			if(prev==l)
			{
				len++;
				break;
			}
			if(freq[prev])break;
			len++;
			freq[prev]=1;
		}
		printf("Case %d: %d\n",++cs,len);
		free(freq);
	}
	return 0;
}













