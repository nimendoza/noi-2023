#include <bits/stdc++.h>

auto get_numbers(int& n, std::vector<bool>& s) {
    std::vector<int> numbers{};
    for (bool x : s) {
        numbers.push_back(x ? 1 : -1);
    }

    return numbers;
}

auto kadanes(int& n, std::vector<int> a) {
    std::pair<int, int> indices{};
    for (int i{}, j{}, max_{}, max{INT_MIN}; i <= n; ++i) {
        if (i < n) {
            max_ += a[i];
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

auto solve(int& n, std::vector<bool>& s) {
    if (!std::accumulate(begin(s), end(s), 0)) {
        return 1;
    }

    auto [i, j] = kadanes(n, get_numbers(n, s));

    int result{};
    for (int k{}; k < n; ++k) {
        result += i <= k && k <= j ? !s[k] : s[k];
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<bool> s(n);
        for (int i{}; i < n; ++i) {
            char c; std::cin >> c;
            s[i] = c == '1';
        }

        std::cout << solve(n, s) << '\n';
    }
}
