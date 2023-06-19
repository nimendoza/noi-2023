#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

template<class T>
vector<T> sums(const vector<T>& vec) {
    vector<T> s(1);
    for (T v : vec) s.push_back(s.back() + v);
    return s;
}

vector<ll> solve(const vector<ll>& _g, const vector<ll>& _h) {
    auto g = sums(_g);
    auto h = sums(_h);
    vector<ll> ans(g.size() + h.size() - 1, -INF);
    int x = 0, y = 0;
    ans[0] = 0;
    for (int sz = 1; sz < ans.size(); sz++) {
        int bx = min(int(g.size()) - 1, sz), by = sz - bx;
        assert(bx + by == sz);
        auto try_candidate = [&](int x, int y) {
            assert(0 <= x && x <= g.size() && 0 <= y && y <= h.size());
            assert(x + y == sz);
            if (g[bx] + h[by] < g[x] + h[y]) {
                bx = x; by = y;
            }
        };
        for (auto [x, y] : vector<pair<int,int>>{
                    {sz + 1 >> 1, sz >> 1},
                    {sz >> 1, sz + 1 >> 1},
                    {min(int(g.size()) - 1, sz), sz - min(int(g.size()) - 1, sz)},
                    {sz - min(int(h.size()) - 1, sz), min(int(h.size()) - 1, sz)},
                    {0, sz},
                    {sz, 0},
                    {x + 1, y},
                    {x, y + 1},
                }) {
            for (int d = -8; d <= 8; d++) {
                int xx = x + d, yy = y - d;
                if (0 <= xx && xx <= g.size() && 0 <= yy && yy <= h.size()) {
                    try_candidate(xx, yy);
                }
            }
        }
        ans[sz] = g[bx] + h[by];
        x = bx, y = by;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<ll> g(n), h(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    ll ans = 0;
    for (ll v : solve(g, h)) ans ^= v;
    cout << ans << '\n';
}
