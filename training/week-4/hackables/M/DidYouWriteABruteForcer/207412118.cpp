#include <bits/stdc++.h>
using namespace std;

int solve(int t, vector<int> cs) {
    int ans = 0, p = 0;
    sort(cs.rbegin(), cs.rend());
    while (t > 0) {
        if (t >= cs[p]) {
            t -= cs[p];
            ans++;
        } else {
            p++;
        }
    }
    assert(p < cs.size());
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t; cin >> n >> t;
    vector<int> cs(n);
    for (int& c: cs) cin >> c;
    cout << solve(t, cs) << '\n';
}
