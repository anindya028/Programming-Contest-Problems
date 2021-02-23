#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int num[1005];

int main()
{
	int n,i,j,v,u;
	while(scanf("%d",&n)==1)
	{
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		int qok = 1, sok = 1, pok = 1,cnt = 3;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j,&v);
			if(j==1)
				q.push(v),s.push(v),pq.push(v);
			else
			{
				if(qok)
				{
					if(q.empty())
					{
						qok = 0;
						cnt--;
					}
					else
					{
						u = q.front();
						q.pop();
						if(u!=v)
							qok = 0, cnt--;
					}
				}
				if(sok)
				{
					if(s.empty())
					{
						sok = 0;
						cnt--;
					}
					else
					{
						u = s.top();
						s.pop();
						if(u!=v)
							sok = 0, cnt--;
					}
				}
				if(pok)
				{
					if(pq.empty())
					{
						qok = 0;
						cnt--;
					}
					else
					{
						u = pq.top();
						pq.pop();
						if(u!=v)
							pok = 0, cnt--;
					}
				}
			}
		}
		if(cnt==1)
		{
			if(qok)
				printf("queue\n");
			if(sok)
				printf("stack\n");
			if(pok)
				printf("priority queue\n");
		}
		else if(cnt>1)
			printf("not sure\n");
		else
			printf("impossible\n");
	}
	return 0;
}