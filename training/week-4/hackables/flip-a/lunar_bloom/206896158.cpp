#include <bits/stdc++.h>

auto get_numbers(int& n, std::vector<bool>& string) {
    std::vector<int> numbers{};
    for (bool x : string) {
        numbers.push_back(x ? 1 : -1);
    }

    return numbers;
}

auto kadanes(std::vector<int>& array) {
    std::pair<int, int> indices{};
    for (int i{}, j{}, max_{}, max{INT_MIN}; i <= array.size(); ++i) {
        if (i < array.size()) {
            max_ += array[i];
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

auto solve(int& n, std::vector<bool>& string) {
    auto numbers{get_numbers(n, string)};
    auto [i, j] = kadanes(numbers);
    if ((i == -1 && j == -1) || !std::accumulate(begin(string), end(string), 0)) {
        return std::accumulate(begin(string), end(string), 0);
    }

    int result{};
    for (int k{}; k < i; ++k) {
        result += string[k];
    }

    for (int k{i}; k <= j; ++k) {
        result += !string[k];
    }

    for (int k{j + 1}; k < n; ++k) {
        result += string[k];
    }

    return result;
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
