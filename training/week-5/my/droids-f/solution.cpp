#include <bits/stdc++.h>
using vint = std::vector<int>;

const int MAX(5e5);

auto dfs(
    const std::vector<vint>& neighbors,
    const int source,
    const int& parent,
    const bool take,
    const bool reset
) {
    static int dp[MAX][2];
    if (reset) {
        memset(dp, -1, sizeof(dp));
    }

    if (dp[source][take] != -1) {
        return dp[source][take];
    }

    int best(take);
    for (int neighbor : neighbors[source]) {
        if (neighbor != parent) {
            best += (
                take ? dfs(neighbors, neighbor, source, false, false) 
                : std::max(
                    dfs(neighbors, neighbor, source, true, false),
                    dfs(neighbors, neighbor, source, false, false)
                )
            );
        }
    }

    return dp[source][take] = best;
}

auto solve(const int& n, const vint& parent) {
    std::vector<vint> neighbors(n, vint{});
    for (int i{1}; i < n; ++i) {
        neighbors[parent[i]].push_back(i);
        neighbors[i].push_back(parent[i]);
    }

    return std::max(
        dfs(neighbors, 0, parent[0], true, true),
        dfs(neighbors, 0, parent[0], false, true)
    );
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
