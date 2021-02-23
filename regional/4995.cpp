#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<string,string> mp;
	mp["HELLO"]="ENGLISH";
	mp["HOLA"]="SPANISH";
	mp["HALLO"]="GERMAN";
	mp["BONJOUR"]="FRENCH";
	mp["CIAO"]="ITALIAN";
	mp["ZDRAVSTVUJTE"]="RUSSIAN";
	char got[1000];
	string ss;
	int cs=0;
	while(scanf("%s",got)==1 && got[0]!='#')
	{
		ss=got;
		if(mp.find(ss)==mp.end())
			printf("Case %d: UNKNOWN\n",++cs);
		else
			printf("Case %d: %s\n",++cs,mp[ss].c_str());
	}
	return 0;
}