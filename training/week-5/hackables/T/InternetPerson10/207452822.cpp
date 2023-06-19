#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> v;

void solve2(int s) {
    int n = v.size();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += v[i];
    }
    if(n % s == 0) {
        cout << ans;
        return;
    }
    vector<vector<ll>> d(s - n%s);
    for(int i = 0; i < v.size(); i++) {
        if(i%s >= n%s) d[s-1-(i%s)].push_back(v[i]);
    }
    /*
    for(int i = 0; i < d.size(); i++) {
        for(int g : d[i]) {
            cout << g << ' ';
        }
        cout << endl;
    }
    */
    int x = d[0].size();
    for(int j = 1; j < x; j++) {
        d[0][j] = min(d[0][j], d[0][j-1]);
    }
    for(int i = 1; i < d.size(); i++) {
        d[i][0] += d[i-1][0];
        for(int j = 1; j < x; j++) {
            d[i][j] = min(d[i][j-1], d[i-1][j] + d[i][j]);
        }
    }
    cout << ans + d.back().back();
    d.clear();
}

void solve() {
    int n, q;
    cin >> n >> q;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while(q--) {
        int s;
        cin >> s;
        solve2(s);
        if(q) cout << ' ';
    }
    cout << '\n';
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
