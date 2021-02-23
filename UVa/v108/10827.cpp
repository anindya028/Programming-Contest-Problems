#include<stdio.h>

int main()
{
	int mat[160][160],i,j,n,t,k,sum[160][160],ans,runsum,l,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&mat[i][j]);
		for(i=n;i<2*n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=mat[i-n][j];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j+n]=mat[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i+n][j+n]=mat[i][j];
		m=n;
		n+=n;
		
		for(i=0;i<n;i++)
			sum[i][0]=mat[i][0];
		ans=0;
		for(i=0;i<n;i++)
			for(j=1;j<n;j++)
				sum[i][j]=sum[i][j-1]+mat[i][j];
		for(i=0;i<n;i++)
			for(j=i;j<n;j++)
				if(j-i<m)
				{
					runsum=0;
					l=0;
					int flag=0;
					for(k=0;k<n;k++)
					{
						if(!i)
						{
							runsum+=sum[k][j];
							if(l>=m)
							{
								runsum-=sum[k-l][j],l--;
								int now=0,g=l,h=-1,f=1000000;
								while(g)
								{
									now+=sum[k-g][j],g--;
									if(now<f)
										f=now,h=g;
								}
								if(runsum-f>runsum)
									runsum-=f,l=h;
							}
						}
						else
						{
							runsum+=(sum[k][j]-sum[k][i-1]);
							if(l>=m)
							{
								runsum-=(sum[k-l][j]-sum[k-l][i-1]),l--;
								int now=0,g=l,h=-1,f=1000000;
								while(g)
								{
									now+=(sum[k-g][j]-sum[k-g][i-1]),g--;
									if(now<f)
										f=now,h=g;
								}
								if(runsum-f>runsum)
									runsum-=f,l=h;
							}
						}
						l++;
						if(runsum>ans)
							ans=runsum;
						if(runsum<0)
							runsum=0,l=0;
					}
				}

		printf("%d\n",ans);
	}
	return 0;
}
