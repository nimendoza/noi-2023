#include <bits/stdc++.h>

bool valid(int& r, int& c, int& x, int& y, int& u, int& v) {
    return (
        !(x == u && y == v)
        && (0 <= v && v < r)
        && (0 <= u && u < c)
    );
}

std::vector<std::pair<int, int>> neighbors(int& r, int& c, int& x, int& y) {
    std::vector<std::pair<int, int>> adjacent_cells{};
    for (int dx{-1}; dx < 2; ++dx) {
        for (int dy{-1}; dy < 2; ++dy) {
            int u{x + dx};
            int v{y + dy};
            if (valid(r, c, x, y, u, v)) {
                adjacent_cells.push_back({u, v});
            }
        }
    }

    return adjacent_cells;
}

std::vector<std::vector<bool>> solve(int& r, int& c, std::vector<std::vector<bool>>& grid) {
    std::vector<std::vector<bool>> new_grid(r, std::vector<bool>(c));
    for (int i{}; i < r; ++i) {
        for (int j{}; j < c; ++j) {
            int surrounding_alive{};
            for (auto [x, y] : neighbors(r, c, j, i)) {
                if (grid[y][x]) {
                    surrounding_alive++;
                }
            }

            if (grid[i][j]) {
                new_grid[i][j] = surrounding_alive == 2 || surrounding_alive == 3;
            } else {
                new_grid[i][j] = surrounding_alive == 3;
            }
        }
    }

    return new_grid;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r; std::cin >> r;
    int c; std::cin >> c;
    std::vector<std::vector<bool>> grid(r, std::vector<bool>(c));
    for (auto& row : grid) {
        for (int i{}; i < c; ++i) {
            bool alive; std::cin >> alive;
            row[i] = alive;
        }
    }

    for (auto row : solve(r, c, grid)) {
        for (auto cell : row) {
            std::cout << cell << ' ';
        }

        std::cout << '\n';
    }
}