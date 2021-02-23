#include<stdio.h>

void print(char ch,int n){
	int i;

	for(i=0; i<n; ++i) putchar(ch);
}
int main(){

	int n,m,i,j,ct =0,space,level,k;
	char toprint;

	//freopen("b.txt","w",stdout);
	//freopen()
	while(scanf("%d%d",&m,&n) && ( n||m)){
		ct++;
		printf("Triangular Museum %d\n",ct);

		if(m==1) m++;
		space = n*m-1;

		level = 1;

		for(i=j=0; i<m*n; ++i,++j){
			print(' ',space);

			for(k=0; k<level; ++k){
				if(k){
					print(' ', 2*(m-j-1));
				}

				putchar('/');

				if((i%m)==(m-1)){
					toprint = '_';
				}
				else toprint = ' ';
				print(toprint, 2*j);

				putchar('\\');

			}
			puts("");
			if( (i%m) == m-1) {
				level++;
				j = -1;
			}
			space--;
		}

		puts("");
	}

	return 0;
}