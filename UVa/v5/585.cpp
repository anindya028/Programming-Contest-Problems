#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

char s[105][250];
int dp1[105][250],dp2[105][250],left[105][250],right[105][250];

int main()
{
	int n,i,j,k,len,mx,cs=0;
	char ss[250];
	while(scanf("%d",&n)==1 && n)
	{
		len=2*n-1;
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",ss);
			for(j=0;j<i;j++)
				s[i][j]='#';
			for(k=0;ss[k];k++)
				s[i][j++]=ss[k];
			for(k=0;k<i;k++)
				s[i][j++]='#';
		}
		//left counting
		for(i=0;i<n;i++)
		{
			left[i][0]=0;
			for(j=1;j<len;j++)
				if(s[i][j-1]=='-')
					left[i][j]=left[i][j-1]+1;
				else
					left[i][j]=0;
		}
		//right counting
		for(i=0;i<n;i++)
		{
			right[i][len-1]=0;
			for(j=len-2;j>=0;j--)
				if(s[i][j+1]=='-')
					right[i][j]=right[i][j+1]+1;
				else
					right[i][j]=0;
		}

		//down triangle
		for(j=0;j<len;j++)
			dp1[n-1][j]= (s[n-1][j]=='-' && ( (j%2==0 && n%2) || (j%2 && n%2==0) )),
			mx=Max(mx,dp1[n-1][j]);
		for(i=n-2;i>=0;i--)
			for(j=0;j<len;j++)
				if(s[i][j]=='-')
				{
					k=Min(left[i][j],right[i][j]);
					k=Min(k,dp1[i+1][j]);
					if(i%2==0)
						if(j%2==0)
							k%2?k--:k;
						else
							k%2?k:k--;
					else
						if(j%2)
							k%2?k--:k;
						else
							k%2?k:k--;
					dp1[i][j]=k+1;
					mx=Max(mx,dp1[i][j]);
				}
				else
					dp1[i][j]=0;

		//up triangle
		for(j=0;j<len;j++)
			dp2[0][j]= (s[0][j]=='-' && ( j%2 )),
			mx=Max(mx,dp2[0][j]);
		for(i=1;i<n;i++)
			for(j=0;j<len;j++)
				if(s[i][j]=='-')
				{
					k=Min(left[i][j],right[i][j]);
					k=Min(k,dp2[i-1][j]);
					if(i%2==0)
						if(j%2)
							k%2?k--:k;
						else
							k%2?k:k--;
					else
						if(j%2==0)
							k%2?k--:k;
						else
							k%2?k:k--;
					dp2[i][j]=k+1;
					mx=Max(mx,dp2[i][j]);
				}
				else
					dp2[i][j]=0;
		
		printf("Triangle #%d\n",++cs);
		printf("The largest triangle area is %d.\n\n",mx*mx);
	}
	return 0;
}
