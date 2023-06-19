#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int lsb(int x){
    return x & (-x);
}

int solve(int n, vector<pair<int, int>> a){
    set<int> xs;
    set<int> ys;
    for (auto& [x, y] : a){
        xs.insert(x);
        ys.insert(y);
    }
    int tmp = 0;
    map<int, int> xcomp;
    for (int i : xs){
        xcomp[i] = tmp++;
    }
    map<int, int> ycomp;
    for (int i : ys){
        ycomp[i] = tmp++;
    }
    for (auto& [x, y] : a){
        x = xcomp[x];
        y = ycomp[y];
    }
    map<int, int> ytox;
    for (auto& [x, y] : a){
        ytox[y] |= (1 << x);
    }
    int xmx = 1 << 18;
    vector<int> bitcnt(xmx);
    for (int i = 1; i < xmx; i++){
        bitcnt[i] = bitcnt[i ^ lsb(i)] + 1;
    }
    vector<int> cnt(xmx);
    for (auto& [y, x] : ytox){
        cnt[x]++;
    }
    int ans = 18;
    for (int i = 1; i < xmx; i++){
        if (cnt[i] == 0) continue;
        int curr = bitcnt[i];
        for (int j = 1; j < xmx; j++){
            if ((i | j) == i) continue;
            curr += cnt[j];
        }
        ans = min(ans, curr);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }
        cout << solve(n, a) << "\n";
    }
}