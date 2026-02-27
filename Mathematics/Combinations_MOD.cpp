// Calculates Combinations N choose K modulo MOD: C(N, K) = N! / (K! * (N-K)!)
// Uses Extended Euclidean Algorithm for modular inverse
// Complexity: O(log MOD)
long long Combinari(long long N, long long K)
{
  a = mod;
  b = fact[K] * fact[N - K] % mod; 

  t1 = 0;
  t2 = 1;

  while(b)
  {
    catul = a / b;
    restul = a % b;
    a = b;
    b = restul;

    t = t1 - t2 * catul;
    t1 = t2;
    t2 = t;
  }
  t1 = (t1 % mod + mod) % mod;
  return fact[N] * t1 % mod;
}
