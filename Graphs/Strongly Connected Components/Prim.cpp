// Prim Agorithm is similar to Dijkstra
// Time Complexity: O(mlogn)
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define NMAX 200005

using namespace std;

int N, M, a, b, c;
long long ans;
bool visited[NMAX];

priority_queue < pair <int , pair <int ,int> > , vector < pair <int , pair <int ,int> > > , greater < pair <int , pair <int ,int> > > > pq;

vector < pair <int, int> >G[NMAX];
vector < pair <int, int> > mst;

void prim(int x)
{
  visited[x] = 1;
  for(auto e : G[x])
      pq.push({e.second, {e.first, x} });

  while(pq.size())
  {
    int acc = pq.top().second.first;
    int w = pq.top().first;
    int p = pq.top().second.second;
    pq.pop();
    if(!visited[acc])
    {
      ans += w;
      visited[acc] = 1;
      mst.push_back({acc, p});
      for(auto e : G[acc])
        if(!visited[e.first]){
            pq.push({e.second, {e.first, acc}});
        }
    }
  }

}


int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++){
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  prim(1);

  cout << ans << '\n';
  cout << mst.size() << '\n';
  for(auto e : mst)
    cout << e.first << ' ' << e.second << '\n';
  return 0;
}
