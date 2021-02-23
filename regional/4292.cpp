#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>

using namespace std;

int req[]={6,2,5,5,4,5,6,3,7,6};

bool comp(string a,string b)
{
	if(a.size()==b.size())
		return a<b;
	else
		return a.size()<b.size();
}

string dp[105];

string make(int n)
{
	if(!n)
		return "";
	if(n<0)
		return "ZZ";
	if(dp[n]!="ZZ")
		return dp[n];
	int i;
	for(i=0;i<=9;i++)
	{
		char s[10];
		sprintf(s,"%d",i);
		string now=s;
		string got=make(n-req[i]);
		if(got=="ZZ")
			continue;
		now+=got;
		if(dp[n]=="ZZ" || comp(now,dp[n]))
			dp[n]=now;
	}
	return dp[n];
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			dp[i]="ZZ";
		string ans="999999999999999999999999999999999999999999999999999999999999999999999999";
		for(i=1;i<=9;i++)
		{
			char s[10];
			sprintf(s,"%d",i);
			string now=s;
			string got=make(n-req[i]);
			if(got=="ZZ")
				continue;
			now+=got;
			if(comp(now,ans))
				ans=now;
		}
		printf("%s ",ans.c_str());
		if(n==2)
			printf("1");
		else if(n%2)
		{
			printf("7");
			for(i=1;i<=(n-3)/2;i++)
				printf("1");
		}
		else
			for(i=1;i<=(n/2);i++)
				printf("1");
		printf("\n");
	}
	return 0;
}