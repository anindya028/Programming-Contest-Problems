//accepted

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int board[9][9];
int n;
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
		return true;
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

void print()
{
	int i,j;
	for(i=0;i<n*n;i++)
	{
		printf("%d",board[i][0]);
		for(j=1;j<n*n;j++)
			printf(" %d",board[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int t,i,j,cs=0;
	char s[20];
	
	while(scanf("%d",&n)==1)
	{
		if(cs)
			printf("\n");
		//input
		for(i=0;i<n*n;i++)
			for(j=0;j<n*n;j++)
				scanf("%d",&board[i][j]);
		if(solve())
			print();
		else
			printf("NO SOLUTION\n");
		cs++;
	}
	return 0;
}