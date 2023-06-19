#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, score = 10e9; cin >> n;
    string str; cin >> str;

    vector<int> count1 = {0}, count0 = {0};
    int t1 = 0, t0 = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '1') ++t1;
        else ++t0;
        count1.push_back(t1);
        count0.push_back(t0);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = str.substr(i, (j-i)+1);
            score = min(score, (count1[n]-(count1[j+1]-count1[i]))+(count0[j+1]-count0[i]));
        }
    }
    cout << score << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}