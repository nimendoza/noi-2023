#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int solve(int n, vector<int>& p) {
    vector<vector<int>> children(n+1);
    for (int i = 2; i <= n; i++) {
        children[p[i]].push_back(i);
    }
    vector<int> count(2, 0);
    function<void(int, int)> dfs = [&](int u, int c) {
        count[c] += 1;
        for (int v : children[u]) {
            dfs(v, c^1);
        }
    };
    dfs(1, 0);
    return max(count[0], count[1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n+1);
        for (int i = 2; i <= n; i++) {
            cin >> p[i];
        }
        cout << solve(n, p) << '\n';
    }
    cout << endl;
    return 0;
}