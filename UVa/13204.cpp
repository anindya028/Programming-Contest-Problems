#include<stdio.h>
#include<algorithm>

using namespace std;

#define myabs(a) (a) > 0 ? (a) : -(a)

int num[105];

int main(){
	int n;
	while(scanf("%d", &n) == 1) {
		int i;
		for(i = 1; i <= n; i++)
			num[i] = i;
		int cnt = 0;
		do {
			int sum = 0;
			for (i = 1; i <= n; i++)
				sum += myabs(num[i] - i);
			if(sum == ((n*n)/2))
				cnt++;
		}while(next_permutation(num+1,num+n+1));
		printf("%d\n", cnt);
	}
	return 0;
}