#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define mabs(a) (((a)>0)?(a):-(a))
#define LL long long

#define SIZE 500001
int pr[80600];
bool p[SIZE];

int gene(int n)
{
	int i,j;
	for(i=3;i*i<=n;i+=2)
		if(!p[i/2])
			for(j=i*i;j<n+1;j+=(2*i))
				p[j/2]=1;

	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
		if(!p[i])
			pr[j]=i*2+1,j++;

    return j;
}

vector<int> revp;
int freq[80000],m;
int tree[2][80000];
map<int,int> mp;

int read(int idx,int is)
{
	int sum=0;
	while(idx>0)
		sum+=tree[is][idx],
		idx-=(idx & -idx);
	return sum;
}

void update(int idx,int is,int val)
{
	while(idx<=m)					//m->Maxval
		tree[is][idx]+=val,
		idx+=(idx & -idx);
}

int find(int cumfreq,int is,int bitmask)
{
	int idx=0;
	while(bitmask && idx<m)
	{
		int tx=idx+bitmask;
		bitmask >>= 1;
		if(tx>m)
			continue;
		if(cumfreq==tree[is][tx])
			return tx;
		else if(cumfreq>tree[is][tx])
			idx=tx,
			cumfreq-=tree[is][tx];
		
	}
	return (cumfreq? -1 : idx) ;
}

int main()
{
	m=gene(SIZE*2);
	int i,j,q;
	char s[100];
	
	revp.clear();
	mp.clear();
	
	for(i=0;i<m;i++)
	{ 
		sprintf(s,"%d",pr[i]);
		reverse(s,s+strlen(s));
		for(j=strlen(s);j<7;j++)
			s[j]='0';
		s[j]=0;
		sscanf(s,"%d",&j);
		revp.push_back(j);
	}
	
	sort(revp.begin(),revp.end());
	
	for(i=0;i<m;i++)
	{
		mp[revp[i]]=i;
		int cnt=0,temp=revp[i];
		for(j=0;j<m && pr[j]*pr[j]<=temp;j++)
			while(temp%pr[j]==0)
				temp/=pr[j],cnt++;
		if(temp!=1)
			cnt++;
		freq[i]=cnt;
	}
	
	for(i=0;i<m;i++)
		update(i+1,0,freq[i]),
		update(i+1,1,1);
	int b;
	i=0;
	while((1<<i)<=m)
		b=1<<i,i++;
	
	while(scanf("%s%d",s,&q)==2)	
	{
		if(s[0]=='q')
		{
			i=find(q+1,1,b);
			j=read(i,0);
			printf("%d\n",j);
		}
		else
		{
			i=mp[q];
			update(i+1,0,-freq[i]);
			update(i+1,1,-1);
		}
	}
	return 0;
}