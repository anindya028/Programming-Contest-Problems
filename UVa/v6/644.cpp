#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
	char s[20][20];
	int i,flag,n,j,cs=0;
	string ss;
	map<string,int> mp;
	while(scanf("%s",s[0])==1)
	{
		flag=1;
		mp.clear();
		mp[s[0]]=0;
		n=1;
		while(scanf("%s",s[n])==1 && strcmp(s[n],"9"))
			mp[s[n]]=n,n++;
		for(i=0;i<n && flag;i++)
		{
			ss="";
			for(j=0;j<strlen(s[i])-1;j++)
			{
				ss+=s[i][j];
				if(mp.find(ss)!=mp.end())
					flag=0;
			}
		}
		if(flag)
			printf("Set %d is immediately decodable\n",++cs);
		else
			printf("Set %d is not immediately decodable\n",++cs);
	}
	return 0;
}
