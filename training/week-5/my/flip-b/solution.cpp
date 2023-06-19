#include <bits/stdc++.h>

auto flip(std::vector<bool> v, const int& i, const int& j) {
    for (int k{i}; k <= j; ++k) {
        v[k] = !v[k];
    }

    return v;
}

auto get_numbers(const int& n, const std::vector<bool>& v) {
    std::vector<int> numbers(n);
    for (int i{}; i < n; ++i) {
        numbers[i] = v[i] ? 1 : -1;
    }

    return numbers;
}

auto kadanes(const int& n, const std::vector<int> v) {
    std::pair<int, int> indices{};
    for (int i{}, j{}, max_{}, max{INT_MIN}; i <= n; ++i) {
        if (i < n) {
            max_ += v[i];
        }

        if (max < max_) {
            max = max_;
            indices = {j, i};
        }

        if (max_ < 0) {
            j = i + 1;
            max_ = 0;
        }
    }

    return indices;
}

auto solve(const int& n, const std::vector<bool>& v) {
    if (std::accumulate(begin(v), end(v), 0) == n) {
        return n == 1 ? 1 : 0;
    }

    auto [i, j]{kadanes(n, get_numbers(n, v))};
    auto w{flip(v, i, j)};

    auto [s, t]{kadanes(n, get_numbers(n, w))};
    auto x{flip(w, s, t)};

    return std::accumulate(begin(x), end(x), 0);
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
