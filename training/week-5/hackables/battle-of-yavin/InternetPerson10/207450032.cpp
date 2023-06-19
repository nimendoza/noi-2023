#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int mi[10001];

void solve() {
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= 10000; i++) mi[i] = -1;
    mi[0] = 0;
    while(n--) {
        int v, c;
        cin >> v >> c;
        for(int i = 0; i <= 10000 - c; i++) {
            mi[i+c] = max(mi[i+c], mi[i]+v);
        }
        for(int i = 0; i < 10000; i++) {
            mi[i+1] = max(mi[i], mi[i+1]);
        }
    }
    cout << mi[d] << '\n';
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
