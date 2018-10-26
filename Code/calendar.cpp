int toJulian(int y, int m, int d) {
  if (m < 3) y--, m += 12;
  return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d + 1721119;
}
int date(int j) { return (j + 1) % 7; }
void fromJulian(int j, int& y, int& m, int& d) {
  int f = j + 1363 + (((4*j + 274277) / 146097) * 3) / 4;
  int e = 4 * f + 3;
  int h = 5 * ((e % 1461) / 4) + 2;
  d = (h % 153) / 5 + 1;
  m = (h / 153 + 2) % 12 + 1;
  y = (e / 1461) + (14 - m) / 12 - 4716;
}
