#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int last_max;
    int first = 1;
    for (int i= 0;i <n;++i) {
        int a, b;
        cin >> a >> b;
        int min = (a > b) ? b : a;
        int max = (a > b) ? a : b;
        if (first) {
            last_max = max;
            first = 0;
            continue;
        }
        if (min > last_max) {
            printf("NO\n");
            return 0;
        } else {
            if (max <= last_max)
                last_max = max;
            else
                last_max = min;
        }
    }
    printf("YES\n");
}