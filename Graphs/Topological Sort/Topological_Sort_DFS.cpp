#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 50005
using namespace std;

int N, M, a, b, visited[NMAX];

vector <int> G[NMAX];
vector <int> top_sort;

void dfs(int x)
{
  visited[x] = 1;
  for(auto e : G[x])
  {
    if(visited[e] == 0)
      dfs(e);
  }
  top_sort.push_back(x);
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    cin >> a >> b;
    G[a].push_back(b);
  }

  for(int i = 1; i <= N; i++)
  {
    if(visited[i] == 0)
      dfs(i);
  }

  reverse(top_sort.begin(), top_sort.end());

  for(auto e : top_sort)
    cout << e << ' ';
  return 0;
}
