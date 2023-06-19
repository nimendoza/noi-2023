#include <bits/stdc++.h>
using namespace std;

int solve(const string& a) {
    int t = 0;
    deque<char> ts;
    deque<int> cs;
    for (char c : a) {
        t += c == '1';
        if (!ts.empty() && ts.back() == c) {
            cs.back()++;
        } else {
            ts.push_back(c);
            cs.push_back(1);
        }
    }
    assert(!ts.empty());
    int sz = a.size();
    if (!ts.empty() && ts.front() == '0') {
        sz -= cs.front();
        ts.pop_front();
        cs.pop_front();
    }
    if (!ts.empty() && ts.back() == '0') {
        sz -= cs.back();
        ts.pop_back();
        cs.pop_back();
    }
    if (ts.empty()) {
        assert(t == 0);
        return 1;
    } else {
        int ans = min(sz - t, t - 1);
        int mx = 0;
        for (int i = 0; i < ts.size(); i += 2) {
            assert(ts[i] == '1');
            if (cs[mx] < cs[i]) mx = i;
        }

        int l = mx, r = mx + 1;
        while (true) {
            if (l >= 2 && cs[l - 1] <= cs[l - 2]) {
                l -= 2;
            } else if (l >= 4 && cs[l - 1] + cs[l - 3] <= cs[l - 2] + cs[l - 4]) {
                l -= 4;
            } else if (l >= 6 && cs[l - 1] + cs[l - 3] + cs[l - 5] <= cs[l - 2] + cs[l - 4] + cs[l - 6]) {
                l -= 6;
            } else if (r + 2 <= ts.size() && cs[r] <= cs[r + 1]) {
                r += 2;
            } else if (r + 4 <= ts.size() && cs[r] + cs[r + 2] <= cs[r + 1] + cs[r + 3]) {
                r += 4;
            } else if (r + 6 <= ts.size() && cs[r] + cs[r + 2] + cs[r + 4] <= cs[r + 1] + cs[r + 3] + cs[r + 5]) {
                r += 6;
            } else {
                break;
            }
        }
        int cur = t;
        for (int i = l, s = -1; i < r; i++, s = -s) cur += s * cs[i];
        return min(ans, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n;
        string a;
        cin >> n >> a;
        cout << solve(a) << '\n';
    }
}
