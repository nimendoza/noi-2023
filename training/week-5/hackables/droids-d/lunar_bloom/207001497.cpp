#include <bits/stdc++.h>
using lli = long long int;

const int MOD{998244353};

auto kadanes(int& u, int v, std::vector<lli>& a) {
    lli max{INT_MIN}, max_{};
    for (lli i{u}; i <= v + 1; ++i) {
        if (i <= v) {
            max_ += a[i];
        }

        max = std::max(max, max_);

        if (max_ < 0) {
            max_ = 0;
        }
    }

    return max;
}

auto solve(int& n, std::vector<lli>& a) {
    std::vector<lli> b{a};
    for (lli& x : b) {
        x = -x;
    }

    int result{};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            result = (((result + -kadanes(i, j, b)) % MOD) + MOD) % MOD;
        }
    }

    return result;
}

int main(int argc, char** argv) {
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
