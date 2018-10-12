#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define db(x) {cout << #x << " = " << (x) << endl;}
#define dba(a, x, y) {cout<<#a<<" :";FOR(i123,x,y)cout<<setw(4)<<(a)[i123];cout<<endl;}
#define clr(x) memset(x,0,sizeof(x));
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
typedef long long ll;
typedef long double ld;
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const ld pi = acos(-1);

struct BIT{
  int N;
  vector<int> v;
  vector<int> val;
  BIT(int n) : N(n), v(n + 1) {}
  int findMax(int i) {
    int s = 0;
    for (;i > 0; s = max(s, v[i]), i -= i & -i);
    return s;
  }
  void add(int i, int x) {
    for (; i <= N; v[i] = max(v[i], x), i += i & -i);
  }
};

const int RANGE = 100001;
BIT fenwick(RANGE);
int n, a, maxVal;
int res;

int main() {
    cin >> n;
    rep(i, n) {
        cin >> a;
        maxVal = fenwick.findMax(a - 1) + 1;
        fenwick.add(a, maxVal);
        res = max(res, maxVal);
    }
    cout << res << endl;
    return 0;
}
