// Kosaraju's algorithm to find strongly connected components (SCCs) by running DFS twice
// 1st pass done on the original graph and record the topological order of the nodes
// 2nd pass done on the transposed graph using the order found in the 1st pass
// Time complexity: O(n + m)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100005
using namespace std;
//ifstream cin("ctc.in");
//ofstream cout("ctc.out");
int N, M, x, y, f[NMAX], cntscc;

vector <int> G[NMAX];
vector <int> Gt[NMAX];
vector <int> scc[NMAX];
vector <int> sortare;



void dfs1(int x)
{
  f[x] = 1;
  for(auto e : G[x])
    if(f[e] == 0)
      dfs1(e);
  sortare.push_back(x);
}

void dfs(int x)
{
  f[x] = 1;
  scc[cntscc].push_back(x);
  for(auto e : Gt[x])
    if(f[e] == 0)
      dfs(e);
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++)
  {
    cin >> x >> y;
    G[x].push_back(y);
    Gt[y].push_back(x);
  }
  //facem sortarea
  for(int i = 1; i <= N; i++)
    if(f[i] == 0)
      dfs1(i);

  reverse(sortare.begin(), sortare.end());

  for(int i = 1; i <= N; i++)
      f[i] = 0;

  //costruim scc
  for(auto i : sortare)
  {
    if(f[i] == 0)
    {
      cntscc++;
      dfs(i);
    }
  }
  cout << cntscc <<'\n';
  for(int i = 1; i <= cntscc; i++)
  {
    for(auto e : scc[i])
      cout << e << ' ';
    cout<<'\n';
  }
  return 0;
}
