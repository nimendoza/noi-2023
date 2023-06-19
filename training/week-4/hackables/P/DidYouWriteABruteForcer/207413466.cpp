#include <bits/stdc++.h>
using namespace std;

using pt = pair<int,int>;
const int SENTINEL = 1 << 30;

int solve(vector<pt> pts) {
    map<int,int> xc, yc;
    for (auto [x, y] : pts) xc[x]++, yc[y]++;
    int cur = 0, ans = min(xc.size(), yc.size());
    auto decx = [&](int x) { if (!--xc[x]) xc.erase(x); };
    auto decy = [&](int y) { if (!--yc[y]) yc.erase(y); };
    auto killx = [&](int x) {
        cur++;
        vector<pt> npts;
        for (auto [X, Y] : pts) {
            if (X == x) {
                decx(X); decy(Y);
            } else {
                npts.emplace_back(X, Y);
            }
        }
        pts = npts;
    };
    auto killy = [&](int y) {
        cur++;
        vector<pt> npts;
        for (auto [X, Y] : pts) {
            if (Y == y) {
                decx(X); decy(Y);
            } else {
                npts.emplace_back(X, Y);
            }
        }
        pts = npts;
    };

    auto kill_something = [&]() {
        ans = min(ans, cur + int(min(xc.size(), yc.size())));
        int mxc = 0;
        for (auto [x, c] : xc) {
            mxc = max(mxc, c);
            if (c == 1) {
                int y = SENTINEL;
                for (auto [X, Y] : pts) {
                    if (x == X) {
                        y = Y;
                        break;
                    }
                }
                assert(y != SENTINEL);
                killy(y);
                return;
            }
        }
        for (auto [y, c] : yc) {
            mxc = max(mxc, c);
            if (c == 1) {
                int x = SENTINEL;
                for (auto [X, Y] : pts) {
                    if (y == Y) {
                        x = X;
                        break;
                    }
                }
                assert(x != SENTINEL);
                killx(x);
                return;
            }
        }
        for (auto [x, c] : xc) {
            if (c == mxc) {
                killx(x);
                return;
            }
        }
        for (auto [y, c] : yc) {
            if (c == mxc) {
                killy(y);
                return;
            }
        }
        assert(false);
    };
    while (!pts.empty()) kill_something();
    ans = min(ans, cur);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pt> pts(n);
        for (auto& [x, y] : pts) cin >> x >> y;
        cout << solve(pts) << '\n';
    }
}
