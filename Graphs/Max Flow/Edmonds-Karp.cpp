// Maximum Flow (Edmonds-Karp Algorithm)
// Time complexity: O(nm^2) in total, O(nm) BFS iterations with O(m) per BFS
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

#define NMAX 1005
#define INF 1e9

using namespace std;
ifstream cin("maxflow.in");
ofstream cout("maxflow.out");

int N, M, S, T, a, b, c, parent[NMAX], C[NMAX][NMAX], F[NMAX][NMAX];
vector <int> G[NMAX];

bool bfs()
{
  memset(parent, 0, sizeof(parent));
  parent[S] = -1;
  queue <int> q;
  q.push(S);

  while(q.size())
  {
    int acc = q.front();
    q.pop();

    if(acc == T)
      return true;

    for(auto e : G[acc])
    {
      if(parent[e] == 0 and C[acc][e] - F[acc][e] > 0)
      {
        parent[e] = acc;
        q.push(e);
      }
    }
  }
  return false;
}

int main()
{
  cin >> N >> M;
  S = 1;
  T = N;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c;
    G[a].push_back(b);
    G[b].push_back(a);
    C[a][b] = c;
  }

  long long max_flow = 0;
  while(bfs())
  {
    for(auto e : G[T])
    {
      if(parent[e] and C[e][T] - F[e][T] > 0)
      {
        int path_flow = INF;
        parent[T] = e;

        //cautam dif minima
        int acc = T;
        while(acc != S)
        {
          int prev = parent[acc];
          path_flow = min(path_flow, C[prev][acc] - F[prev][acc]);
          acc = prev;
        }

        if(path_flow <= 0)
          continue;

        acc = T;
        while(acc != S)
        {
          int prev = parent[acc];
          F[prev][acc] += path_flow;
          F[acc][prev] -= path_flow;
          acc = prev;
        }
        max_flow += path_flow;
      }
    }
  }
  cout << max_flow;
  return 0;
}

