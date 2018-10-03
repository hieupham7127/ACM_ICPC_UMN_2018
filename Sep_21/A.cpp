#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string, string> dict;

    while (1) {
        getline(cin, s);
        if (s.empty()) break;
        stringstream ss(s);
        string a, b;
        ss >> a >> b;
        dict[b] = a;
    }

    while (getline(cin, s)) {
        map<string, string>::iterator c;
        if ((c = dict.find(s)) != dict.end()) {
            cout << c->second << endl;
        } else {
            cout << "eh" << endl;
        }
    }
}