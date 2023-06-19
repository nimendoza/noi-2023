#include <bits/stdc++.h>
using lli = long long int;

const int MOD{998244353};

auto kadanes(const int& u, const int& v, const std::vector<lli>& a) {
    lli min{}, min_{};
    for (lli i{u}; i <= v + 1; ++i) {
        if (i <= v) {
            min_ += a[i];
        }

        min = std::min(min, min_);

        if (min_ > 0) {
            min_ = 0;
        }
    }

    return min;
}

auto solve(const int& n, const std::vector<lli>& a) {
    int result{};
    
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            result = (((result + kadanes(i, j, a)) % MOD) + MOD) % MOD;
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
        std::vector<lli> a(n);
        for (lli& x : a) {
            std::cin >> x;
        }

        std::cout << solve(n, a) << '\n';
    }
}
