#include <bits/stdc++.h>
using vint = std::vector<int>;

auto dfs(
    const int& source,
    std::vector<bool>& seen,
    std::vector<int>& connection,
    const std::vector<vint>& neighbors
) {
    seen[source] = true;
    for (int child : neighbors[source]) {
        if (connection[child] == -1) {
            connection[child] = source;

            return true;
        } else if (seen[connection[child]]) {
            continue;
        } else if (dfs(connection[child], seen, connection, neighbors)) {
            connection[child] = source;

            return true;
        }
    }

    return false;
}

auto solve(const int& n, const vint& x, const vint& y) {
    int xcount{};
    std::map<int, int> xmap{};
    for (int u : std::set(begin(x), end(x))) {
        xmap[u] = xcount++;
    }

    int ycount{};
    std::map<int, int> ymap{};
    for (int v : std::set(begin(y), end(y))) {
        ymap[v] = ycount++;
    }

    std::vector<vint> neighbors(n, vint{});
    for (int i{}; i < n; ++i) {
        neighbors[xmap[x[i]]].push_back(ymap[y[i]]);
    }

    int result{};
    std::vector<int> connection(n, -1);
    for (int i{}; i < n; ++i) {
        std::vector<bool> seen(n, false);
        result += dfs(i, seen, connection, neighbors);
    }
    
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<int> x(n);
        std::vector<int> y(n);
        for (int i{}; i < n; ++i) {
            std::cin >> x[i] >> y[i];
        }

        std::cout << solve(n, x, y) << '\n';
    }
}
