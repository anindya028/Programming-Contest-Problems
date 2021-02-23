//this is my code->rte,ac
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
struct team
{
	char name[35];
	int p;
	int w;
	int t;
	int l;
	int gd;
	int gs;
	int ga;
	int gam;
}*tea;
int find(int n, char *teamName)
{
	int i;
	for (i=0; i<n; i++)
    		if (strcmp(tea[i].name,teamName)==0)
      			return i;
}
int strcmpignore(char *a, char *b)
{
  for (; *a && *b; a++, b++)
    if (toupper(*a)!=toupper(*b)) 
      return toupper(*a)-toupper(*b);
  if (*a) return  1;
  if (*b) return -1;
  return 0;
}
int teamcmp(const void *a, const void *b)
{
  team *T1 = (team*) a;
  team *T2 = (team*) b;
  if (T1->p!=T2->p) return T2->p - T1->p;
  if (T1->w!=T2->w) return T2->w - T1->w;
  if (T1->gd!=T2->gd) return T2->gd- T1->gd;
  if (T1->gs!=T2->gs) return T2->gs - T1->gs;
  if (T1->gam!=T2->gam) return T1->gam - T2->gam;
  return strcmpignore(T1->name,T2->name);
}
int main()
{
	int n,i,t,j,g,g1,g2,t1,t2;
	char tour[105],team1[32],team2[32];
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		if(i)printf("\n");
		scanf("%[^\n]\n",tour);
		printf("%s\n",tour);
		scanf("%d\n",&t);
                tea=(team *)calloc(t,sizeof(team));
		for(j=0;j<t;j++)scanf("%[^\n]\n",tea[j].name);
		scanf("%d\n",&g);
		for(j=0;j<g;j++)
		{
			scanf("%[^#]#%d@%d#%[^\n]\n",team1,&g1,&g2,team2);
			t1=find(t,team1);
                        t2=find(t,team2);
			tea[t1].gd+=(g1-g2);
			tea[t1].gs+=g1;
			tea[t1].ga+=g2;
			tea[t1].gam++;
			if(g1>g2)
			{
				tea[t1].p+=3;
				tea[t1].w++;
				tea[t2].l++;
			}
			else if(g1==g2)
			{
				tea[t1].p+=1;
				tea[t2].p+=1;
				tea[t1].t++;
				tea[t2].t++;
			}
			else
			{
				tea[t1].l++;
				tea[t2].w++;
				tea[t2].p+=3;
			}
			tea[t2].gd+=(g2-g1);
			tea[t2].gs+=g2;
			tea[t2].ga+=g1;
			tea[t2].gam++;
		}
		qsort(tea,t,sizeof(team),teamcmp);
		for(j=0;j<t;j++)printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",j+1,tea[j].name,tea[j].p,tea[j].gam,tea[j].w,tea[j].t,tea[j].l,tea[j].gd,tea[j].gs,tea[j].ga);
                free(tea);
	}
	return 0;
}
//this is code of felix-halim->ac
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTEAM 30
#define TEAMNAME_LEN 31
#define TOURNAMENTNAME_LEN 101

typedef struct {
  char name[TEAMNAME_LEN];
  int points;
  int wins;
  int ties;
  int losses;
  int goalDifference;
  int goalsScored;
  int goalsAgainst;
  int gamesPlayed;
} Team;

int strcmpignore(char *a, char *b){
  for (; *a && *b; a++, b++)
    if (toupper(*a)!=toupper(*b)) 
      return toupper(*a)-toupper(*b);
  if (*a) return  1;
  if (*b) return -1;
  return 0;
}

int getTeamIdxByName(Team teams[], int n, char *teamName){
  for (int i=0; i<n; i++)
    if (strcmp(teams[i].name,teamName)==0)
      return i;
  return -1;
}

int teamcmp(const void *a, const void *b){
  Team *T1 = (Team*) a;
  Team *T2 = (Team*) b;
  if (T1->points!=T2->points) return T2->points - T1->points;
  if (T1->wins!=T2->wins) return T2->wins - T1->wins;
  if (T1->goalDifference!=T2->goalDifference) return T2->goalDifference - T1->goalDifference;
  if (T1->goalsScored!=T2->goalsScored) return T2->goalsScored - T1->goalsScored;
  if (T1->gamesPlayed!=T2->gamesPlayed) return T1->gamesPlayed - T2->gamesPlayed;
  return strcmpignore(T1->name,T2->name);
}

int main(){
  char tournament[TOURNAMENTNAME_LEN];
  Team teams[MAXTEAM];
  int N, i, T, G;

  scanf("%d\n",&N);
  while (N--){
    scanf("%[^\n]\n",tournament);
    printf("%s\n",tournament);

    scanf("%d\n",&T);
    memset(teams, 0, sizeof(Team)*T);
    for (i=0; i<T; i++)
      scanf("%[^\n]\n",teams[i].name);

    scanf("%d\n",&G);
    for (i=0; i<G; i++){
      char tname1[TEAMNAME_LEN];
      char tname2[TEAMNAME_LEN];
      int t1,t2,g1,g2;

      scanf("%[^#]#%d@%d#%[^\n]\n", tname1,&g1,&g2,tname2);
      t1 = getTeamIdxByName(teams,T,tname1);
      t2 = getTeamIdxByName(teams,T,tname2);

      // calculate scores
      teams[t1].goalDifference += g1-g2;
      teams[t1].goalsScored += g1;
      teams[t1].goalsAgainst += g2;
      teams[t1].gamesPlayed++;
      teams[t1].points += (g1>g2)? 3 : (g1==g2)? 1 : 0;
      teams[t1].wins += (g1>g2)? 1 : 0;
      teams[t1].losses += (g2>g1)? 1 : 0;
      teams[t1].ties += (g1==g2)? 1 : 0;

      teams[t2].goalDifference += g2-g1;
      teams[t2].goalsScored += g2;
      teams[t2].goalsAgainst += g1;
      teams[t2].gamesPlayed++;
      teams[t2].points += (g2>g1)? 3 : (g1==g2)? 1 : 0;
      teams[t2].wins += (g2>g1)? 1 : 0;
      teams[t2].losses += (g1>g2)? 1 : 0;
      teams[t2].ties += (g1==g2)? 1 : 0;
    }

    qsort(teams,T,sizeof(Team),teamcmp);

    for (i=0; i<T; i++)
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1,
        teams[i].name,
        teams[i].points,
        teams[i].gamesPlayed,
        teams[i].wins,
        teams[i].ties,
        teams[i].losses,
        teams[i].goalDifference,
        teams[i].goalsScored,
        teams[i].goalsAgainst);

    if (N) puts(""); // separate each test case by a blank line (REQUIRED)
  }

  return 0;
}*/













