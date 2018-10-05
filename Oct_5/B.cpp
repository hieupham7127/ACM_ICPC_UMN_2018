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
// const int MOD = ;

int n;
int val;
int res;
vector<int> v;
vector<int>::iterator pos;

int main() {
  cin >> n;
  while (n != 0) {
    rep(i, n) {
      cin >> val;
      v.pb(val);
    }
    sort(v.begin(), v.end());
    res = 0;
    rep(i, n - 2)
      FOR(j, i + 1, n - 1) {
        pos = upper_bound(v.begin(), v.end(), v[i] + v[j]);
        res += (v.end() - pos);
      }
    v.clear();
    cout << res << endl;
    cin >> n;
  }
}
