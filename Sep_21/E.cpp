#include <iostream>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define SIZE 31

int n;
int f[SIZE] = {0}, g[SIZE] = {0};

int main() {
    // initialize base cases
    f[0] = 1;
    g[1] = 1;
    // create all solutions
    FOR(i, 2, SIZE) {
        if (i % 2 == 0)
            f[i] = f[i - 2] + 2 * g[i - 1];
        else g[i] = f[i - 1] + g[i - 2];
    }
    cin >> n;
    while (n != -1) {
        cout << f[n] << endl;
        cin >> n;
    }
}
