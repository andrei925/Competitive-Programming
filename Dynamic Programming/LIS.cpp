//Longest increasing subsequence
//O(N log N)
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

int N, x[NMAX], best[NMAX], pos[NMAX], p[NMAX];
vector <int> ans;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> x[i];

  int len = 0;
  for(int i = 1; i <= N; i++)
  {
    if(!len){
      best[++len] = x[i];
      // --- Pentru reconstructia subsirului
      pos[len] = i;
      p[i] = pos[len - 1];
      //
      continue;
    }

    if(x[i] > best[len]){
      best[++len] = x[i];
      // --- Pentru reconstructia subsirului
      pos[len] = i;
      p[i] = pos[len - 1];
      //
      continue;
    }

    int l = 1, r = len, idx = 0, mid;
    while(l <= r)
    {
      mid = (l + r) / 2;
      if(x[i] <= best[mid])
      {
         r = mid - 1;
         idx = mid;
       }
      else
        l = mid + 1;
    }
    best[idx] = x[i];
    // --- Pentru reconstructia subsirului
    pos[idx] = i;
    p[i] = pos[idx - 1];
    //
  }

  cout << len;

  // --- Reconstructia Subsirului
  int curr = pos[len];
  while(curr > 0)
  {
    ans.push_back(x[curr]);
    curr = p[curr];
  }
  reverse(ans.begin(), ans.end());

  cout << '\n';
  for(auto e : ans)
    cout << e <<' ';
  return 0;
}
