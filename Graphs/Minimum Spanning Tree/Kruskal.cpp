#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 100005
using namespace std;
int N, M, a, b, parent[NMAX], h[NMAX];
long c;

struct edge{
  int first, second;
  long long third;
};

vector <edge> G;

bool comp(edge a, edge b){
  return a.third < b.third;
}

int Find(int x)
{
  if(parent[x] == x)
    return x;
  return Find(parent[x]);
}

void Union(int x, int y)
{
  int x_parent = Find(x);
  int y_parent = Find(y);

  if(x_parent != y_parent)
  {
    if(h[x_parent] < h[y_parent])
      parent[x_parent] = y_parent;
    else if(h[y_parent] < h[x_parent])
      parent[y_parent] = x_parent;
    else if(h[x_parent] == h[y_parent]){
      parent[x_parent] = y_parent;
      h[y_parent]++;
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
    cin >> a >> b >> c;
    G.push_back({a, b, c});
  }

  sort(G.begin(), G.end(), comp);

  for(int i = 1; i <= N; i++)
    parent[i] = i;

  long long ans = 0;
  for(auto e : G)
  {
    if(Find(e.first) != Find(e.second))
    {
      Union(e.first, e.second);
      ans += e.third;
    }
  }
  bool bad = 0;
  for(int i = 1; i <= N; i++)
    if(Find(i) != Find(1))
      bad = 1;
  if(bad)
    cout << "IMPOSSIBLE";
  else
    cout << ans;
  return 0;
}
