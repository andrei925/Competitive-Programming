//  Time complexity: O(nlogn) build, O(1) per query
#include <iostream>
#include <cmath>
#define NMAX 200005
using namespace std;
int N, Q, rmq[30][NMAX], L, k, l ,r;
int main()
{
  cin >> N >> Q;
  L = log2(N);
  for(int i = 1; i <= N; i++)
    cin >> rmq[0][i];

  rmq[0][N + 1] = 1000000001;
  for(int i = 1; i <= L; i++)
  {
    for(int j = 1; j <= N ; j++)
    {
      rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1) )]);
    }
  }

  for(int i = 1; i <= Q; i++)
  {
    cin >> l >> r;
    k = log2(r - l + 1);
    cout << min(rmq[k][l], rmq[k][r - (1 << k) + 1]) << '\n';
  }
  return 0;
}
