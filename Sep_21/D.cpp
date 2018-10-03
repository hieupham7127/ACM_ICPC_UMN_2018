#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        int adj[n][n];
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cin >> adj[i][j];
            }
        }

        for (int i=0;i<n;++i) {
            vector<int> b;
            for (int j=0;j<n;++j) {
                if (adj[i][j]) b.push_back(j);
            }
            bool stop = false;
            for (int j=0,l1=b.size();j<l1-1;++j) {
                if (stop) break;
                for (int k=j;k<l1; ++k) {
                    if (stop) break;
                    if (adj[b[j]][b[k]]) {
                        stop = true;
                        break;
                    }
                }
            }
            if (!stop) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}