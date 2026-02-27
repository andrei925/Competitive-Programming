// Calculates the N-th Catalan Number modulo MOD: C_n = (2n)! / ((n+1)! * n!)
// Uses Extended Euclidean Algorithm for modular inverse of the denominator
long long Catalan(int N)
{
  a = mod;
  b = fact[N + 1] * fact[N] % mod;

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
  return fact[2 * N] * t1 % mod;
}
