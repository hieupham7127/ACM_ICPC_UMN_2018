struct BipartiteMatching {
  vector<vector<int> > adj;
  vector<int> match, used;
  BipartiteMatching(int V) :  adj(V), match(V), used(V) {}
  void add_edge(int u, int v) {
    adj[u].pb(v); adj[v].pb(u);
  }
  int dfs(int v) {
    used[v] = true;
    rep(i,sz(adj[v])) {
      int u = adj[v][i], w = match[u];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u;
        match[u] = v;
        return 1;
      }
    }
    return 0;
  }
  int bipartite_matching() {
    int res = 0;
    fill(match.begin(), match.end(), -1);
    rep(v,sz(match)) {
      if (match[v] < 0) {
        fill(used.begin(), used.end(), 0);
        if (dfs(v)) res++;
      }
    }
    return res;
  }
};
