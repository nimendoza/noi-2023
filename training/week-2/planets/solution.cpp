#include <bits/stdc++.h>
using lli = long long int;

/** Neomi's thought process
 * 1. Say that we cut the array such that for each part of the array, when we sort them, the entire array is sorted.
 * 2. We say that a set of cuts are *good* when #1 is achieved, and *bad* otherwise.
 * 2.1. Example: [1, 3, 2]
 * 2.2. A cut consisting of [1] and [3, 2] is good.
 * 3. We can then redefine `f(s)` to be the largest number of good cuts (plus one) we could make in the array `s`.
*/

class sparse_table {
public:
    sparse_table(int& n, std::vector<int>& a) : n(n), table(std::ceil(std::log2(n + 1)), std::vector<int>(n, 0)) {
        for (int i{}; i < n; ++i) {
            table[0][i] = a[i];
        }

        for (int i{1}; (1 << i) <= n; ++i) {
            for (int j{}; j + (1 << i) <= n; ++j) {
                table[i][j] = std::max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k(std::floor(std::log2(r - l)));
        return std::max(table[k][l], table[k][r - (1 << k)]);
    }
private:
    int n;
    std::vector<std::vector<int>> table;
};

std::vector<int> get_smaller_left(std::vector<int>& a) {
    std::vector<int> smaller_left(a.size(), -1);
    for (int i{}; i < a.size(); ++i) {
        int j{i - 1};
        while (j >= 0 && a[j] > a[i]) {
            j = smaller_left[j];
        }

        smaller_left[i] = j;
    }

    return smaller_left;
}

int binary_search(std::vector<int>& a, sparse_table& table, int l, int r, int x, int y) {
    if (r - l == 1) {
        if (a[l] > x) {
            return l;
        }

        return -1;
    }

    int m{(l + r) / 2};
    if (table.query(m, y) > x) {
        return binary_search(a, table, m, r, x, y);
    }

    return binary_search(a, table, l, m, x, y);
}

lli solve(int& n, std::vector<int>& a) {
    sparse_table table(n, a);
    auto smaller_left{get_smaller_left(a)};
    // std::cerr << "smaller_left: ";
    // for (int x : smaller_left) {
    //     std::cerr << x << ' ';
    // }
    // std::cerr << '\n';
    
    for (int& x : a) {
        x = -x;
    }

    auto larger_left{get_smaller_left(a)};
    // std::cerr << "larger_left: ";
    // for (int x : larger_left) {
    //     std::cerr << x << ' ';
    // }
    // std::cerr << '\n';

    for (int& x : a) {
        x = -x;
    }

    std::reverse(begin(a), end(a));

    auto smaller_right{get_smaller_left(a)};
    // std::cerr << "smaller_right: ";
    // for (int x : smaller_right) {
    //     std::cerr << x << ' ';
    // }
    // std::cerr << '\n';

    std::reverse(begin(a), end(a));

    lli result(n - 1 - smaller_right[n - 1]);
    for (int i{1}; i < n; ++i) {
        int left{};
        if (a[i] > a[i - 1]) {
            left = larger_left[i];
        } else if (smaller_left[i] < 1) {
            left = -1;
        } else {
            int x{smaller_left[i]};
            left = binary_search(a, table, 0, x, a[i], x);
        }

        int x{n - 1 - i};
        // std::cerr << x << '\n';
        result += lli(i - left) * (x - smaller_right[x]);
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int& x : a) {
            std::cin >> x;
        }

        std::cout << solve(n, a) << '\n';
    }
}