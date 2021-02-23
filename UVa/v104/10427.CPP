#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int cum[11],num[11],n,ans,i;
	char s[15];
	cum[0]=0;
	cum[1]=9;
	cum[2]=189;
	cum[3]=2889;
	cum[4]=38889;
	cum[5]=488889;
	cum[6]=5888889;
	cum[7]=68888889;
	cum[8]=788888889;
	cum[9]=3888888889;
	num[0]=0;
	num[1]=9;
	num[2]=99;
	num[3]=999;
	num[4]=9999;
	num[5]=99999;
	num[6]=999999;
	num[7]=9999999;
	num[8]=99999999;
	num[9]=999999999;
	while(scanf("%d",&n)==1)
	{
		for(i=0;cum[i]<n;i++);
		n-=cum[i-1];
		ans=num[i-1];
		if(n<i)ans++;
		else if(n%i==0)ans+=n/i;
		else ans+=(n/i)+1;
		sprintf(s,"%d",ans);
		printf("%c\n",s[(n%i-1+i)%i]);
	}
	return 0;
}













