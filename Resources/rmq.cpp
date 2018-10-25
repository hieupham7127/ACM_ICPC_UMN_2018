struct SPT {
  vector<int> logTable, a;
  vector< vector<int> > rmq;
  SPT () {}
  SPT(vector<int> inpv) {
    this->a = inpv;
    int n = sz(a);
    logTable.resize(n + 1);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;
    rmq.resize(logTable[n] + 1, vector<int>(n));
    rep(i,n) rmq[0][i] = i;
    for (int k = 1; (1 << k) < n; k++) {
      rep(i, n - (1 << k) + 1) {
        int x = rmq[k - 1][i];
        int y = rmq[k - 1][i + (1 << (k - 1))];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }
  int minPos(int i, int j) {
    int k = logTable[j - i];
    int x = rmq[k][i], y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
};


