#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define N 100000050
unsigned long prime[N / 64];
#define gP(n) (prime[(n)>>6]&(1<<(((n)>>1)&31)))
#define rP(n) (prime[(n)>>6]&=~(1<<(((n)>>1)&31)))

void sieve()
{
    memset( prime, -1, sizeof( prime ) );
    unsigned long i,i2,j;
    unsigned long sqrtN = ( unsigned long )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        i2 = i + i;
        for( j = i * i; j < N; j += i2 ) rP( j );
    }
}

int num[10005],cum[10005];

int main()
{
	sieve();
	int n,t,st,nd;
	register int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cum[0]=0;
		nd=1000000,st=1;
		for(i=1;i<=n;i++)
			scanf("%d",&num[i]),cum[i]=cum[i-1]+num[i];
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if( ((cum[j]-cum[i-1])%2 && gP(cum[j]-cum[i-1])) || cum[j]-cum[i-1]==2)
					if(j-i<nd-st)
						nd=j,st=i;
		if(nd<=n)
		{
			printf("Shortest primed subsequence is length %d:",nd-st+1);
			for(i=st;i<=nd;i++)
				printf(" %d",num[i]);
			printf("\n");
		}
		else
			printf("This sequence is anti-primed.\n");
	}
	return 0;
}