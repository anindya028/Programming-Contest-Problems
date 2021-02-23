#include<stdio.h>
#include<stack>
using namespace std;

int main()
{
	int b,x,y,now,temp,cs=0,i,flag[1000],carry,imp;
	while(scanf("%d%d%d",&b,&x,&y)==3)
	{
		for(i=0;i<b;i++)
			flag[i]=0;
		stack<int> st;
		flag[x]=1;
		st.push(x);
		now=x;
		carry=0;
		imp=0;
		while(1)
		{
			temp=(now*y+carry)%b;
			carry=(now*y + carry)/b;
			if(flag[temp] && !carry)
			{
				if(temp!=x)
					imp=1;
				break;
			}
			if(!carry)
				flag[temp]=1;
			now=temp;
			st.push(now);
		}
		if(imp)
			printf("Case %d: No solution\n",++cs);
		else
		{
			printf("Case %d:",++cs);
			while(!st.empty())
				printf(" %d",st.top()),st.pop();
			printf("\n");
		}
	}
	return 0;
}