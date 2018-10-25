vector<int> LCP(const string& s, const vector<int>& sa) {
  int n = sz(s), h = 0;
  vector<int> rank(n + 1), lcp(n);
  rep(i,n + 1) rank[sa[i]] = i;
  rep(i,n) {
    int j = sa[rank[i] - 1];
    if (h > 0) h--;
    for (; max(i, j) + h < n && s[j + h] == s[i + h]; h++);
    lcp[rank[i] - 1] = h;
  }
  return lcp;
}
