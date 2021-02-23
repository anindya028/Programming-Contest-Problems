#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define inf 1<<29
#define pii pair<int,int>
#define mod 1000000007

char A[102],B[102],C[302];
int is[102][102][302], cs;
pii dp[102][102][302];

pii make(int posa,int posb,int posc)
{
	if(!A[posa] && !B[posb])
		return make_pair(0,1);
	if(!C[posc])
		return make_pair(inf,0);

	if(is[posa][posb][posc] == cs)
		return dp[posa][posb][posc];

	is[posa][posb][posc] = cs;
	dp[posa][posb][posc] = make_pair(inf,0);

	pii temp;
	if(A[posa]==B[posb])
	{
		int i = posc;
		while(C[i] && C[i]!=A[posa])
			i++;
		if(C[i])
		{
			temp = make(posa+1,posb+1,i+1);
			temp.first++;
			if(temp.first < dp[posa][posb][posc].first)
				dp[posa][posb][posc] = temp;
		}
	}
	else
	{
		int i = posc;
		while(C[i] && C[i]!=A[posa])
			i++;
		if(C[i])
		{
			temp = make(posa+1,posb,i+1);
			temp.first++;
			if(temp.first < dp[posa][posb][posc].first)
				dp[posa][posb][posc] = temp;
		}

		i = posc;
		while(C[i] && C[i]!=B[posb])
			i++;
		if(C[i])
		{
			temp = make(posa,posb+1,i+1);
			temp.first++;
			if(temp.first < dp[posa][posb][posc].first)
				dp[posa][posb][posc] = temp;
			else if(temp.first == dp[posa][posb][posc].first)
				dp[posa][posb][posc].second = (dp[posa][posb][posc].second + temp.second)%mod;
		}
	}

	return dp[posa][posb][posc];
}

int main()
{
//	freopen("super.in","r",stdin);
//	freopen("super.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%s%s%s",A,B,C);
		pii got = make(0,0,0);
		printf("Case %d: %d\n",cs,got.second);

		if(got.first == inf)
		{
			printf("NOT FOUND\n");
			continue;
		}

		int v = got.first,i;
		int posa = 0, posb = 0, posc = 0;
		while(v)
		{
			if(A[posa] == B[posb])
			{
				while(C[posc] != A[posa])
					posc++;
				printf("%c",A[posa]);
				posa++, posb++, posc++;
			}
			else
			{
				i = posc;
				while(C[i] && C[i] != A[posa])
					i++;
				pii tempa = make(posa+1,posb,i+1);
				if(!C[i])
					tempa.first = inf;

				int j = posc;
				while(C[j] && C[j] != B[posb])
					j++;
				pii tempb = make(posa,posb+1,j+1);
				if(!C[j])
					tempb.first = inf;

				if(tempa.first+1 == v && tempb.first+1 == v)
				{
					if(A[posa]<B[posb])
						printf("%c",A[posa]),
						posa++, posc = i+1;
					else
						printf("%c",B[posb]),
						posb++, posc = j+1;
				}
				else
				{
					if(tempa.first+1 == v)
						printf("%c",A[posa]),
						posa++, posc = i+1;
					else
						printf("%c",B[posb]),
						posb++, posc = j+1;
				}
			}
			v--;
		}
		printf("\n");
	}
	return 0;
}