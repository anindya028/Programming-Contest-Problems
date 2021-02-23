#include<stdio.h>

long p[200],i,j,max,count,n,c,d,a,b;

void ggg(){
	p[0]=1;
	p[1]=2;
	max=2;
	for(i=3;i<1000;i+=2){
		for(j=3;j*j<=i;j+=2)
			if(i%j==0)
				break;
		if(j*j>i)
			p[max++]=i;
	}
}

void main(){
	ggg();
	while(scanf("%ld%ld",&n,&c)==2){
		for(i=0;i<max && p[i]<=n;i++);
		count=i;
		printf("%ld %ld:",n,c);
		for(i=count/2-c+count%2 ; i<count/2+c && i<count; i++)
			if(i>=0 && i<count)
				printf(" %ld",p[i]);
		printf("\n\n");
	}
}
