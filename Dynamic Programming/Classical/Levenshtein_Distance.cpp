//Edit Distance or Levenshtein Distance
//Given two arrays, in how many moves can we make them the same? we know that the number of moves is the most K
//dp[i][j] = minimum number of moves to make on the first i characters of A to obtain the first j characters of B
//The recurence is dp[i][j] = min({ - dp[i - 1][j] + 1,
//                                  - dp[i][j - 1] + 1,
//                                  - dp[i - 1][j - 1] + (A[i] != B[j]) (so 0 if theyre the same 1 otherwise)
//                               })
//Knowing the distance is at most K we dont need to calculate dp[i][j] if |i - j| is more than K
//Now we just use the Rolling array optimisation for memory

#include <iostream>
#include <cstring>
#define NMAX 20005
using namespace std;

//ifstream cin("edist.in");
//ofstream cout("edist.out");

int N, M, K, dp[5][NMAX];
char a[NMAX], b[NMAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  cin >> a;
  cin >> b;

  for(int j = 0; j < M; j++)
    dp[0][j] = j;

  for(int i = 1; i < N; i++)
  {
    for(int j = max(0, i - K); j <= min(i + K, M - 1); j++)
    {
      if(j > 0)
        dp[1][j] = min(dp[0][j - 1] + (a[i] != b[j]), min(dp[0][j] + 1, dp[1][j - 1] + 1));
      else
        dp[1][j] = i;
    }
    for(int j = max(0, i - K); j <= min(i + K, M - 1); j++){
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }

  cout << dp[0][M - 1];
  return 0;
}
