#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

int freq[10005];

int main()
{
	int n,m,i,j,d;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		memset(freq,0,sizeof(freq));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&d),freq[d]++;
		vector<int> st,nd;
		int mx1=-1,mx2=-1;
		for(i=1;i<=10000;i++)
			if(freq[i]>mx1)
				nd=st,mx2=mx1,st.clear(),st.push_back(i),mx1=freq[i];
			else if(freq[i]==mx1)
				st.push_back(i);
			else if(freq[i]>mx2)
				mx2=freq[i],nd.clear(),nd.push_back(i);
			else if(freq[i]==mx2)
				nd.push_back(i);
		sort(nd.begin(),nd.end());
		
		for(i=0;i<nd.size();i++)
			printf("%d ",nd[i]);
		printf("\n");
	}
	return 0;
}