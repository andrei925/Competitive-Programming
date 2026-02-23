//Subsirul de suma maxima
//O(N)
#include <iostream>
#define NMAX 100005
using namespace std;
int N, value[NMAX];
int main()
{
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> value[i];

  long long curr = 0;
  long long ans = -1e18;
  int left = 0, right = 0, s = 1;
  for(int i = 1; i <= N; i++)
  {
    curr += value[i];

    if(curr > ans)
    {
      ans  = curr;
      left = s;
      right = i;
    }

    if(curr < 0)
    {
      curr = 0;
      s = i + 1;
    }
  }

  cout << ans << '\n';
  cout << left << ' ' << right;
  return 0;
}


