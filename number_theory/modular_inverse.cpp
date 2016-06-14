/*
 * Description:
 * -----------
 * The modular multiplicative inverse of an integer `a'
 * modulo `n' is an integer x such that: ax % n = 1
 * The multiplicative inverse of a modulo n exists if
 * and only if a and n are coprime. This function is
 * useful when we wish to compute (x/y) % n as it is
 * equivalent to computing (x * mod_inverse(y,n)) % n
*/

long long mod_inverse(long long a, long long n) {
  // a and n MUST be coprime or else it returns -1
  long long t = 0, newt = 1;
  long long r = n, newr = a;
  while (newr) {
    long long q = r / newr;
    long long tmp_t = t, tmp_r = r;
    t = newt; r = newr;
    newt = tmp_t - q * newt;
    newr = tmp_r - q * newr;
  }
  if (r > 1) return -1;
  if (t < 0) t += n;
  return t;
}
