// add an empty constructor in SPT
const int MAX_V = 1001;
struct LCA {
  vector<int> adj[MAX_V], depth, vs;
  int root, id[MAX_V];
  SPT rmq;
  LCA(int inproot) : root(inproot){ 
    clr(adj); clr(id); vs.clear(); depth.clear(); 
  }
  void dfs(int u, int p, int d) {
    id[u] = sz(depth); vs.pb(u); depth.pb(d);
    rep(i,sz(adj[u])) {
      int v = adj[u][i];
      if (v != p) {
        dfs(v, u, d + 1);
        depth.pb(d); vs.pb(u);
      } 
    } 
  } 
  void add_edge(int u, int v) { 
    adj[u].pb(v); adj[v].pb(u); 
  }
  void init() { dfs(root, -1, 0); rmq = SPT(depth); }
  int lca (int u, int v) {
    return vs[rmq.minPos(min(id[u],id[v]),max(id[u],id[v]))];
  }
};

