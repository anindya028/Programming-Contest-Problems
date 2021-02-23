#include<stdio.h>

#define MAXN 10000005

char isPrime[MAXN];
long long primes[MAXN/10];

int genePrime() {
	int i, j;
	for (i = 2; i*i < MAXN; i++) {
		if (!isPrime[i]) {
			for (j = i * i; j < MAXN; j += i) {
				isPrime[j] = 1;
			}
		}
	}
	for (i = 2, j = 0; i < MAXN; i++) {
		if (!isPrime[i]) {
			primes[j] = i;
			j++;
		}
	}
	return j;
}

int main() {
	int numPrime = genePrime();
	long long n;
	while (scanf("%lld", &n) == 1 && n > 1) {
		int cnt = 0;
		for ( int i = 0; i < numPrime && primes[i]*primes[i] <= n; i++) {
			if (n % primes[i] == 0) {
				while (n % primes[i] == 0) {
					n /= primes[i];
					cnt++;
				}
			}
		}
		if (n > 1) 
			cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}