//Se da un sir de N numere. Putem obtine suma S adunand cu cele N numere?
// O(N * S)
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

int N, S, x[NMAX];
bool dp[3][NMAX];

void solve()
{
  cin >> N >> S;
  for(int i = 1; i <= N; i++)
    cin >> x[i];

  dp[1][0] = 1;  dp[2][0] = 1;
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= S; j++){
      if(j >= x[i])
        dp[2][j] = (dp[1][j] or dp[1][j - x[i]]);
      else
        dp[2][j] = dp[1][j];
    }

    for(int j = 1; j <= S; j++){
      dp[1][j] = dp[2][j];
      dp[2][j] = 0;
    }
  }

  if(dp[1][S])
    cout << "DA";
  else
    cout << "NU";
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
