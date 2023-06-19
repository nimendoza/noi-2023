#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int a[200001];
int b[200001], c[200001];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int t = 0; t < 2; t++) {
        a[0] = 0;
        for(int i = 0; i < n; i++) {
            a[i+1] = a[i] + (s[i] == '1' ? 1 : -1);
        }
        int mi = 0, ans = 0, ct = 0;
        for(int i = 0; i <= n; i++) {
            mi = min(mi, a[i]);
            ans = max(ans, a[i] - mi);
            if(i > 0) if(s[i-1] == '1') ct++;
            if(t == 0) b[i] = ct - ans;
            if(t == 1) c[i] = ct - ans;
        }
        reverse(s.begin(), s.end());
    }
    int ans = 999999;
    for(int i = 0; i <= n; i++) {
        ans = min(ans, b[i] + c[n-i]);
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
