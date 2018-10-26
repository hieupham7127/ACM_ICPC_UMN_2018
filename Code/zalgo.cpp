vector<int> make_z(string s)
{
  int N = sz(s);
  vector<int> z(N);
  for (int i = 1, l = 0, r = 0, k; i < N; i++) {
    if (i <= r) z[i] = min (r - i + 1, z[i - l]);
    while ((k = i + z[i]) < N && s[z[i]] == s[k]) z[i]++;
    k--;
    if (k > r) l = i, r = k;
  }
  return z;
}
