#include <bits/stdc++.h>
using lli = long long int;
using gnt = __int128;

const int MOD{998244353};

auto kadanes(lli& n, std::vector<gnt>& v) {
    gnt max{INT_MIN}, max_{};
    for (lli i{}; i <= n; ++i) {
        if (i < n) {
            max_ += v[i];
        }

        max = std::max(max, max_);

        if (max_ < 0) {
            max_ = 0;
        }
    }

    return max;
}

lli binpow(lli a, lli b, int k) {
    a %= k;

    lli res{1};
    while (b) {
        if (b & 1) {
            res = (res * a) % k;
        }

        a = (a * a) % k;
        b >>= 1;
    }
    return res;
}

auto solve(lli& n, int& w, int& k, int& f0, std::vector<lli>& a) {
    std::vector<int> f{f0};
    for (lli i(1); i <= n; ++i) {
        f.push_back(binpow(f[i - 1], 2, k));
    }

    std::vector<gnt> v(n);
    for (lli i{1}; i <= n; ++i) {
        v[i - 1] = -(a[f[i]] + w * i);
    }

    return int(((-kadanes(n, v) % MOD) + MOD) % MOD);
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        lli n; std::cin >> n;
        int w; std::cin >> w;
        int k; std::cin >> k;
        int f; std::cin >> f;
        std::vector<lli> a(k);
        for (int i{}; i < k; ++i) {
            std::cin >> a[i];
        }

        std::cout << solve(n, w, k, f, a) << '\n';
    }
}
