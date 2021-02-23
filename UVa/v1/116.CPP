/*#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long __int64
//#define Long long long
#define Min(a,b) (((a)<(b))?(a):(b))

int main()
{
	Long mat[15][105],cost[15][105],d,ans;
	int i,j,k,r,c,parent[15][105],path[105],a,b,flag;
	while(scanf("%d%d",&r,&c)==2)
	{
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				scanf("%d",&k);
				mat[i][j]=k;
			}
		for(i=0;i<r;i++)
		{
			cost[i][0]=mat[i][0];
			parent[i][0]=i;
		}
		for(j=1;j<c;j++)
			for(i=0;i<r;i++)
			{
				d=Min(cost[(i-1+r)%r][j-1],Min(cost[i][j-1],cost[(i+1)%r][j-1]));
				cost[i][j]=d+mat[i][j];
				if(!i)
				{
					if(d==cost[i][j-1])
					{
						parent[i][j]=i;
						continue;
					}
				}
				if((i+1)==r)
				{
					if(d==cost[(i+1)%r][j-1])
					{
						parent[i][j]=(i+1)%r;
						continue;
					}
				}
				if(d==cost[(i-1+r)%r][j-1])
					parent[i][j]=(i-1+r)%r;
				else if(d==cost[i][j-1])
					parent[i][j]=i;
				else
					parent[i][j]=(i+1)%r;
				
			}
		ans=cost[0][c-1];
		k=0;
		for(i=1;i<r;i++)
			if(cost[i][c-1]<ans)
			{
				ans=cost[i][c-1];
				k=i;
			}
			else if(cost[i][c-1]==ans)
			{
				j=1;
				flag=0;
				a=i;
				b=k;
				while(j<=(c-1))
				{
					a=parent[a][c-j];
					b=parent[b][c-j];
					if(a<b && !flag)
						flag=1;
					else if(a>b && flag)
						flag=0;
					j++;
				}
				if(flag)
				{
					ans=cost[i][c-1];
					k=i;
				}
			}
		path[0]=k;
		i=1;
		while(i<c-1)
		{
			path[i]=parent[k][c-i];
			k=parent[k][c-i];
			i++;
		}
		path[i]=parent[k][c-i];
		printf("%d",path[c-1]+1);
		for(i=c-2;i>=0;i--)
			printf(" %d",path[i]+1);
		printf("\n%I64d\n",ans);
	}
	return 0;
}*/
#include<stdio.h>
#define INF 999999

long a[12][105];
long cost[12][105];
long next[12][105];
long c,r;

long min(long a,long b,long c)
{
    return a<b?a<c?a:c:b<c?b:c;
}

void print(int index,int col)
{
    if(col==c)
    {
        return;
    }
    if(col!=0)
    {
        printf(" ");
    }
    printf("%d",index+1);
    print(next[index][col],col+1);
    return;

}

int main(void)
{
    long i,j;
    //freopen("116.in","r",stdin);
    while(scanf("%ld%ld",&r,&c)==2)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%ld",&a[i][j]);
                cost[i][j]=INF;
            }
        }
        if(r==1)
        {
             for(i=0;i<c-1;i++)
            {
                printf("1 ");
            }
            printf("1\n");
            long t=0;
            for(i=0;i<c;i++)
            {
                t+=a[0][i];
            }
            printf("%ld\n",t);
            continue;
        }
        for(j=0;j<r;j++)
        {
            cost[j][c-1]=a[j][c-1];
        }

        for(j=c-2;j>=0;j--)
         {
            long p;
            p=min(cost[0][j+1],cost[1][j+1],cost[r-1][j+1]);
            cost[0][j]=a[0][j]+p;
            if(cost[0][j+1]==p)
            {
                next[0][j]=0;
            }
            else if(cost[1][j+1]==p)
            {
                next[0][j]=1;
            }
            else if(cost[r-1][j+1]==p)
            {
                next[0][j]=r-1;
            }
            for(i=1;i<(r-1);i++)
            {
                p=min(cost[i][j+1],cost[i-1][j+1],cost[i+1][j+1]);
                cost[i][j]=a[i][j]+p;
                if(cost[i-1][j+1]==p)
                {
                   next[i][j]=i-1;
                }
                else if(cost[i][j+1]==p)
                {
                    next[i][j]=i;
                }
                else if(cost[i+1][j+1]==p)
                {
                    next[i][j]=i+1;
                }
            }
            p=min(cost[0][j+1],cost[r-2][j+1],cost[r-1][j+1]);
            cost[r-1][j]=a[r-1][j]+p;
            if(cost[0][j+1]==p)
            {
                next[r-1][j]=0;
           }
            else if(cost[r-2][j+1]==p)
            {
                next[r-1][j]=r-2;
            }
            else if(cost[r-1][j+1]==p)
            {
                next[r-1][j]=r-1;
            }
        }
        long m=INF;
        long mindex;
        for(i=0;i<r;i++)
        {
            if(cost[i][0]<m)
            {
                m=cost[i][0];
                mindex=i;
            }
        }
        print(mindex,0);
        printf("\n%ld\n",m);
    }
    return 0;
}












