// Time complexity: O(nlogn) build, O(logn) per query
#include <iostream>
#include <vector>
#include <cmath>
#define NMAX 100005
using namespace std;

int N, Q, L, up[NMAX][20], time_in[NMAX], time_out[NMAX], time_curr;
vector <int> G[NMAX];

void dfs(int x)
{
  time_in[x] = ++time_curr;

  for(int i = 1; i <= L; i++)
    up[x][i] = up[up[x][i - 1]][i - 1];

  for(auto e : G[x])
    if(up[x][0] != e)
      dfs(e);

  time_out[x] = ++time_curr;
}

bool is_ancestor(int x, int y){
  return (time_in[x] <= time_in[y] and time_out[y] <= time_out[x]);
}

int lca(int x, int y)
{
  if(is_ancestor(x, y))
    return x;
  if(is_ancestor(y, x))
    return y;

  for(int i = L; i >= 0; i--)
    if(up[x][i] and !is_ancestor(up[x][i], y) )
      x = up[x][i];
  return up[x][0];
}

int main()
{
  cin >> N >> Q;
  L = log2(N);
  for(int i = 2; i <= N; i++){
    cin >> up[i][0];
    G[up[i][0]].push_back(i);
  }

  dfs(1);

  for(int i = 1; i <= Q; i++){
    int a, b;
    cin >> a >> b;
    cout << lca(a, b) << '\n';
  }
  return 0;
}
