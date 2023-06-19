#include <bits/stdc++.h>

auto memoize(int& n, std::vector<bool>& string) {
    std::vector<std::vector<int>> sum_length(n + 1, std::vector<int>(n, 0));
    for (int i{}; i < n; ++i) {
        sum_length[1][i] = string[i];
    }

    for (int k{2}; k <= n; ++k) {
        for (int i{k - 1}; i < n; ++i) {
            sum_length[k][i] = sum_length[k - 1][i - 1] + sum_length[1][i];
        }
    }

    return sum_length;
}

auto get_fix(int l, int r, std::vector<std::vector<int>>& sum_length) {
    if (l > r) {
        return 0;
    }

    return sum_length[r - l + 1][r];
}

auto solve(int& n, std::vector<bool>& string) {
    if (n == 1) {
        return 0;
    }

    auto sum_length{memoize(n, string)};

    int min{std::accumulate(begin(sum_length[1]), end(sum_length[1]), 0)};
    for (int k{1}; k <= n; ++k) {
        for (int i{k - 1}; i < n; ++i) {
            int prefix{get_fix(0, i - k, sum_length)};
            int flipped{k - sum_length[k][i]};
            int suffix{get_fix(i + 1, n - 1, sum_length)};
            min = std::min(min, prefix + flipped + suffix);
        }
    }

    return min;
}

int main(int argc, char** argv) {
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
