#include <bits/stdc++.h>

auto solve(
    const int& n,
    const int& d,
    const std::vector<int>& v,
    const std::vector<int>& c
) {
    std::vector<int> dp(d * d, 0);
    for (int i{}; i < d * d; ++i) {
        for (int j{}; j < n; ++j) {
            if (v[j] <= i) {
                dp[i] = std::max(dp[i], dp[i - v[j]] + c[j]);
            }
        }
    }

    for (int& x : dp) {
        if (!x) {
            x = INT_MAX;
        }
    }

    for (int x : dp) {
        if (x != int(INT_MAX)) {
            std::cerr << x << ' ';
        }
    }

    std::cerr << '\n';

    return *std::min_element(begin(dp) + d, end(dp));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int d; std::cin >> d;
        std::vector<int> v(n);
        for (int& x : v) {
            std::cin >> x;
        }

        std::vector<int> c(n);
        for (int& x : c) {
            std::cin >> x;
        }

        std::cout << solve(n, d, v, c) << '\n';
    }
}
