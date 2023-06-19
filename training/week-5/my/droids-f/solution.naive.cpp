#include <bits/stdc++.h>
using vint = std::vector<int>;

auto shoot(const int& n, const int& index, const std::vector<vint>& adjacency_list, std::vector<bool> seen) -> int {
    seen[index] = true;
    for (int x : adjacency_list[index]) {
        seen[x] = true;
    }

    int result{1};
    for (int i{}; i < n; ++i) {
        if (!seen[i]) {
            result = std::max(result, shoot(n, i, adjacency_list, seen) + 1);
        }
    }

    return result;
}

auto solve(const int& n, const std::vector<int>& parent) {
    std::vector<vint> adjacency_list(n, vint{});
    for (int i{}; i < n; ++i) {
        if (parent[i] >= 0) {
            adjacency_list[i].push_back(parent[i]);
            adjacency_list[parent[i]].push_back(i);
        }
    }

    int result{};
    for (int i{}; i < n; ++i) {
        std::vector<bool> seen(n, false);
        result = std::max(result, shoot(n, i, adjacency_list, seen));
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    vint parent(n, -1);
    for (int i{1}; i < n; ++i) {
        std::cin >> parent[i];
        parent[i]--;
    }

    std::cout << solve(n, parent) << '\n';
}
