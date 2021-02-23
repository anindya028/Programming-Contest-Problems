#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

int board[9][9];
int n,sol;
bool done()
{
	int i,j;
	for(i=0;i<n*n;i++)
		for(j=0;j<n*n;j++)
			if(board[i][j]==0)
				return false;
	return true;
}

bool solve()
{
	if(done())
	{
		sol++;
		if(sol>1)
			return true;
		else return false;
	}
	int i,j,k,p,q;
	int min=20,mini,minj;

	for(i=0;i<n*n;i++)
		for(j=0;j<n*n;j++)if(board[i][j]==0)
		{
			int av=n*n;
			bool b[10];
			memset(b,true,sizeof(b));

			//row check
			for(k=0;k<n*n;k++)
				if(board[i][k] && b[board[i][k]])
				{
					av--;
					b[board[i][k]]=false;
				}

			//col check
			for(k=0;k<n*n;k++)
				if(board[k][j] && b[board[k][j]])
				{
					av--;
					b[board[k][j]]=false;
				}

			//cell check
			int row=(i/n)*n;
			int col=(j/n)*n;
			for(p=row;p<row+n;p++)
				for(q=col;q<col+n;q++)
					if(board[p][q] && b[board[p][q]])
					{
						av--;
						b[board[p][q]]=false;
					}

			if(av<min)
			{
				min=av;
				mini=i;
				minj=j;
			}
		}
	if(min==0 || min == 20)
		return false;
	bool B[10];
	memset(B,true,sizeof(B));
	for(i=0;i<n*n;i++)
		if(board[mini][i])
			B[board[mini][i]]=false;
	for(i=0;i<n*n;i++)
		if(board[i][minj])
			B[board[i][minj]]=false;
	int r=(mini/n)*n;
	int c=(minj/n)*n;
	for(i=r;i<r+n;i++)
		for(j=c;j<c+n;j++)
			if(board[i][j])
				B[board[i][j]]=false;

	for(i=1;i<=n*n;i++)if(B[i])
	{
		board[mini][minj]=i;
		if(solve())
			return true;
		board[mini][minj]=0;
	}
	return false;

}
bool validate(void)
{
	int i,j,p,q;
	int *freq;
	for(i=0;i<9;i++)
	{
		freq=(int *)calloc(11,sizeof(int));
		for(j=0;j<9;j++)
			freq[board[i][j]]++;
		for(j=1;j<=9;j++)
			if(freq[j]>1)
			{
				free(freq);
				return false;
			}
		free(freq);
	}
	for(i=0;i<9;i++)
	{
		freq=(int *)calloc(11,sizeof(int));
		for(j=0;j<9;j++)
			freq[board[j][i]]++;
		for(j=1;j<=9;j++)
			if(freq[j]>1)
			{
				free(freq);
				return false;
			}
		free(freq);
	}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			freq=(int *)calloc(11,sizeof(int));
			for(p=i*3;p<(i+1)*3;p++)
				for(q=j*3;q<(j+1)*3;q++)
					freq[board[p][q]]++;
			for(p=1;p<=9;p++)
				if(freq[p]>1)
				{
					free(freq);
					return false;
				}
			free(freq);
		}
	return true;
}
int main()
{
	n=3;
	int i,j,cs=0;
	while(scanf("%d",&board[0][0])==1)
	{
		for(j=1;j<9;j++)
			scanf("%d",&board[0][j]);
		for(i=1;i<9;i++)
			for(j=0;j<9;j++)
				scanf("%d",&board[i][j]);
		if(!validate())
		{
			printf("Case %d: Illegal.\n",++cs);
			continue;
		}
		sol=0;
		if(!solve() && !sol)
			printf("Case %d: Impossible.\n",++cs);
		else
		{
			if(sol==1)
				printf("Case %d: Unique.\n",++cs);
			else
				printf("Case %d: Ambiguous.\n",++cs);
		}
	}
	return 0;
}













