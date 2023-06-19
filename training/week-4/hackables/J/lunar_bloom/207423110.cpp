#include <bits/stdc++.h>
using lli = long long int;

auto solve(const int& n, const std::vector<lli>& v) {
    lli result{LONG_LONG_MIN};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            result = std::max(
                result,
                std::accumulate(begin(v) + i, begin(v) + j + 1, 0LL)
                - *std::max_element(begin(v) + i, begin(v) + j + 1)
            );
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<lli> v(n);
        for (lli& x : v) {
            std::cin >> x;
        }

        std::cout << solve(n, v) << '\n';
    }
}
