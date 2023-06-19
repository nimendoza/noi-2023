#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct mxsub{
    ll summ, mx, mxl, mxr;
    mxsub(ll summ, ll mx, ll mxl, ll mxr) : summ(summ), mx(mx), mxl(mxl), mxr(mxr) {}
};

mxsub combine(mxsub a, mxsub b){
    ll summ = a.summ + b.summ;
    ll mx = max(max(a.mx, b.mx), a.mxr + b.mxl);
    ll mxl = max(a.mxl, a.summ + b.mxl);
    ll mxr = max(a.mxr + b.summ, b.mxr);
    return mxsub(summ, mx, mxl, mxr);
}

int pow2ceil(int n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

ll solve(int n, vector<ll> a){
    int N = pow2ceil(n);
    vector<mxsub> seg(N * 2, mxsub(0, -1e12, -1e12, -1e12));
    for (int i = 0; i < n; i++){
        seg[i + N] = mxsub(a[i], a[i], a[i], a[i]);
    }
    for (int i = N - 1; i > 0; i--){
        seg[i] = combine(seg[i * 2], seg[i * 2 + 1]);
    }
    vector<int> bigl(n), bigr(n);
    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++){
        mp[-a[i]].push_back(i);
    }
    set<int> s{-1, n};
    for (auto&[_, v] : mp){
        for (int i: v){
            auto it = s.lower_bound(i);
            bigr[i] = (*it) - 1;
            it--;
            bigl[i] = (*it) + 1;
        }
        for (int i: v){
            s.insert(i);
        }
    }
    ll maxx = 0;
    for (int i = 0; i < n; i++){
        int l = bigl[i] + N;
        int r = bigr[i] + N;
        mxsub maxl = mxsub(0, -1e12, -1e12, -1e12);
        mxsub maxr = mxsub(0, -1e12, -1e12, -1e12);
        while (l <= r){
            if (l % 2 == 1){
                maxl = combine(maxl, seg[l]);
                l++;
            }
            if (r % 2 == 0){
                maxr = combine(seg[r], maxr);
                r--;
            }
            l >>= 1; r >>= 1;
        }
        maxl = combine(maxl, maxr);
        maxx = max(maxx, maxl.mx - a[i]);
    }
    return maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << "\n";
    }
}