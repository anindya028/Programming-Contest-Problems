#include<stdio.h>
#include<string.h>

char str[25];
int cnt[26];

int main(){
	int t;
	int r, c, m, n, a,b,i,j,mx,x;
	
	scanf("%d", &t);
	for(x=1; x<=t; ++x){
		scanf("%d%d%d%d", &r, &c,&m, &n);
		memset(cnt, 0, sizeof(cnt));
		for(i=0; i<r; ++i){
			scanf("%s", str);
			for(j=0; str[j]; ++j){
				cnt[str[j] - 'A']++;
			}
		}
		
		mx = 0;
		for(i=0; i<26; ++i){
			if(cnt[i] > mx) mx = cnt[i];
		}
		
		int a =0, b = 0;
		for(i=0; i<26; ++i){
			if( cnt[i] == mx) a+= mx;
			else b+= cnt[i];
		}
		
		printf("Case %d: %d\n", x, a*m+b*n);
	}
	
	return 0;
}
