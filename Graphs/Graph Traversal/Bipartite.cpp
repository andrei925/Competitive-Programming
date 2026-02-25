// Impartirea unui graf in graf bipartite
// Problem link: https://cses.fi/problemset/task/1668
#include <iostream>
#include <vector>
#include <queue>
#define NMAX 200005
using namespace std;
int N, M, a, b, side[NMAX], imp;

vector <int> G[NMAX];
queue <int> q;

void bfs(int x)
{
  side[x] = 1;
  q.push(x);
  while(!q.empty())
  {
    int acc = q.front();
    q.pop();
    for(auto e : G[acc])
    {
      if(!side[e]){
        if(side[acc] == 1) side[e] = 2;
        else side[e] = 1;
        q.push(e);
      }
      else if(side[e] == side[acc])
      {
        cout << "IMPOSSIBLE";
        imp = 1;
        while(!q.empty())
          q.pop();
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> N >> M;
  for(int i = 1; i <= M; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= N; i++)
  {
    if(!side[i])
      bfs(i);
    if(imp)
      return 0;
  }

  for(int i = 1; i <= N; i++)
    cout << side[i] << ' ';
  return 0;
}
