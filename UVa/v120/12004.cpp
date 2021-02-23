#include<stdio.h>

int main() {
  long long n;
  int t, cs;
  scanf("%d", &t);
  for (cs = 1; cs <= t; cs++) {
    scanf("%lld", &n);
    long long ans = n * (n - 1);
    int a = 4;
    while (ans %2 == 0 && a > 1) {
      ans /= 2;
      a /= 2;
    }
    if (a == 1)
      printf("Case %d: %lld\n", cs, ans);
    else
      printf("Case %d: %lld/%d\n", cs, ans, a);
  }
  return 0;
}