#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int solve(int n, vector<int>& p) {
    vector<bool> takeable(n+1, true);
    int ans = 0;
    for (int u = n; u >= 1; u--) {
        if (takeable[u]) {
            ans++;
            if (u != 1) {
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