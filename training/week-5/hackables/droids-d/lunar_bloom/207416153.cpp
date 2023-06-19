#include <bits/stdc++.h>
using lli = long long int;

const int MOD{998244353};

auto solve(const int& n, const std::vector<lli>& a) {
    lli total{};
    for (int u{}; u < n; ++u) {
        for (int v{u}; v < n; ++v) {
            lli min{};
            for (int i{u}; i <= v; ++i) {
                for (int j{i}; j <= v; ++j) {
                    min = std::min(min, std::accumulate(begin(a) + i, begin(a) + j + 1, 0LL));
                }
            }

            total += min;
        }
    }

    return (((total % MOD) + MOD) % MOD);
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
