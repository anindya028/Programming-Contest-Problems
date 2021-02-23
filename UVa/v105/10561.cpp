#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int grundy[205];

int make(int n)
{
	if(n<=0)
		return 0;
	
	if(grundy[n]!=-1)
		return grundy[n];
	
	int i;
	set<int> now;
	for(i=1;i<=n;i++)
		now.insert(make(i-3)^make(n-i-2));
	i=0;
	while(now.find(i)!=now.end())
		i++;
	grundy[n]=i;
	return grundy[n];
}

int main()
{
	int t,i,k,len,j;
	char s[205];
	mem(grundy,-1);
	scanf("%d",&t);
	vector<int> got;
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s);
		got.clear();
		for(i=0;s[i];i++)
		{
			if(s[i]=='X')
				continue;
			s[i]='X';
			int f=0;
			for(j=0;j<len-2;j++)
				if(s[j]=='X' && s[j]==s[j+1] && s[j+1]==s[j+2])
					f=1;
			if(f)
			{
				got.push_back(i+1);
				s[i]='.';
				continue;
			}
			
			for(j=0;j<len-2;j++)
				if(s[j]=='X' && s[j+1]=='.' && s[j+2]=='X')
					f=1;
				else if(s[j]=='X' && s[j+2]=='.' && s[j+1]=='X')
					f=1;
				else if(s[j]=='.' && s[j+1]=='X' && s[j+2]=='X')
					f=1;
			
			if(f)
			{
				s[i]='.';
				continue;
			}
			
			k=0;
			
			int last=0;
			j=0;
			while(s[j])
			{
				while(s[j]=='X')
					j++;
				if(!s[j])
					break;
				last=j;
				while(s[j]=='.')
					j++;
				if(!last || !s[j])
					k ^= make(j-last-2);
				else
					k ^= make(j-last-4);
			}

			if(!k)
				got.push_back(i+1);
			s[i]='.';
		}
		if(got.size()==0)
			printf("LOSING\n\n");
		else
		{
			printf("WINNING\n");
			printf("%d",got[0]);
			for(i=1;i<got.size();i++)
				printf(" %d",got[i]);
			printf("\n");
		}
	}
	return 0;
}
