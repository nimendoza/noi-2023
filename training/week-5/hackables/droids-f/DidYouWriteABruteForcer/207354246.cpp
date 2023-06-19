#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int solve(int n, vector<int>& p) {
    vector<int> child_count(n+1, 0);
    vector<bool> takeable(n+1, true);
    for (int i = 2; i <= n; i++) {
        child_count[p[i]]++;
    }
    queue<int> leaves;
    for (int u = 1; u <= n; u++) {
        if (child_count[u] == 0) {
            leaves.push(u);
        }
    }
    int ans = 0;
    while (!leaves.empty()) {
        int u = leaves.front();
        leaves.pop();
        bool taken = false;
        if (takeable[u]) {
            ans++;
            taken = true;
        }
        if (u != 1) {
            child_count[p[u]]--;
            if (child_count[p[u]] == 0) {
                leaves.push(p[u]);
            }
            if (taken) {
                takeable[p[u]] = false;
            }
        }
    }
    return ans;
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