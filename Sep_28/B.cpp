#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << n - m << endl;
        return 0;
    }
    int c = 0;
    while (m != n) {
        if (n > m) {
            c += n - m;
            break;
        } else {
            if (m % 2 == 0) {
                m /= 2;
            } else {
                m += 1;
            }
            c += 1;
        }
    }
    cout << c << endl;
    return 0;
}