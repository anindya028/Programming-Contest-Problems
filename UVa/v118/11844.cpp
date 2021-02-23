#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	int i,m,n,b,e,j,ma;
	char s[1000],t[1000];
	map<string,string> rules;
	string ss,tt;
	map<string,int> st,nd,now;
	map<string,int>::iterator it;
	while(scanf("%d%d%d%d",&m,&b,&e,&n)==4 && m && b && e)
	{
		rules.clear();
		st.clear();
		nd.clear();
		int f=0;
		while(m--)
		{
			scanf("%s%s",s,t),ss=s,tt=t;
			if(rules.find(ss)!=rules.end())
				if(rules[ss]!=tt)
				{
					f=-1;
					//goto done;
				}
			rules[ss]=tt;
		}
		while(b--)
		{
			scanf("%s%d",s,&j);
			st[s]=j;
		}
		while(e--)
		{
			scanf("%s%d",s,&j);
			nd[s]=j;
		}
		i=0;
		if(f==-1)
			goto done;
		now=st;
		ma=1;
		for(it=now.begin();it!=now.end();++it)
		{
			if(it->second==0)
				continue;
			if(nd.find(it->first)==nd.end() || nd[it->first]!=it->second)
			{
				ma=0;
				break;
			}
		}
		for(it=nd.begin();ma && it!=nd.end();++it)
			if(now.find(it->first)==now.end() || now[it->first]!=it->second)
			{
				ma=0;
				break;
			}
		if(ma)
		{
			f=1;
			goto done;
		}
		while(i<n)
		{
			st.clear();
			for(it=now.begin();it!=now.end();++it)
				if(rules.find(it->first)!=rules.end())
				{
					if(st.find(rules[it->first])!=st.end())
						st[rules[it->first]]+=it->second;
					else
						st[rules[it->first]]=it->second;
				}
				else
				{
					if(st.find(it->first)!=st.end())
						st[it->first]+=it->second;
					else
						st[it->first]=it->second;
				}
			i++;
			now=st;
			ma=1;
			for(it=now.begin();it!=now.end();++it)
			{
				if(it->second==0)
					continue;
				if(nd.find(it->first)==nd.end() || nd[it->first]!=it->second)
				{
					ma=0;
					break;
				}
			}
			for(it=nd.begin();ma && it!=nd.end();++it)
				if(now.find(it->first)==now.end() || now[it->first]!=it->second)
				{
					ma=0;
					break;
				}
			if(ma)
			{
				f=1;
				break;
			}
		}
done:;
		if(f==-1)
			printf("Protein mutations are not deterministic\n");
		else if(f==1)
			printf("Cure found in %d mutation(s)\n",i);
		else
			printf("Nostalgia for Infinity is doomed\n");

	}
	return 0;
}