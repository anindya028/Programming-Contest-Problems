#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>

using namespace std;

long long ncr[105][105];
long long C(int n, int r) {
	if (n == r || r == 0) 
		return 1;
	if (ncr[n][r] != -1)
		return ncr[n][r];
	ncr[n][r] = C(n - 1, r) + C(n - 1, r - 1);
	return ncr[n][r];
}


int main() {
	int i, j, T, n;
	char line[1005], a[1005], b[1005];
	memset(ncr, -1, sizeof(ncr));
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%s", line);
		for (i = 0; line[i]; i++)
			if (!isalnum(line[i]))
				line[i] = ' ';
		sscanf(line, "%s%s%d", a, b, &n);
		printf("Case %d: %s", cs, a);
		if (n > 1)
			printf("^%d", n);
		for (i = 1; i < n; i++) {
			printf("+");
			long long v = C(n, i);
			printf("%lld*%s", v, a);
			if (n - i > 1)
				printf("^%d", n - i);
			printf("*%s", b);
			if (i > 1)
				printf("^%d", i);
		}
		printf("+%s", b);
		if (n > 1)
			printf("^%d", n);
		printf("\n");
	}	
	return 0;
}