// Maximum Flow (Dinic Algorithm)
// Time complexity: O(n^2m)
// A slight improvement from Edmonds_Karp Algorithm
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define NMAX 1005
#define INF 1e9

using namespace std;

int N, M, S, T, a, b, c, C[NMAX][NMAX], F[NMAX][NMAX], level[NMAX], idx[NMAX];
vector <int> G[NMAX];


bool bfs()
{
  memset(level, -1, sizeof(level));
  level[S] = 0;
  queue <int> q;
  q.push(S);
  while(q.size())
  {
    int acc = q.front();
    q.pop();

    for(auto e : G[acc])
    {
      if(level[e] == -1 and C[acc][e] - F[acc][e] > 0)
      {
        level[e] = level[acc] + 1;
        q.push(e);
      }
    }
  }
  if(level[T] != -1)
    return true;
  return false;
}

int dfs(int acc, int pushed)
{
  if(acc == T) return pushed;
  if(pushed == 0) return 0;

  for( ; idx[acc] < G[acc].size(); idx[acc]++)
  {
    int e = G[acc][idx[acc]];

    //cazul rau
    if(level[e] != level[acc] + 1 or C[acc][e] - F[acc][e] == 0)
      continue;

    int path_flow = dfs(e, min(pushed, C[acc][e] - F[acc][e]));

    if(path_flow == 0)
      continue;

    F[acc][e] += path_flow;
    F[e][acc] -= path_flow;
    return path_flow;
  }
  return 0;
}

int main()
{
  cin >> N >> M;
  S = 1; T = N;
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
    memset(idx, 0, sizeof(idx));
    while(int pushed = dfs(S, INF))
    {
      max_flow += pushed;
    }
  }
  cout << max_flow;
  return 0;
}
