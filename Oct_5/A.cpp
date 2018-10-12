#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define mp make_pair

unordered_map<int, pair<int, int>> m;
int n, p;

int main() {
    cin >> n;
    rep1(i, n)
        m[i] = mp(0, 0);
    FOR(i, 2, n) {
        cin >> m[i].first;
        m[m[i].first].second++;
    }
    vector<int> deg(n + 1);
    rep1(i, n)
        if (m[i].second == 0)
            deg[m[i].first]++;
    rep1(i, n)
        if (m[i].second > 0 && deg[i] < 3) {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}
