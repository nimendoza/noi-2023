#include <bits/stdc++.h>

auto solve(int& n, int& a, std::vector<int>& c) {
    int min{*std::min_element(begin(c), end(c))}; a -= min - 1;
    for (int& x : c) {
        x -= min - 1;
    }

    int dp[a + 1]; memset(dp, 0, sizeof(dp));
    for (int i{1}; i <= n; ++i) {
        for (int weight{a}; weight >= 0; --weight) {
            if (c[i - 1] <= weight) {
                dp[weight] = std::max(dp[weight], dp[weight - c[i - 1]] + c[i - 1]);
            }
        }
    }

    for (int i{}; i <= a; ++i) {
        std::cerr << dp[i] << ' ';
    }

    std::cerr << '\n';

    return dp[a] + min - 1;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int a; std::cin >> a;
        std::vector<int> c(n);
        for (int& x : c) {
            std::cin >> x;
        }

        std::cout << solve(n, a, c) << '\n';
    }
}
