#include <bits/stdc++.h>

auto solve(const int& n, const std::vector<bool>& v) {
    std::vector<bool> lights(v); lights.push_back(v.back());

    std::vector<int> lengths{};
    for (int i{}, current{1}; i < n; ++i, ++current) {
        if (lights[i] != lights[i + 1]) {
            continue;
        }

        lengths.push_back(current);
        current = 0;
    }

    int answer{};
    for (int i{}; i < lengths.size(); ++i) {
        answer = std::max(answer, lengths[i] + (0 <= i - 1 ? lengths[i - 1] : 0) + (i + 1 < lengths.size() ? lengths[i + 1] : 0));
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<bool> lights(n);
    for (int i{}; i < n; ++i) {
        bool c; std::cin >> c;
        lights[i] = c;
    }

    std::cout << solve(n, lights) << '\n';
}
