#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> count1, count0;

int solve(string& str, int n) {
    if (str == "1") return 1;
    vector<int>().swap(count1); vector<int>().swap(count0);
    count1.push_back(0); count0.push_back(0);

    int score = 10e9;

    int t1 = 0, t0 = 0;
    for (const char i : str) {
        if (i == '1') ++t1;
        else ++t0;
        count1.push_back(t1);
        count0.push_back(t0);
    }
    if (count1[n]-count1[0] == 0) return 0;

    int sI, sJ;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = str.substr(i, (j-i)+1);
            int flipped = (count1[n]-(count1[j+1]-count1[i]))+(count0[j+1]-count0[i]);
            if (flipped < score) {
                score = flipped;
                sI = i; sJ = j;
            }
        }
    }

    for (int i = 0; i < str.size(); ++i) {
        if (i >= sI && i <= sJ) {
            if (str[i] == '1') str[i] = '0';
            else str[i] = '1';
        }
    }

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t > 0) {
        int n, ans; cin >> n;
        string str; cin >> str;
        ans = solve(str, n);
        ans = solve(str, n);
        cout << ans << '\n';
        t--;
    }
}