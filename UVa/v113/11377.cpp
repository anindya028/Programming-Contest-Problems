//good graph problem
#include<stdio.h>
//#include<vector>
#include<queue>
#include<assert.h>

using namespace std;

#define SIZE 2009
#define INF 1000000

short int list[SIZE][SIZE];
int port[SIZE],dis[SIZE],n,m,q,deg[SIZE];
//list is adjacency list, list is used to reduce order
// vis flags visited nodes during bfs
// dis[i] stores how many new airports needed to build to come here(i)
// port[i]  is one if i has already an airport
void ini(){
	int i;

	for(i=0;i<=n;i++){
		deg[i]=0;
		port[i]=0;		
	}
}

void bfs(int s,int t){
	queue<int> q;
	int i,j,temp,need;

	q.push(s);
	//vis[s]=1;
	if(port[s])dis[s]=0;
	else dis[s]=1;

	while(!q.empty()){
		i=q.front(); q.pop();
		temp=deg[i];
		for(j=0;j<temp;j++){
			//if(!vis[list[i][j]]){
			//	vis[list[i][j]]=1;
				if(port[list[i][j]]) need=dis[i];
				else need=dis[i]+1;

				/*if(list[i][j]==t){
					printf("%d\n",dis[list[i][j]]);
					return ;
				}*/

				if(need<dis[list[i][j]]){
					q.push(list[i][j]);
					dis[list[i][j]]=need;
				}
			//}
		}
	}

	if(dis[t]<INF) printf("%d\n",dis[t]);
	else printf("-1\n");
	return;
}

void init(){
	int i;
	for(i=0;i<=n;i++){		
		dis[i]=INF;
	}
}

int main(){
	int i,a,b,t,x,k,j,flag;

	scanf("%d",&t);
	for(x=1;x<=t;x++){
		scanf("%d%d%d",&n,&m,&k);

		ini();
		for(i=0;i<k;i++){
			scanf("%d",&a);
			port[a]=1;
		}

		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			list[a][deg[a]++]=b;
			list[b][deg[b]++]=a;
		}

		printf("Case %d:\n",x);

		scanf("%d",&q);
		for(i=0;i<q;i++){
			scanf("%d%d",&a,&b);

			if(a==b) {
				//if(port[a]) puts("0");
				//else puts("1");
				/*flag=1;
				for(j=0;j<deg[a];j++) {
					if(list[a][j]==a){
						if(port[a]) puts("0");
						else puts("1");
						flag=0;
						break;
					}
				}
				if(flag)
					puts("-1");*/
				puts("0");
				continue;
			}

			init();

			bfs(a,b);
		}
		puts("");
	}

	return 0;
}