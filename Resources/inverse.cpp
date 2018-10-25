typedef ll Int;
Int extgcd(Int a, Int b, Int& x, Int& y) {
  Int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}
Int inv(Int a, Int mod) {
  Int x, y, g;
  g = extgcd(a, mod, x, y);
  if (x < 0) x += mod;
  return x;
}

