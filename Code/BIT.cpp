struct BIT{
  int N;
  vector<int> v;
  BIT(int n) : N(n), v(n + 1) {}
  int sum(int i) {
    int s = 0;
    for (;i > 0; s += v[i], i -= i & -i);
    return s;
  }
  void add(int i, int x) {
    for (; i <= N; v[i] += x, i += i & -i);
  }
};

