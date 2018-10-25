const int MAX_N = 200100;
struct Choose {
  int fac[MAX_N + 1], inv[MAX_N + 1];
  int inverse(int a) {
    return a==1?1:(int)((MOD-MOD/a)*1ll*inverse(MOD%a)%MOD);
  }
  void init() {
    fac[0] = inv[0] = 1;
    rep1(i,MAX_N) fac[i] = (int) ((fac[i-1]*1ll*i)%MOD);
    rep1(i,MAX_N) inv[i] = inverse(fac[i]);
  }
  int choose(int a, int b) {
    return (int) ((fac[a]*1ll*inv[b]%MOD)*inv[a-b]%MOD);
  }
};
