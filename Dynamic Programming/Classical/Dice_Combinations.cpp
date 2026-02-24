//In cate moduri putem obtine suma N arucand zaruri
//Se poate optimiza once again spatiul
//O(N)
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

#define NMAX 100005
#define INF 1e9
#define MOD 1e9 + 7

using namespace std;


void solve()
{
  cin >> N;

  dp[0] = 1;
  for(int i = 1; i <= N; i++)
    for(int j = i - 1; j >= i - 6 and j >= 0; j--)
      dp[i] += dp[j];

  cout << dp[N];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  t = 1;

  while(t--)
  {
    solve();
  }
  return 0;
}
