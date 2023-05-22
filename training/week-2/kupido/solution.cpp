#include <bits/stdc++.h>

std::vector<std::vector<char>> get_adjacency_list(int& n, int& a, int& b, int& x, int& y) {
    std::vector<int> degrees{};
    for (int _{}; _ < x; ++_) {
        degrees.push_back(a);
    }

    for (int _{}; _ < y; ++_) {
        degrees.push_back(b);
    }

    std::sort(begin(degrees), end(degrees));

    std::vector<std::vector<char>> adjacency_list(n, std::vector<char>(n, '.'));
    for (int i{}; i < n; ++i) {
        adjacency_list[i][i] = '\\';
    }

    for (int i{n - 1}; i >= 0; --i) {
        std::vector<int> candidates{};
        for (int j{}; j < i; ++j) {
            candidates.push_back(j);
        }

        std::sort(begin(candidates), end(candidates), [&degrees](int& a, int& b) {
            return degrees[a] < degrees[b];
        });

        for (int j{degrees[i]}; j < candidates.size(); ++j) {
            adjacency_list[candidates[j]][i] = 'L'; 
            --degrees[candidates[j]];
        }

        for (int j{}; j < degrees[i]; ++j) {
            adjacency_list[i][candidates[j]] = 'L';
        }
    }

    return adjacency_list;
}

void solve(int& a, int& b) {
    for (int x{}; x <= (a + 1) * 2; ++x) {
        for (int y{}; y <= (b + 1) * 2; ++y) {
            int n{x + y};
            if (
                n
                && (x && y || a == b)
                && (x * a + y * b == n * (n - 1) / 2)
            ) {
                auto adjacency_list{get_adjacency_list(n, a, b, x, y)};
                std::cout << "YES\n" << n << "\n";
                for (auto row : adjacency_list) {
                    for (auto col : row) {
                        std::cout << col;
                    }
                    std::cout << "\n";
                }
                return;
            }
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int a; std::cin >> a;
        int b; std::cin >> b;

        solve(a, b);
    }
}
