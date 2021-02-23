#include<stdio.h>

int main()
{
	int n,m,i,j,t,k,sum,f;
	int mat[10][100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=sum=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&mat[i][j]),sum+=mat[i][j];
		if(sum%2)
		{
			printf("No\n");
			continue;
		}
		f=1;
		for(i=0;i<n && f;i++)
			for(j=i+1;j<n && f;j++)
			{
				sum=0;
				for(k=0;k<m;k++)
					if(mat[i][k] && mat[j][k])
						sum++;
				if(sum>1)
					f=0;
			}
		for(i=0;i<m;i++)
		{
			for(j=sum=0;j<n;j++)
				if(mat[j][i])
					sum++;
			f&=(sum==2);
		}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
