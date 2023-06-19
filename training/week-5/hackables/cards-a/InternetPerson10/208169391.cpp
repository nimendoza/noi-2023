#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> v;

ll BIG = 999999999999999999;

int pc = 0;

struct SegTree {
    int lx, rx;
    bool meron = false;
    ll minVal, maxVal;
    ll maxValLeft = -BIG;
    ll minValRight = BIG;
    ll ans;
    ll op = 0;
    SegTree *ls = nullptr, *rs = nullptr;
    SegTree(int l, int r) {
        lx = l; rx = r;
        if(rx - lx == 1) {
            minVal = maxVal = v[lx];
            ans = 0;
        }
        else {
            int m = (l + r) / 2;
            ls = new SegTree(l, m);
            rs = new SegTree(m, r);
            minVal = min(ls->minVal, rs->minVal);
            maxVal = max(ls->maxVal, rs->maxVal);
            ans = 0;
        }
    }
    ~SegTree() {
        if(ls != nullptr) {
            delete ls;
            delete rs;
        }
    }
    void prop() {
        if(ls == nullptr) {
            op = 0;
            return;
        }
        if(op != 0) {
            ls->minVal += op;
            ls->maxVal += op;
            ls->minValRight += op;
            ls->maxValLeft += op;
            ls->op += op;
            rs->minVal += op;
            rs->maxVal += op;
            rs->minValRight += op;
            rs->maxValLeft += op;
            rs->op += op;
            op = 0;
        }
    }
    ll add(ll x, ll v) {
        prop();
        if(x >= rx) return ans;
        if(lx >= x+1) {
            minVal += v;
            maxVal += v;
            minValRight += v;
            maxValLeft += v;
            op += v;
            return ans;
        }
        if(rx - lx == 1) {
            minVal += v;
            maxVal += v;
            if(lx == x) {
                minValRight = maxValLeft = minVal;
                meron = true;
            }
            return 0;
        }
        ll al = ls->add(x, v);
        ll ar = rs->add(x, v);
        if(ls->meron) {
            maxValLeft = max(maxValLeft, ls->maxValLeft);
            maxValLeft = max(maxValLeft, rs->maxVal);
            minValRight = min(minValRight, ls->minValRight);
            meron = true;
        }
        if(rs->meron) {
            maxValLeft = max(maxValLeft, rs->maxValLeft);
            minValRight = min(minValRight, ls->minVal);
            minValRight = min(minValRight, rs->minValRight);
            meron = true;
        }
        minVal = min(ls->minVal, rs->minVal);
        maxVal = max(ls->maxVal, rs->maxVal);
        ans = max(ans, max(al, ar));
        ans = max(ans, rs->maxValLeft - ls->minVal);
        ans = max(ans, rs->maxVal - ls->minValRight);
        // cout << lx << ' ' << rx << ' ' << minVal << ' ' << maxVal << ' ' << minValRight << ' ' << maxValLeft << ' ' << ans << endl;
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    int g = 1;
    while(g < n + 1) g *= 2;
    v.resize(g);
    vector<pair<ll, int>> p;
    v[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        p.push_back({v[i], i});
        v[i] += v[i-1];
    }
    for(int i = n + 1; i < g; i++) v[i] = v[i-1];
    SegTree st(0, g);
    sort(p.rbegin(), p.rend());
    p.push_back({-1999999999999LL, -1});
    ll ans = st.ans;
    for(int i = 0; i < n; i++) {
        if(p[i].first <= 0) break;
        ll a = st.add(p[i].second, -p[i].first);
        if(p[i].first != p[i+1].first) ans = max(ans, a);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
