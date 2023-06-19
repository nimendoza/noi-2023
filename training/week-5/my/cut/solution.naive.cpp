#include <bits/stdc++.h>
using lli = long long int;

auto solve(const int& n, const int& c, const std::vector<int>& v) {
    lli l{};
    lli r{1LL << 60};
    while (l != r - 1) {
        lli middle{(l + r) >> 1};
        int counts{};
        for (int u : v) {
            counts += (u + middle - 1) / middle;
        }

        if (counts <= c + n) {
            r = middle;
        } else {
            l = middle;
        }
    }

    return r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int c; std::cin >> c;
        std::vector<int> l(n);
        for (int& x : l) {
            std::cin >> x;
        }

        std::cout << solve(n, c, l) << '\n';
    }
}
