
struct edge { int to, cap, rev; };
struct MF{
  vector< vector<edge> > adj;
  vector<int> level, iter;
  MF(int V) : adj(V), level(V), iter(V) {}

  void add_edge(int from, int to, int cap) {
    adj[from].pb((edge){to,cap,sz(adj[to])});
    adj[to].pb((edge){from,0,sz(adj[from])-1});
  }
  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      rep(i,sz(adj[v])) {
        edge& e = adj[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }
  int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = iter[v]; i < sz(adj[v]); i++) {
      edge& e = adj[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          adj[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
      bfs(s);
      if (level[t] < 0) return flow;
      fill(iter.begin(), iter.end(), 0);
      for (int f; (f = dfs(s, t, INF)) > 0; flow += f);
    }
  }
};
