#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;

pair<int, int> ans(int x) {
    pair<int, int> a = {1, 0};
    for(int ch : adj[x]) {
        pair<int, int> p = ans(ch);
        a.first += p.second;
        a.second += max(p.first, p.second);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }
    cout << max(ans(0).first, ans(0).second) << '\n';
}
