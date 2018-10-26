const int MAX_V = 100;
struct SCC {
  int V, used[MAX_V], cmp[MAX_V]; 
  vector<int> G[MAX_V], rG[MAX_V], vs;
  SCC(int n) : V(n) {}
  void add_edge(int from, int to) {
    G[from].pb(to);
    rG[to].pb(from);
  }
  void dfs(int v) {
    used[v] = true;
    rep(i,sz(G[v])) if (!used[G[v][i]]) dfs(G[v][i]);
    vs.pb(v);
  }
  void rdfs(int v, int k) {
    used[v] = true; cmp[v] = k;
    rep(i,sz(rG[v])) if (!used[rG[v][i]]) rdfs(rG[v][i], k);
  }
  int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    rep1(v,V) if (!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = sz(vs) - 1; i >= 0; i--) 
      if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }
};
