#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// Bruh bipartite matching jumpscare hahaha

vector<vector<int>> adj;
map<int, int> m1, m2;
int to[5001];
bool taken[5001];

bool dfs(int x) {
    taken[x] = true;
    for(int ch : adj[x]) {
        if(to[ch] == -1) {
            to[ch] = x;
            return true;
        }
        if(taken[to[ch]]) continue;
        if(dfs(to[ch])) {
            to[ch] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    m1.clear();
    m2.clear();
    adj.clear();
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(!m1.count(x)) {
            int g = m1.size();
            m1[x] = g;
        }
        if(!m2.count(y)) {
            int g = m2.size();
            m2[y] = g;
        }
        adj[m1[x]].push_back(m2[y]);
        taken[i] = false;
        to[i] = -1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dfs(i);
        for(int j = 0; j < n; j++) taken[j] = false;
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
