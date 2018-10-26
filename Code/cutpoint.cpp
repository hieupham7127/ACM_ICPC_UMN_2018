const int MAXN = 1010;
struct CutPoint {
  vector<int> g[MAXN], cut_points;
  int timer, used[MAXN], tin[MAXN], fup[MAXN];
  CutPoint() {
    clr(g); clr(used); clr(tin); clr(fup); timer = 0;
  }

  void add_edge(int u, int v) {
    g[u].pb(v); g[v].pb(u);
  }
   
  void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    rep(i,sz(g[v])) {
      int to = g[v][i];
      if (to == p)  continue;
      if (used[to]) {
        fup[v] = min (fup[v], tin[to]);
      } else {
        dfs (to, v);
        fup[v] = min (fup[v], fup[to]);
        if (fup[to] >= tin[v] && p != -1) {
          cut_points.pb(v);
        }
        ++children;
      }
    }
    if (p == -1 && children > 1) {
      cut_points.pb(v);
    }
  }
  vector<int> run(int root) {
    clr(used); cut_points.clear();
    dfs(root);
    sort(cut_points.begin(), cut_points.end());
    cut_points.erase(unique(cut_points.begin(), cut_points.end()), cut_points.end());
    return cut_points;
  }
};
