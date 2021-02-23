#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,s[100][100],*col,*row,i,j,count,ci,ri;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		count=0;
		ri=ci=-1;
		col=(int *)calloc(n,sizeof(int));
		row=(int *)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&s[i][j]);
				row[i]+=s[i][j];
				col[j]+=s[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			if(col[i]%2)
			{
				count++;
				ci=i;
                        }
			if(row[i]%2)
			{
				count++;
				ri=i;
                        }
		}
		if(!count)printf("OK\n");
		else if(count==2)
		{
			if(ri>=0&&ci>=0)printf("Change bit (%d,%d)\n",ri+1,ci+1);
			else printf("Corrupt\n");
                }
		else printf("Corrupt\n");
	}
	return 0;
}













