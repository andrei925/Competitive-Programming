// Fast Exponentiation
// Computes N^K in O(log K) time using the square-and-multiply method
long long Putere(int N, int K)
{
  long long ans = 1;
  while(K)
  {
    if(K % 2 == 1)
      ans *= N;
    N *= N;
    K /= 2;
  }
  return ans;
}
