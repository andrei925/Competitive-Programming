// DFS Traversal
//Counting the number of components of the graph
//O(N + M)
#include <iostream>
#include <vector>
#define NMAX 100005
using namespace std;

int N, M, a, b, visited[NMAX];
vector <int> G[NMAX];

void dfs(int x)
{
  visited[x] = 1;
  for(auto e : G[x])
  {
    if(!visited[e])
      dfs(e);
  }
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int cnt = 0;
  for(int i = 1; i <= N; i++)
  {
    if(!visited[i])
    {
      cnt++;
      dfs(i);
    }
  }

  cout << cnt;
  return 0;
}
