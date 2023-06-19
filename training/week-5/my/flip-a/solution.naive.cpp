#include <bits/stdc++.h>

auto flip(std::vector<bool> v, const int& i, const int& j) {
    for (int x{i}; x <= j; ++x) {
        v[x] = !v[x];
    }

    return std::accumulate(begin(v), end(v), 0);
}

auto solve(const int& n, const std::vector<bool>& v) {
    int min{INT_MAX};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            min = std::min(min, flip(v, i, j));
        }
    }

    return min;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<bool> string(n);
        for (int i{}; i < n; ++i) {
            char c; std::cin >> c;
            string[i] = c == '1';
        }

        std::cout << solve(n, string) << '\n';
    }
}
