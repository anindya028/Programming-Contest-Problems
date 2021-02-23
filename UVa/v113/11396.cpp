//good problem,bicoloring
#include<stdio.h>
#include<queue>

using namespace std;

#define SIZE 309

int g[SIZE][SIZE],vis[SIZE],n,col[SIZE],notpossible;

void ini(int n){
	int i,j;

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=0;
}

void bfs(int s){
	queue<int> q;
	int i,j;

	col[s]=1;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		i = q.front();q.pop();

		for(j=1;j<=n;j++){
			if(i==j) continue;
			if(!g[i][j]) continue;

			if(!vis[j]){
				vis[j]=1;
				if(col[i]==1)
					col[j]=2;
				else
					col[j]=1;

				q.push(j);
			}
			else{
				if(col[i]==col[j]){
					notpossible =1;
					return;
				}
			}
		}
	}
}
int main(){
	int a,b,i;

	while(scanf("%d",&n) && n){

		ini(n);
		while(scanf("%d%d",&a,&b) && a|b){
			g[a][b]=g[b][a]=1;
		}

		memset(vis,0,sizeof(vis));
		memset(col,0,sizeof(col));
		notpossible = 0;
		for(i=1;i<=n;i++){
			if(!vis[i]){
				bfs(i);
				if(notpossible){
					break;
				}
			}
		}
		if(notpossible)
			puts("NO");//supposed to be
		else puts("YES");
	}

	return 0;
}