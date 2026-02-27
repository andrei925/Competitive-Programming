// Modular Multiplicative Inverse via Extended Euclidean Algorithm
// Complexity: O(log MOD)
long long Modular_Inverse(long long X)
{
  a = mod;
  b = X % mod; // ce impartim

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
  return  t1 % mod;
}
