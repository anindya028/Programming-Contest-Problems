#include<stdio.h>

char s[5005];
int f[130];
int ff[130];

int is_cool() {
	int i;
	for(i = 0; i < 130; i++)
		ff[i] = f[i] = 0;
	for (i = 0; s[i]; i++)
		f[s[i]]++;
	int diff = 0;
	
	for (i = 0; i < 130; i++) {
		ff[f[i]]++;
		if (f[i] > 0)
			diff++;
	}
	for (i = 1; i < 130; i++)
		if (ff[i] > 1)
			return 0;
	return diff > 1;  
}

int main(){
	int n, cs = 0;
	while(scanf("%d", &n) == 1){
		int count = 0;
		for ( int i = 0; i < n; i++) {
			scanf("%s", s);
			count += is_cool();
		}
		printf("Case %d: %d\n", ++cs, count);	
	}
	return 0;
}
