#include<stdio.h>
/*
int mat[19683][27],temp[19683][27],i,j;

void calc()
{
	int m=19683,n=27;
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			mat[i][j]=i*n+j+1;
	int cnt=0;
	while(1)
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				temp[(i*n+j)%m][(i*n+j)/m]=mat[i][j];
		int ok=1;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				mat[i][j]=temp[i][j];
				if(mat[i][j]!=(i*n+j+1))
					ok=0;
			}
		cnt++;
		if(ok)
			break;
	}
	printf("%d\n",cnt);
}
*/
int gcd(int m,int n)
{
	if(!n)return m;
	return gcd(n,(m%n));
}

int main()
{
	int t,cs,m,n;
//	calc();
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&m,&n);	
		printf("Case %d: %d\n",cs+1,(m+n)/gcd(m,n));
	}
	return 0;
}