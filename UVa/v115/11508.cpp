#include<stdio.h>
#include<string.h>

#define SIZE 100009
char str[7*SIZE];
int arr[SIZE],res[SIZE];
bool used[SIZE], rused[SIZE];
int main(){
	int i,j,n,a;
	char *p;
	bool hacked;
	
	while(gets(str)){
		if(strcmp(str, "0") == 0) break;
		
		p = strtok(str, " ");
		i = 0;
		while(p){
			sscanf(p, "%d",&a);
			arr[i] = a;
			++i;
			p = strtok(NULL, " ");
		}
		
		n = i;
		
		memset(rused, 0, sizeof(rused));
		memset(used, 0, sizeof(used));
		hacked = false;
		
		for(i=0; i<n; ++i){
			if( arr[i] >= n){
				hacked = true;
				break;
			}
			else {
				if(rused[arr[i]] == 0){
					res[arr[i]] = arr[i];
					rused[ arr[i] ] = 1;
					used[i] = 1;
				}
			}
		}
		
		if(!hacked)
		for(i=j=0; i<n; ++i){
			if(used[i] == 0){
				while( rused[j]) ++j;
				res[j] = arr[i];
				rused[j] = 1;
			}
		}
		
		if(hacked){
			puts("Message hacked by the Martians!!!");
		}
		else {
			for(i=0; i<n; ++i){
				if(i) putchar(' ');
				printf("%d", res[i]);
			}
			puts("");
		}
	}
	
	return 0;
}
