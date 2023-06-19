#include <bits/stdc++.h>

auto flip(std::vector<bool> string, int& i, int& j) {
    for (int x{i}; x <= j; ++x) {
        string[x] = !string[x];
    }

    return std::accumulate(begin(string), end(string), 0);
}

auto solve(int& n, std::vector<bool>& string) {
    int min{INT_MAX};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            if (string[i] && string[j]) {
                min = std::min(min, flip(string, i, j));
            }
        }
    }

    if (min == INT_MAX) {
        min = 0;
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
