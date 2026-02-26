#include <iostream>
#include <vector>
#include <queue>
#define NMAX 50005

using namespace std;

int N, M, a, b, in_degree[NMAX];
vector <int> G[NMAX];
vector <int> top_sort;
queue <int> q;

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= M; i++){
    cin >> a >> b;
    G[a].push_back(b);
    in_degree[b]++;
  }

  for(int i = 1; i <= N; i++)
    if(!in_degree[i])
      q.push(i);

  while(q.size())
  {
    int acc = q.front();
    q.pop();
    top_sort.push_back(acc);
    for(auto e : G[acc]){
      in_degree[e]--;
      if(!in_degree[e])
        q.push(e);
    }
  }

  for(auto e : top_sort)
    cout << e << ' ';
  return 0;
}
