#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//#define Long __int64
//#define Long long long

long long mem[2005][2005]; //initialized to -1

long long c(int n, int k) 
{ 
   if (n == k) return 1; 
   if (k == 0) return 1; 
   if (mem[n][k] != -1) return mem[n][k]; 
   return mem[n][k] = c(n - 1, k) + c(n - 1, k - 1); 
}

int main()
{
	unsigned long long ans,n,v,j,k;
	for(j=0;j<2005;j++)
		for(k=0;k<2005;k++)
			mem[j][k]=-1;
	while(scanf("%llu%llu",&n,&v)==2)
	{
		if(!n && !v)break;
        		k=v-1;
		if((n+v-1)%2==(v-1)%2)
		{
			j=v+1;
			ans=1;
                		}
		else
		{
			j=v+2;
			ans=v;
                		}
		for(;j<=(n+v-1);j+=2)
		{
            ans+=c(j,k);
		}
		printf("%llu\n",ans);
	}
	return 0;
}











