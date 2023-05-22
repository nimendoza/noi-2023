#include <bits/stdc++.h>

const int k{166};

const std::vector<std::pair<int, int>> directions{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

class disjoint_set_union {
public:
    disjoint_set_union(int n) : n(n), parent(n, -1), size(n, 1) {}

    int find(int x) {
        if (parent[x] < 0) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) {
            return;
        }

        if (size[root_a] < size[root_b]) {
            std::swap(root_a, root_b);
        }

        parent[root_b] = root_a;
        size[root_a] += size[root_b];
    }
private:
    int n;
    std::vector<int> size;
    std::vector<int> parent;
};

void solve(int& n, int& m, int& c, std::vector<int>& p, std::vector<std::vector<int>>& grid) {
    int x{n * k};
    int y{m * k};
    std::vector<std::vector<int>> map(x, std::vector<int>(y, 0));
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            map[i * k][j * k] = grid[i][j];
        }
    }

    std::vector<std::vector<bool>> adjacency_matrix(c + 1, std::vector<bool>(c + 1, false));
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            for (auto [id, jd] : directions) {
                int in{i + id};
                int jn{j + jd};
                if (0 <= in && in < n && 0 <= jn && jn < m) {
                    int a{grid[i][j]};
                    int b{grid[in][jn]};
                    adjacency_matrix[a][b] = true;
                }
            }
        }
    }

    disjoint_set_union dsu(n * m);
    for (int a{}; a < n; ++a) {  // for loops are so hard...
        for (int b{}; b < m; ++b) {
            if (!grid[a][b]) {
                continue;
            }

            for (int d{}; d < 2; ++d) {
                int i{a + directions[d].first};
                int j{b + directions[d].second};
                if (0 <= i && i < n && 0 <= j && j < m) {
                    if (!grid[i][j]) {
                        continue;
                    }

                    if (grid[a][b] == grid[i][j]) {
                        if (dsu.find(a * m + b) == dsu.find(i * m + j)) {
                            continue;
                        }

                        dsu.unite(a * m + b, i * m + j);
                    } else if (!adjacency_matrix[grid[a][b]][grid[i][j]]) {
                        continue;
                    }

                    adjacency_matrix[grid[a][b]][grid[i][j]] = false;
                    adjacency_matrix[grid[i][j]][grid[a][b]] = false;

                    for (int ak{a * k}; ak <= i * k; ++ak) {
                        for (int bk{b * k}; bk <= j * k; ++bk) {
                            if (!map[ak][bk]) {
                                map[ak][bk] = grid[a][b];
                            }
                        }
                    }
                }
            }
        }
    }

    std::vector<int> count(c, 0);
    for (int i{}; i < x; ++i) {
        for (int j{}; j < y; ++j) {
            if (map[i][j]) {
                ++count[map[i][j] - 1];
            }
        }
    }

    int max{};
    for (int i{}; i < c; ++i) {
        max = std::max(max, (count[i] + p[i] - 1) / p[i]);
    }

    for (int country{}; country < c; ++country) {
        int target{max * p[country] - count[country]};
        for (int i{}; target && i < n; ++i) {
            for (int j{}; target && j < m; ++j) {
                if (grid[i][j] == country + 1) {
                    for (int ik{i * k}; target && ik < (i + 1) * k; ++ik) {
                        for (int jk{j * k}; target && jk < (j + 1) * k; ++jk) {
                            if (!map[ik][jk]) {
                                map[ik][jk] = country + 1;
                                --target;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << x << ' ' << y << '\n';
    for (auto& row : map) {
        for (auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int m; std::cin >> m; 
        int c; std::cin >> c;

        std::vector<int> p(c);
        for (int& x : p) {
            std::cin >> x;
        }

        std::vector<std::vector<int>> grid(n, std::vector<int>(m));
        for (auto& row : grid) {
            for (auto& cell : row) {
                std::cin >> cell;
            }
        }

        solve(n, m, c, p, grid);
    }
}