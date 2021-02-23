#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL long long

vector<char> vv;

LL fact[20];

LL make(int now)
{
	int f[130]={0};
	int i,n=0;
	for(i=0;i<vv.size();i++)
		if(!(now & 1<<i))
			f[vv[i]]++,n++;
	LL ret=fact[n];
	for(i=0;i<130;i++)
		ret/=fact[f[i]];
	return ret;
}

int main()
{
	int i,t,cs,j,now,m;
	LL n;
	fact[0]=1;
	for(i=1;i<16;i++)
		fact[i]=fact[i-1]*i;
	char s[50];
	vector<char> ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%s%lld",s,&n);
		vv.clear();
		ans.clear();
		if(strlen(s)==1 && n>1)
		{
			printf("Case %d: XXX\n",cs+1);
			continue;
		}
		int f[130]={0};
		for(i=0;s[i];i++)
			f[s[i]]++;
		int flag=0;
		char mid;
		m=strlen(s)/2,now=0;
		for(i=0;i<130;i++)
			if(f[i]%2)
			{
				if(flag)
					goto done;
				flag=1;
				mid=i;
				f[i]--;
				f[i]/=2;
				while(f[i])
					vv.push_back(i),f[i]--;
			}
			else
			{
				f[i]/=2;
				while(f[i])
					vv.push_back(i),f[i]--;
			}
		sort(vv.begin(),vv.end());
		
		for(i=0;i<m;i++)
		{
			int fr[130]={0};
			for(j=0;j<vv.size();j++)
			{
				if(fr[vv[j]] || (now & 1<<j))
					continue;
				fr[vv[j]]=1;
				LL cnt=make(now + (1<<j));
				if(cnt>=n)
				{
					ans.push_back(vv[j]);
					now+=(1<<j);
					break;
				}
				else
					n-=cnt;
			}
		}

done:
		if(ans.size()==m)
		{
			printf("Case %d: ",cs+1);
			for(i=0;i<ans.size();i++)
				printf("%c",ans[i]);
			if(flag)
				printf("%c",mid);
			reverse(ans.begin(),ans.end());
			for(i=0;i<ans.size();i++)
				printf("%c",ans[i]);
			printf("\n");
		}
		else
			printf("Case %d: XXX\n",cs+1);
	}
	return 0;
}
