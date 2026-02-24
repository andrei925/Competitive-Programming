//Submatricea de suma maxima
//O(N^3)
#include <iostream>
#define NMAX 1005
using namespace std;
int N, M, mat[NMAX][NMAX];
int left_row, right_row, ans_left_row, ans_right_row, ans_left_column, ans_right_column;
long long sum[NMAX][NMAX];
int main()
{
  cin >> N >> M;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++){
      cin >> mat[i][j];
      sum[i][j] = sum[i][j - 1] + mat[i][j];
    }

  int ans_total = -1e18;
  for(int left = 1; left <= M; left++)
  {
    for(int right = left; right <= M; right++)
    {
      long long curr = 0, s = 1;
      int ans = -1e18;
      for(int i = 1;i <= N; i++)
      {
        curr += sum[i][right] - sum[i][left - 1];

        if(curr > ans)
        {
          ans = curr;
          left_row = s;
          right_row = i;
        }

        if(curr < 0)
        {
          curr = 0;
          s = i + 1;
        }
      }

      if(ans > ans_total)
      {
        ans_total = ans;
        ans_left_row = left_row;
        ans_right_row = right_row;
        ans_left_column = left;
        ans_right_column = right;
      }
    }
  }

  cout << ans_total << '\n';
  //punctul stanga sus
  cout << ans_left_row << ' ' << ans_left_column << '\n';
  //punctul dreapta jos
  cout << ans_right_row << ' ' << ans_right_column;
  return 0;
}

