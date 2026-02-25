//Dijkstra - Minimum distance from one vertice to all the others on a WEIGHTED GRAPH
// O(N * log M)
#include <iostream>
#include <vector>
#include <queue>
#define NMAX 200005
#define INF 1e18
using namespace std;
int N, M, a, b, c;
long long dist[NMAX];

vector < pair <int, int> > G[NMAX];
priority_queue < pair <long long, int> , vector < pair <long long, int> > , greater < pair <long long, int> > > pq;

void dijkstra(int x)
{
  for(int i = 1; i <= N; i++)
    dist[i] = INF;
  dist[x] = 0;

  pq.push({0, x});
  while(pq.size())
  {
    int acc = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if(d > dist[acc]) continue;  // VERY IMPORTANT - this if reduces time complexity and makes sure we dont follow stale vertices
    for( auto e : G[acc])
    {
      int vecin = e.first;
      int cost = e.second;

      if(dist[vecin] > dist[acc] + cost)
      {
        dist[vecin] = dist[acc] + cost;
        pq.push({dist[vecin], vecin});
      }
    }
  }
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c;
    G[a].push_back({b, c});
  }

  dijkstra(1);

  for(int i = 1; i <= N; i++)
    cout << dist[i] << ' ';
  return 0;
}
