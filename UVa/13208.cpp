#include<stdio.h>
#include<algorithm>
#include<stack>

using namespace std;

#define Min(a, b) ((a) < (b)? (a): (b))

int x[100005];
int h[100005];



int main() {
	int n, T, a;
	scanf("%d", &T);
	while( T-- ) {
		scanf("%d%d", &a, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);

		stack< pair<int, long long> > S;

		for (int i = 0; i <= n; i++)
			scanf("%d", &h[i]);

		S.push(make_pair(h[0], 0));
		S.push(make_pair(h[1], x[0]));

		for (int i = 2; i <= n; i++) {
			long long cur_x = x[i-1];
			while (S.size() > 1){
				pair<int, long long> now = S.top();
				if (now.first >= h[i]) {
					S.push(make_pair(h[i], cur_x));
					break;
				}
				else {
					S.pop();
					cur_x += now.second;
				}
			}
		}

		long long sum = 0;
		while(S.size() > 1) {
			pair<int, long long> now = S.top();
			printf("-->> %d %lld", now.first, now.second);
			if (S.size() == 2) {
				S.pop();
				pair<int, long long> prev = S.top();
				sum += ((long long)Min(now.first,prev.first) * (long long)now.second);	
			}
			else
				sum += ((long long)now.first * (long long)now.second);
			S.pop();
			
		}

		while(!S.empty()) S.pop();

		printf("%lld\n", sum * a);
	}
	return 0;
}
