#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
	char buf[1005],s[105],key[105];
	int t;
	gets(buf);
	sscanf(buf,"%d",&t);
	while(t--)
	{
		gets(buf);
		gets(key);
		int bs=0,db,i;
		vector<char> vc;
		int got[30]={0};
		while(sscanf(buf+bs,"%s%n",s,&db)==1)
		{
			bs+=db;
			if(strlen(key)!=strlen(s))
				continue;
			int v=(-key[0]+s[0]+26)%26;
			int ok=1;
			for(i=1;key[i];i++)
				if((-key[i]+s[i]+26)%26!=v)
				{
					ok=0;
					break;
				}
			if(ok && !got[v])
				vc.push_back('a'+v),got[v]=1;
		}
		sort(vc.begin(),vc.end());
		for(i=0;i<vc.size();i++)
			printf("%c",vc[i]);
		printf("\n");
	}
	return 0;
}