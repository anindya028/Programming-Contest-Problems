#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
   int N,a,b;
   scanf("%d",&N);
   for(;N>0;N--){
      scanf("%d%d",&a,&b);
      if(a<b || (a+b)%2==1)
         printf("impossible\n");
      else
         printf("%d %d\n",(a+b)/2 , (a-b)/2);
   }
   return 0;
}


