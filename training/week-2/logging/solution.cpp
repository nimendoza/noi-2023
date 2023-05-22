#include <bits/stdc++.h>
using lli = long long int;

const int MOD{int(1e9) + 7};

int solve(int& n, std::vector<lli>& d, std::vector<lli>& v) {
    std::vector<std::pair<lli, lli>> ranked(n);
    for (int i{}; i < n; ++i) {
        ranked[i] = {v[i], d[i]};
    }

    std::sort(rbegin(ranked), rend(ranked));

    int total{};
    for (int i{}; i < n; ++i) {
        total = (total + ranked[i].second + ranked[i].first * i) % MOD;
    }

    return total;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;

        std::vector<lli> d(n);
        for (lli& x : d) {
            std::cin >> x;
        }

        std::vector<lli> v(n);
        for (lli& x : v) {
            std::cin >> x;
        }

        std::cout << solve(n, d, v) << '\n';
    }
}