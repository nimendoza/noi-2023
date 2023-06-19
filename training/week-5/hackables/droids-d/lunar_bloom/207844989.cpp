#include <bits/stdc++.h>
using lli = long long int;

const int MOD{998244353};

const bool debug{};

struct data {
    lli min;
    lli frontier;
    bool is_tail;

    data() : min{}, frontier{}, is_tail{} {}
    data(lli min, lli frontier, bool is_tail) : min{min}, frontier{frontier}, is_tail{is_tail} {}

    auto print() {
        std::stringstream stream{};
        stream << '(' << min << ",\t" << frontier << ",\t" << is_tail << ')';

        return stream.str();
    }
};

auto solve(const int& n, const std::vector<lli>& a) {
    data** dp{new data*[n + 1]};
    for (int i{1}; i <= n; ++i) {
        dp[i] = new data[n - i + 2];
        for (int j{1}; j <= n - i + 1; ++j) {
            dp[i][j] = data();
        }
    }

    lli total{};
    for (int i{1}; i <= n; ++i) {
        dp[1][i] = data(a[i - 1], a[i - 1], true);

        if (debug) {
            std::cerr << dp[1][i].print() << '\t';
        }

        if (dp[1][i].min < 0) {
            total = (total + dp[1][i].min) % MOD;
        }
    }

    if (debug) {
        std::cerr << '\n';
    }

    for (int k{2}, m{n - 1}; k <= n; ++k, --m) {
        for (int i{}; debug && i < (k - 1) * 3; ++i) {
            std::cerr << '\t';
        }

        for (int i{1}; i <= m; ++i) {
            std::array<lli, 3> choose;
            if (dp[k - 1][i].is_tail) {
                choose = {
                    dp[k - 1][i].min,
                    dp[1][k + i - 1].min,
                    dp[k - 1][i].frontier + dp[1][k + i - 1].min,
                };
            } else if (
                dp[k - 1][i].min == dp[k - 2][i].min
                && dp[k - 1][i].frontier == dp[k - 2][i].frontier + dp[1][k + i - 3].frontier
            ) {
                choose = {
                    std::min(dp[k - 1][i].min, dp[1][k + i - 1].min),
                    dp[1][k + i - 1].min,
                    dp[k - 1][i].frontier + dp[1][k + i - 1].min,
                };
            } else {
                choose = {
                    dp[k - 1][i].min,
                    dp[1][k + i - 1].min,
                    dp[k - 1][i].frontier + dp[1][k + i - 1].min,
                };
            }

            dp[k][i].frontier = std::min(choose[1], choose[2]);
            dp[k][i].min = *std::min_element(begin(choose), end(choose));
            if (dp[k][i].min == choose[2] || dp[k][i].min == choose[1]) {
                dp[k][i].is_tail = true;
            } else if (dp[k][i].min == choose[0]) {
                dp[k][i].is_tail = false;
            } else {
                assert(false);
            }

            if (debug) {
                std::cerr << dp[k][i].print() << '\t';
            }

            if (dp[k][i].min < 0) {
                total = (total + dp[k][i].min) % MOD;
            }
        }

        if (debug) {
            std::cerr << '\n';
        }
    }

    return ((total % MOD) + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<lli> a(n);
        for (lli& x : a) {
            std::cin >> x;
        }

        std::cout << solve(n, a) << '\n';
    }
}
