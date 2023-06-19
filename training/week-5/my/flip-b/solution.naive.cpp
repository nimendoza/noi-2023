#include <bits/stdc++.h>

auto flip(std::vector<bool> v, const int& i, const int& j) {
    for (int k{i}; k <= j; ++k) {
        v[k] = !v[k];
    }

    return v;
}

auto solve(const int& n, const std::vector<bool>& v) {
    int min{INT_MAX};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            auto a{flip(v, i, j)};
            for (int u{}; u < n; ++u) {
                for (int v{u}; v < n; ++v) {
                    auto b{flip(a, u, v)};
                    min = std::min(min, std::accumulate(begin(b), end(b), 0));
                }
            }
        }
    }

    auto x{begin(v) + 1};

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
