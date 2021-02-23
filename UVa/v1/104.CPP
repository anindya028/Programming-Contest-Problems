#include <stdio.h>

#define MAXN 21

void printPath(int trace[MAXN][MAXN][MAXN], int from, int to, int nChange){
  int intermediary;

  if (nChange==0) {
    printf("%d ",from+1);
    return;
  }

  intermediary = trace[nChange][from][to];
  printPath(trace,from,intermediary,nChange-1);
  printf("%d ",intermediary+1);
}

void main(){
  float cur[MAXN][MAXN][MAXN], temp;
  int trace[MAXN][MAXN][MAXN];
  int i,j,k,n,nChange, arbitrageFound;

  while(scanf("%d",&n)!=EOF){
    arbitrageFound = 0;

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (i==j) cur[0][i][j] = 1.;
        else scanf("%f",&cur[0][i][j]);

    for (nChange=1; nChange<=n; nChange++){
      /* Build table for [nChange][currencyFrom][currencyTo]
         using Floyd Warshall algorithm */
      for (i=0; i<n; i++)
        for (j=0; j<n; j++){
          cur[nChange][i][j] = cur[nChange-1][i][j];
          /* find the intermediary */
          for (k=0; k<n; k++){
            temp = cur[nChange-1][i][k]*cur[0][k][j];
            if (temp>cur[nChange][i][j]){
              cur[nChange][i][j] = temp;
              trace[nChange][i][j] = k;
            }
          }
        }

      /* checking for arbitrage over 1% */
      for (i=0; i<n; i++){
        if (cur[nChange][i][i]>1.01){
          printPath(trace,i,i,nChange);
          printf("%d\n",i+1); /* end up at i again */
          arbitrageFound = 1;
          break;
        }
      }
      if (arbitrageFound) break;
    }

    if (!arbitrageFound){
      printf("no arbitrage sequence exists\n");
    }
  }
}













