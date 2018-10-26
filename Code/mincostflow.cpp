typedef ll cost_type;
const cost_type INF = (int) 1e15;
typedef pair<cost_type,int> P;
struct edge{ 
  int to, cap; 
  cost_type cost; 
  int rev; 
};

struct MF {
  vector<vector<edge> > adj;
  vector<cost_type> h, dist;
  vector<int> prevv, preve;
  MF(int V) : adj(V), h(V), dist(V), prevv(V), preve(V) {}
  void add_edge(int from, int to, int cap, cost_type cost) {
    adj[from].pb((edge){to,cap,cost,sz(adj[to])});
    adj[to].pb((edge){from,0,-cost,sz(adj[from])-1});
  }
  cost_type min_cost_flow(int s, int t, int f) {
    cost_type res = 0;
    fill(h.begin(), h.end(), 0);
    while (f > 0) {
      priority_queue< P, vector<P>, greater<P> > q;
      fill(dist.begin(), dist.end(), INF);
      dist[s] = 0;
      q.push(P(0,s));
      while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        rep(i,sz(adj[v])) {
          edge& e = adj[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            q.push(P(dist[e.to], e.to));
          }
        }
      }
      if ((double) dist[t] + 1.0 > INF) return -1;
      rep(v,sz(h)) h[v] += dist[v];

      int d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = min(d, adj[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge& e = adj[prevv[v]][preve[v]];
        e.cap -= d;
        adj[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

