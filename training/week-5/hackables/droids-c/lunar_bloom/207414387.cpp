#include <bits/stdc++.h>
using lli = long long int;
using gnt = __int128;

const int MOD{998244353};

auto kadanes(const lli& current) {
    static gnt max{};
    static gnt max_{};

    max_ += current;
    max = std::min(max, max_);
    if (max_ > 0) {
        max_ = 0;
    }

    return max;
}

auto solve(const lli& n, const int& w1, const int& k, const int& f0, const std::vector<lli>& a) {
    lli v{};
    gnt w{};
    gnt f{f0};

    lli min{*std::min_element(begin(a), end(a))};

    gnt result{};
    for (lli i(1); i <= n && min + w < 0; ++i) {
        f = (f * f) % k;
        w += w1;

        v = a[f] + w;

        result = kadanes(v);
    }

    return int(((result % MOD) + MOD) % MOD);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        lli n; std::cin >> n;
        int w; std::cin >> w;
        int k; std::cin >> k;
        int f; std::cin >> f;
        std::vector<lli> a(k);
        for (lli& x : a) {
            std::cin >> x;
        }

        std::cout << solve(n, w, k, f, a) << '\n';
    }
}
