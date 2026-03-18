//  Segment tree with lazy propagation
//  We are given an array and a set of operation as such : 1. output the minimum on the interval A, B
//                                                         2. add the value X to the numbers in the interval A, B
//  We use lazy to make both operations in O(logN)

#include <iostream>
#define NMAX 100005
using namespace std;
//ifstream cin("aimi.in");
//ofstream cout("aimi.out");
int N, v[NMAX], M;

struct node_tree{
  int min_value;
  long long pending;
}tree[4 * NMAX];


void built(int node, int start, int end)
{
  tree[node].pending = -1;
  
  if(start == end){
    tree[node].min_value = v[start];
    return;
  }

  int mid = (start + end) / 2;
  built(node * 2, start, mid);
  built(node * 2 + 1, mid + 1, end);

  tree[node].min_value = min(tree[node * 2].min_value, tree[node * 2 + 1].min_value);
}

void push(int node)
{
  if(tree[node].pending != -1)
  {
    tree[node * 2].min_value = tree[node].pending;
    tree[node * 2].pending = tree[node].pending;

    tree[node * 2 + 1].min_value = tree[node].pending;
    tree[node * 2 + 1].pending = tree[node].pending;

    tree[node].pending = -1;
  }
}

void update(int node, int start, int end, int L, int R, int value)
{
  if(R < start or end < L or L > R)
    return;

  if(L <= start and end <= R){
    tree[node].min_value = value;
    tree[node].pending = value;
    return;
  }

  if(start != end)
    push(node);

  int mid = (start + end) / 2;
  update(node * 2, start, mid, L, R, value);
  update(node * 2 + 1, mid + 1, end, L, R, value);

  tree[node].min_value = min(tree[node * 2].min_value, tree[node * 2 + 1].min_value);
}

long long query(int node, int start, int end, int L, int R)
{
  if(R < start or end < L or start > end)
    return 1e18;

  if(L <= start and end <= R)
    return tree[node].min_value;

  if(start != end)
    push(node);

  int mid = (start + end) / 2;
  return min( query(node * 2, start, mid, L, R), query(node * 2 + 1, mid + 1, end, L, R));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> v[i];

  built(1, 1, N);

  cin >> M;
  for(int i = 1; i <= M; i++)
  {
    int op, A, B, X;
    cin >> op;
    if(op == 1)
    {
      cin >> A >> B;
      cout << query(1, 1, N, A, B) << '\n';
    }
    if(op == 2)
    {
      cin >> A >> B >> X;
      update(1, 1, N, A, B, X);
    }
  }
  return 0;
}
