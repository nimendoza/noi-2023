#include <bits/stdc++.h>
using lli = long long int;

auto _solve(int& n, std::vector<lli>& g, std::vector<lli>& h) {
    std::vector<lli> pg{g};
    for (int i{1}; i < n; ++i) {
        pg[i] += pg[i - 1];
    }

    std::vector<lli> ph{h};
    for (int i{1}; i < n; ++i) {
        ph[i] += ph[i - 1];
    }

    lli result{};
    for (int k{1}; k <= 2 * n; ++k) {
        lli max{};
        for (int i{}; i <= std::min(n, k); ++i) {
            for (int j{}; j <= std::min(n, k - i); ++j) {
                if (i && j) {
                    max = std::max(max, pg[i - 1] + ph[j - 1]);
                } else if (i) {
                    max = std::max(max, pg[i - 1]);
                } else if (j) {
                    max = std::max(max, ph[j - 1]);
                }
            }
        }

        result ^= max;
    }

    return result;
}

auto solve(int& n, std::vector<lli>& g, std::vector<lli>& h) {
    if (n < 3) {
        return _solve(n, g, h);
    }

    lli result{};
    lli** dp{new lli*[n + 1]};

    dp[0] = new lli[1];
    dp[0][0] = lli{};
    dp[1] = new lli[2];
    dp[1][0] = g[0];
    dp[1][1] = h[0];

    result ^= *std::max_element(dp[1], dp[1] + 2);

    for (int k{2}; k <= n; ++k) {
        dp[k] = new lli[k + 1];
        dp[k][0] = g[k - 1] + dp[k - 1][0];
        dp[k][k] = h[k - 1] + dp[k - 1][k - 1];
        for (int l{1}; l < k; ++l) {
            dp[k][l] = dp[k - 1][l - 1] + dp[k - 1][l] - dp[k - 2][l - 1];
        }

        result ^= *std::max_element(dp[k], dp[k] + k + 1);
    }

    for (int l{}; l <= n - 1; ++l) {
        dp[n - 1][l] = dp[n][l] + dp[n][l + 1] - dp[n - 1][l];
    }

    result ^= *std::max_element(dp[n - 1], dp[n - 1] + n);

    for (int k{n - 2}; k >= 0; --k) {
        for (int l{}; l <= k; ++l) {
            dp[k][l] = dp[k + 1][l] + dp[k + 1][l + 1] - dp[k + 2][l + 1];
        }

        result ^= *std::max_element(dp[k], dp[k] + k + 1);
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<lli> g(n);
    for (lli& x : g) {
        std::cin >> x;
    }

    std::vector<lli> h(n);
    for (lli& x : h) {
        std::cin >> x;
    }

    std::cout << solve(n, g, h) << '\n';
}
