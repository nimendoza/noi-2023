#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> han = {0}, greedo = {0}, sums;

    ll gsum = 0, hsum = 0;
    for (int i = 0; i < n; ++i) {
        ll g; cin >> g;
        gsum += g; greedo.push_back(gsum);
    }
    for (int i = 0; i < n; ++i) {
        ll h; cin >> h;
        hsum += h; han.push_back(hsum);
    }

    ll sum = 0;
    for (int i = 1; i < (2*n)+1; ++i) {
        if (i <= n) {
            for (int j = 0; j < i+1; ++j) {
                int k = i;
                sum = max(sum, (greedo[k-j]-greedo[0])+(han[j]-han[0]));
            }
        } else {
            for (int j = 0; j < i-(2*(i-n)-1); ++j) {
                int k = i-n;
                sum = max(sum, (greedo[n-j]-greedo[0])+(han[k+j]-han[0]));
            }
        }
        sums.push_back(sum);
        sum = 0;
    }

    ll ans = sums[0];
    for (int i = 1; i < sums.size(); ++i) {
        ans ^= sums[i];
    }

    cout << ans << '\n';
}