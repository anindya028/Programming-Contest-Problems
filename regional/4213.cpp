  
      #include <iostream>
  
      #include <cstdio>
  
      #include <cstring>
  
      using namespace std;
  
       
      int c1[1001][1001];

      int c2[1001][1001][2];

      char s1[1001], s2[1001];

      int K;
 int go1(int u, int v){

              int &ret = c1[u][v];

              if(-1!=ret) return ret;
              if(s1[u] == s2[v]){

                      int t = 0;

                      if (u && v){

                              t = go1(u-1, v-1);
                     }
                     ret = 1 + t;
             }
              else{
                      ret = 0;
              }
              return ret;
      }
      int go2(int u, int v, int w){
              if (u<0 || v<0)return 0;
              int &ret = c2[u][v][w];
              if(-1!=ret) return ret;
              ret = 0;
              if (w == 0){
                      int t = go1(u, v);
                      if (t >= K){
                              int a = go2(u - K, v - K, 1) + K;
                              if (a > ret) ret = a;
                      }
              }
              else{
                      if (s1[u] == s2[v]){
                              int a = go2(u-1, v-1, 1) + 1;
                              if (a > ret) ret = a;
                      }
              }
       
              int b = go2(u, v-1, 0);
              if (b > ret) ret = b;
              b = go2(u-1, v, 0);
              if (b > ret) ret = b;

              return ret;
  
      }
  
       
  
      int main (void){
  
             
  
              while(scanf("%d",&K) && K){
  
                      scanf("%s%s",&s1,&s2);
  
                      int len1 = strlen(s1);
  
                      int len2 = strlen(s2);
  
                      memset(c1, -1, sizeof(c1));
  
                      memset(c2, -1, sizeof(c2));
  
                      int res = go2(len1-1, len2-1, 0);
  
                      printf("%d\n",res);
  
              }
  
              return 0;
  
      }