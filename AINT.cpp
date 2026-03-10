#include <fstream>
#define NMAX 1000005
using namespace std;

ifstream cin("arbint.in");
ofstream cout("arbint.out");

int tree[NMAX], v[NMAX], N, M, op, a, b;

void built(int nod, int st, int dr)
{
  if(st == dr)
  {
    tree[nod] = v[st];
    return;
  }
  int mid = (st + dr) / 2;
  built(nod * 2, st, mid);
  built(nod * 2 + 1, mid + 1, dr);

  tree[nod] = max(tree[nod * 2], tree[nod * 2 + 1]);
}

void update(int nod, int st, int dr, int pos, int value)
{
  if(st == dr and st == pos){
    tree[nod] = value;
    return;
  }

  int mid = (st + dr) / 2;
  if(pos <= mid)update(nod * 2, st, mid, pos, value);
  else update(nod * 2 + 1, mid + 1, dr, pos, value);

  tree[nod] = max(tree[nod * 2], tree[nod * 2 + 1]);
}

int query(int nod, int st, int dr, int L, int R)
{
  if(L <= st and dr <= R)
    return tree[nod];

  int mid = (st + dr) / 2;
  int rez = 0;
  if(L <= mid) rez = query(nod * 2, st, mid, L, R);
  if(mid < R) rez = max(rez,query(nod * 2 + 1, mid + 1, dr, L, R));

  return rez;
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    cin >> v[i];
  }
  built(1, 1, N);
  for(int i = 1; i <= M; i++)
  {
    cin >> op >> a >> b;
    if(op == 0)
      cout << query(1, 1, N, a, b) << '\n';
    else
      update(1, 1, N, a, b);
  }
  return 0;
}
