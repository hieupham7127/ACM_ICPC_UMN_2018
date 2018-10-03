#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n+10];
    int max_k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            max_k = a[i];
        } else {
            if (a[i] > max_k) max_k = a[i];
        }
    }

    int m1 = m;
    int max_el = max_k;
    while (m1--) {
        int min_ind = 0, min;
        for (int i=0;i < n;++i) {
            if (i==0) {
                min_ind = 0;
                min = a[i];
            } else {
                if (a[i] < min) {
                    min = a[i];
                    min_ind = i;
                }
            }
        }
        a[min_ind]++;
        if (a[min_ind] > max_el) {
            max_el = a[min_ind];
        }
    }

    // printf("%d %d\n", *max_element(&a[0], &a[n-1]), max_k + m);
    cout << max_el << " " << (max_k + m) << endl;
}
