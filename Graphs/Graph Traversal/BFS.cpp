//Basic BFS Traversal where we calculate the distance from a node to any other
//O(N + M)
#include <iostream>
#include <vector>
#include <queue>
#define NMAX 100005
using namespace std;

int N, M, a, b, dist[NMAX];
vector <int> G[NMAX];
queue <int> q;

void bfs(int start)
{
  for(int i = 1; i <= N; i++)
    dist[i] = -1;
  dist[start] = 0;

  q.push(start);
  while(!q.empty())
  {
    int acc = q.front();
    q.pop();
    for(auto e : G[acc])
    {
      if(dist[e] == -1)
      {
        dist[e] = dist[acc] + 1;
        q.push(e);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs(1);

  for(int i = 1; i <= N; i++)
    cout << dist[i] << ' ';
}
