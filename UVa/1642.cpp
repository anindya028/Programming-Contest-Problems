#include<stdio.h>
#include<algorithm>
#include<stack>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b)) 
#define MAXN 100000
#define LL long long

LL gcd(LL m, LL n) {
	if(n == 0) return m;
	return gcd(n, m%n);
}

LL num[MAXN + 5];

int main() {
	int t, n, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%lld", &num[i]);
		}
		
		stack< pair<LL, int> > s;
		s.push(make_pair(1, 0));
		LL ans = 0;
		for (i = 0; i < n; i++) {
			stack< pair<LL, int> > st;
			pair<LL, int> top_pli;
			do {
				top_pli = s.top();
				if (top_pli.first == 1)
					break;
				LL g = gcd(top_pli.first, num[i]);
				if (g == top_pli.first)
					break;
				s.pop();
				ans = MAX(ans, top_pli.first * (i - top_pli.second));
				top_pli.first = g;
				st.push(top_pli);
			}while(1);
			
			while(!st.empty()) {
				top_pli = st.top();
				st.pop();
				pair<LL, int> top_pli_prev;
				top_pli_prev = s.top();
				if (top_pli_prev.first != top_pli.first)
					s.push(top_pli);
			}
			
			ans = MAX(ans, num[i]);
			s.push(make_pair(num[i], i));
		}
		while(!s.empty())
		{
			pair<LL, int> top_pli = s.top();
			s.pop();
			ans = MAX(ans, top_pli.first * (i - top_pli.second));
		}

		printf("%lld\n", ans);
	}
	return 0;
}