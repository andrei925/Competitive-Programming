#include <iostream>
#define NMAX 505
#define INF 2e18
using namespace std;
long long N, M, Q, a, b, c, dist[NMAX][NMAX];

void floyd_warshall()
{
  for(int k = 1; k <= N; k++)
    for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++)
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
}

int main()
{
  cin >> N >> M >> Q;

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      dist[i][j] = INF;
      if(i == j)
        dist[i][j] = 0;
    }
  }
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c;
    if(c < dist[a][b]){
      dist[a][b] = c;
      dist[b][a] = c;
    }
  }

  floyd_warshall();

  while(Q--)
  {
    int x, y;
    cin >> x >> y;
    if(dist[x][y] < INF)
      cout << dist[x][y] << ' ';
    else
      cout << -1 << ' ';
  }
  return 0;
}
