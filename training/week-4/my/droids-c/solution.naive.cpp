#include <bits/stdc++.h>
using lli = long long int;
using gnt = __int128;

const int MOD{998244353};

auto solve(const lli& n, const int& w, const int& k, const int& f0, const std::vector<lli>& a) {
    std::vector<int> f{f0};
    for (lli i(1); i <= n; ++i) {
        f.push_back((lli(f[i - 1]) * f[i - 1]) % k);
    }

    std::vector<lli> v(n);
    for (lli i(1); i <= n; ++i) {
        v[i - 1] = a[f[i]] + w * i;
    }

    gnt min{};
    for (lli i{}; i < n; ++i) {
        for (lli j{i}; j < n; ++j) {
            min = std::min(min, std::accumulate(begin(v) + i, begin(v) + j + 1, gnt{}));
        }
    }

    return int(((min % MOD) + MOD) % MOD);
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
