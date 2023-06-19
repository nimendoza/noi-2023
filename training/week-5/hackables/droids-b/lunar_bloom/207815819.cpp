#include <bits/stdc++.h>
using lli = long long int;
using vlli = std::vector<lli>;

auto recurse(const int n, const int k, const vlli& b, const vlli& c) {
    if (!n) {
        return 0LL;
    }

    if (!k) {
        return 0LL;
    }

    return std::max({
        recurse(n - 1, k, b, c),
        recurse(n - 1, k - 1, b, c) + b[n - 1],
        k > 1 ? recurse(n - 1, k - 2, b, c) + c[n - 1] : -1,
    });
}

auto solve(const int& n, const int& k, const vlli& b, const vlli& d) {
    vlli c(n);
    for (int i{}; i < n; ++i) {
        c[i] = b[i] + d[i];
    }

    return recurse(n, k, b, c);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int k; std::cin >> k;
        vlli b(n);
        for (lli& x : b) {
            std::cin >> x;
        }

        vlli d(n);
        for (lli& x : d) {
            std::cin >> x;
        }

        std::cout << solve(n, k, b, d) << '\n';
    }
}
