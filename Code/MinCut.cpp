struct MinCut {
  vector<vector<int> > weights;
  MinCut(int n) : weights(n, vector<int>(n)) {}
  void add_edge(int u, int v, int w) { weights[u][v] += w; weights[v][u] += w; }
  pair<int, vector<int> > GetMinCut() {
    int N = sz(weights), best_weight = -1, prev, last;
    vector<int> used(N), cut, best_cut, w, added;
    for (int phase = N-1; phase >= 0; phase--) {
      w = weights[0]; added = used; last = 0;
      rep(i,phase) {
        prev = last; last = -1;
        rep1(j,N-1) if (!added[j] && (last == -1 || w[j] > w[last])) last = j;
        if (i == phase-1) {
          rep(j,N) weights[prev][j] += weights[last][j];
          rep(j,N) weights[j][prev] = weights[prev][j];
          used[last] = true;
          cut.push_back(last);
          if (best_weight == -1 || w[last] < best_weight) {
            best_cut = cut;
            best_weight = w[last];
          }
        } else {
          rep(j,N) w[j] += weights[last][j];
          added[last] = true;
        }
      }
    }
    return mp(best_weight, best_cut);
  }
};

