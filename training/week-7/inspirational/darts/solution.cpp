#include <bits/stdc++.h>
using vint = std::vector<int>;

const int capacity{4};

auto solve(const int& n, const int& m, const vint& s) {
    vint dp(capacity + 1, 0);
    for (int w{1}; w <= capacity; ++w) {
        for (int i{}; i < n; ++i) {
            for (int j{1}; j <= w; ++j) {
                dp[w] = std::max(
                    dp[w],
                    (
                        dp[w - j] + s[i] <= m
                        ? dp[w - j] + s[i]
                        : 0
                    )
                );
            }
        }
    }

    return *std::max_element(begin(dp), end(dp));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int m; std::cin >> m;
    std::vector<int> s(n);
    for (int& x : s) {
        std::cin >> x;
    }

    std::cout << solve(n, m, s) << '\n';
}
