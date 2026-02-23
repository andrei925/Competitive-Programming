 #include <fstream>
 #define NMAX 5005
 #define WMAX 10005
 using namespace std;
 ifstream cin("rucsac.in");
 ofstream cout("rucsac.out");
 int N, W, w[NMAX], c[NMAX], dp[WMAX];
 int main()
 {
   cin >> N >> W;
   for(int i = 1; i <= N; i++)
     cin >> w[i] >> c[i];

   for(int i = 1; i <= N; i++)
    for(int j = W; j >= w[i]; j--)
      dp[j] = max(dp[j], dp[j - w[i]] + c[i]);

    cout << dp[W];
    return 0;
 }
