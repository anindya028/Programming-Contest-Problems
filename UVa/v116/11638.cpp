#include<stdio.h>
#include<math.h>

int th[4];

int main()
{
	int cs,T,m,s,i,c,n,j;
	scanf("%d",&T);
	for(cs=0;cs<T;cs++)
	{
		scanf("%d%d",&m,&s);
		for(i=0;i<4;i++)
			scanf("%d",&th[i]);
		scanf("%d",&c);
		int act[4]={0},dir[4]={0},is[4]={0};
		for(i=0;i<8;i++)
			if(i<4)
				act[i]=c & 1<<i;
			else
				dir[i-4]=c & 1<<i;
		long long cum=0;
		scanf("%d",&n);
		int t,temp,ok=0;
		for(j=0;j<n;j++)
		{
			scanf("%d%d",&t,&temp);
			cum+=t;
			if(cum<s)
				continue;
			if(!ok)
			{
				for(i=0;i<4;i++)
					if(act[i])
						is[i]|= (dir[i] && temp>th[i]) || (!dir[i] && temp<th[i]);
				ok=1;
				continue;
			}
			if( ((cum-s)/m) > ((cum-s-t)/m) )
			{
				for(i=0;i<4;i++)
					if(act[i])
						is[i]|= (dir[i] && temp>th[i]) || (!dir[i] && temp<th[i]);
			}
		}
		printf("Case %d:",cs+1);
		for(i=0;i<4;i++)
			if(!is[i])
				printf(" no");
			else
				printf(" yes");
		printf("\n");
	}
	return 0;
}