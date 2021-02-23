#include<stdio.h>
#include<string.h>

char s[10005][30];

int main()
{
	int t,i,n,j,k,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		i=ans=0;
		while(i<n)
		{
			int f[128]={0},cnt=1;
			for(k=0;s[i][k];k++)
				f[s[i][k]]++;
			for(j=i+1;j<n;j++)
			{
				int flag=0;
				for(k=0;s[j][k];k++)
					if(f[s[j][k]]==cnt)
					{
						flag=1;
						f[s[j][k]]++;
					}
				if(!flag)
					break;
				cnt++;
			}
			ans++;
			i=j;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}