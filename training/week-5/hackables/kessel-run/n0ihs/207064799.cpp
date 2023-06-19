#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        ans += h / a[i];
        h %= a[i];
    }

    cout << ans;
}
