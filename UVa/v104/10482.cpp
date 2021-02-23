#include<stdio.h>
#include<string.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Foro(i,a) For(i,0,a)
#define mem(a) memset(a,0,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

int old[650][650],now[650][650];

int main()
{
	int t,n,sum,i,j,k,mn,num[40],cs;
	scanf("%d",&t);
	Foro(cs,t)
	{
		mn=100000000;
		scanf("%d",&n);
		sum=0;
		Foro(i,n)
			scanf("%d",&num[i]),sum+=num[i];
		mem(old);
		mem(now);
		old[0][0]=1;
		mn=100000000;
		Foro(i,n)
		{
			Fore(j,0,sum)
				for(k=sum;k>=0;k--)
					if(old[j][k])
						if(k+num[i]<=sum)
						{
							int a=j,b=k+num[i],c=sum-a-b;
							int d=Max(a,Max(b,c))-Min(a,Min(b,c));
							mn=Min(mn,d);
							now[a][b]=1;
						}
			Fore(j,0,sum)
				for(k=sum;k>=0;k--)
					if(old[k][j])
						if(k+num[i]<=sum)
						{
							int a=j,b=k+num[i],c=sum-a-b;
							int d=Max(a,Max(b,c))-Min(a,Min(b,c));
							mn=Min(mn,d);
							now[b][a]=1;
						}
			Fore(j,0,sum)
				Fore(k,0,sum)
					old[j][k]= now[j][k] || old[j][k];
			mem(now);
		}
		printf("Case %d: %d\n",cs+1,mn);
	}
	return 0;
}
