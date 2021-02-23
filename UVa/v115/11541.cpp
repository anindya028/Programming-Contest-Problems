#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	int t,cs,i,j,k,n;
	char s[1000];
	string ss;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%s",s);
		ss="";
		for(i=0;s[i];)
		{
			j=i+1;
			n=0;
			while(s[j]>='0' && s[j]<='9')
				n=n*10+(s[j]-'0'),j++;
			for(k=0;k<n;k++)
				ss+=s[i];
			i=j;
		}
		printf("Case %d: %s\n",cs+1,ss.c_str());
	}
	return 0;
}
