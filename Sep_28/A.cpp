#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define range(i, L, R) for (i = L; i < R; i ++)
#define ranges(i, L, R, step) for (i = L; i < R; i += step)
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); ++it)
#define foreachr(it, l) for (auto it = l.rbegin(); it != l.rend(); ++it)
#define in(el, lst) (lst.find(el) != lst.end())

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

bool check(int n) {
    bool x = false;
    if (n == 1 || n == 0) {
        return true;
    }
    if (n >= 144 && n % 1000 == 144) {
        x |= check(n / 1000);
    }
    if (n >= 14 && n % 100 == 14) {
        x |= check(n / 100);
    }
    if (n % 10 == 1) {
        x |= check(n / 10);
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "YES" << endl;
        return 0;
    }
    cout << (check(n) ? "YES" : "NO") << endl;
    return 0;
}