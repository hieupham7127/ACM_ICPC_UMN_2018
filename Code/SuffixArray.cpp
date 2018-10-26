struct SuffixArray {
  int n, k;
  vector<int> rank, tmp, sa;
  pair<int,int> f(int i) {
    return mp(rank[i], i + k <= n ? rank[i + k] : -1);
  }
  vector<int> get_sa(const string& s) {
    n = sz(s);
    rank.resize(n + 1); tmp.resize(n + 1); sa.resize(n + 1);
    rep(i,n + 1) sa[i] = i, rank[i] = i < n ? s[i] : -1;
    vector< pair<pair<int,int>,int> > v;
    for (k = 1; k <= n; k *= 2) {
      v.clear();
      rep(i,n + 1) v.pb(mp(f(sa[i]),sa[i]));
      sort(v.begin(), v.end());
      rep(i,n + 1) sa[i] = v[i].second;
      tmp[sa[0]] = 0;
      rep1(i,n) tmp[sa[i]] = tmp[sa[i - 1]] + (f(sa[i - 1]) < f(sa[i]) ? 1 : 0);
      rank = tmp;
    }
    return sa;
  }
};
