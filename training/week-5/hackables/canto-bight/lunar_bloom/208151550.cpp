#include <bits/stdc++.h>

const int MAX(1e8);

auto solve(const int& n, const int& a, const std::vector<int>& c) {
    std::bitset<MAX + 1> bag(0ULL); bag[0] = true;
    for (int x : c) {
        bag |= (bag << x);
    }

    for (int i{a}; i >= 0; --i) {
        if (bag[i]) {
            return i;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int a; std::cin >> a;
        std::vector<int> c(n);
        for (int& x : c) {
            std::cin >> x;
        }

        std::cout << solve(n, a, c) << '\n';
    }
}
