//Problema clasica de grid paths
//Exista multe variatii precum Drumul de cost minim, diferite directii etc
//O(N * M)
//Putem optimiza timpul daca in loc sa copiem liniile cu Rolling Array le construim dupa paritate
//Memoria poate fi optimizata la O(N) cu Rolling Array
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

#define NMAX 100005
#define INF 1e9
#define MOD 1e9 + 7

using namespace std;

int N, M, dp[3][NMAX];

void solve()
{
  cin >> N >> M;

  for(int j = 1; j <= M; j++)
    dp[1][j] = 1;

  for(int i = 2; i <= N; i++)
  {
    for(int j = 1; j <= M; j++)
      dp[2][j] = dp[2][j - 1] + dp[1][j];

    for(int j = 1; j <= M; j++){
      dp[1][j] = dp[2][j];
      dp[2][j] = 0;
    }
  }

  cout << dp[1][M];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  t = 1;

  while(t--)
  {
    solve();
  }
  return 0;
}
