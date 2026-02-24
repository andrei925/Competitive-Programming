#include <fstream>
#define INF 100000000
using namespace std;
ifstream cin("hamilton.in");
ofstream cout("hamilton.out");
int N, M, dist[20][20], memo[1 << 18][20], a, b, c;

int solve(int mask, int x)
{
  if(mask == (1 << N) - 1)
    return dist[x][0];

  if(memo[mask][x] != -1)
    return memo[mask][x];

  int cost_min = INF;
  for(int k = 0; k < N; k++)
  {
    if( !(mask & (1 << k)) and dist[x][k] != INF)
    {
      int cost = dist[x][k] + solve(mask | (1 << k), k);
      cost_min = min( cost_min, cost );
    }
  }
  memo[mask][x] = cost_min;
  return cost_min;
}

int main()
{
  cin >> N >> M;

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      dist[i][j] = INF;

  for(int i = 1; i <= M; i++){
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for(int mask = 0; mask < (1 << N); mask++)
    for(int i = 0; i < N; i++)
      memo[mask][i] = -1;

  int ans = solve(1, 0);
  if(ans >= INF)
    cout << "Nu exista solutie";
  else
    cout << ans;
  return 0;
}
