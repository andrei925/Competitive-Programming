#include <iostream>
#define INF 1e9
#define NMAX
#define SMAX
using namespace std;
int N, coins[NMAX], dp[SMAX], dp_Comb[SMAX], dp_Aran[SMAX];
int main()
{
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> coins[i];

  //............CERINTA 1
  //Numarul Minim de Monede pentru a obtine suma S
  //dp[i] = Numarul minim de monede pentru a obtine suma i
  for(int i = 1; i <= S; i++)
    dp[i] = INF;
  dp[0] = 0;

  for(int i = 1; i <= S; i++)
    for(int j = 1; j <= N; j++)
      if(i >= coins[j])
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);

  cout << dp[S];

  //..........CERINTA 2
  //Numarul de moduri de a obtine suma S, unde ordinea nu conteaza = Combinari
  //dp_Comb[i] = Numarul de moduri de a obtine suma i
  dp_Comb[0] = 1;
  for(int i = 1; i <= N; i++)
    for(int j = coins[i]; j <= S; j++)
      dp_Comb[j] += dp_Comb[j - coins[i]]

  cout << dp_Comb[S];

  //..........CERINTA 3
  //Numarul de moduri de a obtine suma S, unde ordinea conteaza = Aranjamente

  dp_Aran[0] = 1;
  for(int i = 1; i <= S; i++)
    for(int j = 1; j <= N; j++)
      if(i >= coins[j])
        dp_Aran[i] += dp_Aran[i - coins[j]];

  cout << dp_Aran[S];
  return 0;
}
