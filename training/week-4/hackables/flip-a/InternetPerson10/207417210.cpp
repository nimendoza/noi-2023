#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int a[200001];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    a[0] = 0;
    for(int i = 0; i < n; i++) {
        a[i+1] = a[i] + (s[i] == '1' ? 1 : -1);
    }
    int mi = 0, ans = 0;
    for(int i = 0; i <= n; i++) {
        mi = min(mi, a[i]);
        ans = max(ans, a[i] - mi);
    }
    ans *= -1;
    for(int i = 0; i < n; i++) {
        ans += (s[i] == '1');
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
