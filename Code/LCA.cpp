const int MAX_V = 200100;
const int MAX_LOG_V = 25;
vector<int>  adj[MAX_V];
int root = 1;
int edgefrom[MAX_V];
int edgeto[MAX_V];

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  rep(i,sz(adj[v]))
  if (adj[v][i] != p) dfs(adj[v][i], v, d + 1);
}

void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++) {
    for (int v = 1; v <= V; v++) {
      if (parent[k][v] < 0) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v) return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
