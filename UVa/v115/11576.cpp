#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
using namespace std;	

int main()
{
	int n,k,w,i,j,ans;
	char s[105][105];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&k,&w);
		for(i=0;i<w;i++)
			scanf("%s",s[i]);
		ans=k;
		for(i=1;i<w;i++)
		{
			string s1=s[i-1],s2=s[i];
			for(j=0;j<k;j++)
				if(s1.substr(j,k-j)==s2.substr(0,k-j))
					break;
			ans+=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}