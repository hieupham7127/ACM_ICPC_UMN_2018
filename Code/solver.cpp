Int solve(Int a, Int b, Int m) {
  Int x, y, g = extgcd(a, m, x, y);
  if (g == 1) {
    return (Int) ((inv(a, m) * (__int128) b) % m);
  }
  if (b % g != 0) {
    return -1;
  }
  __int128 soln = (inv(a / g, m / g) * (__int128) (b / g)) % (m / g);
  __int128 k = 0;
  return (Int) (soln + k * (m / g)) % m;
}
