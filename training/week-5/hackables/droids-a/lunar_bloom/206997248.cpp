#include <bits/stdc++.h>
using lli = unsigned long long int;

std::map<std::pair<int, int>, lli> memo;

auto get(int l, int r) {
    if (l > r) {
        return lli{};
    }

    if (memo[{l, r}]) {
        return memo[{l, r}];
    }

    return memo[{l, r}] = get(l, (r + l) >> 1) + get(((r + l) >> 1) + 1, r);
}

auto solve(int& n, std::vector<lli>& g, std::vector<lli>& h) {
    std::vector<lli> a(rbegin(g), rend(g));
    for (lli x : h) {
        a.push_back(x);
    }

    for (int i{}; i < 2 * n; ++i) {
        memo[{i, i}] = a[i];
    }

    lli result{};
    for (int i{n}, j{n}, k{1}; k <= 2 * n; i = n, ++j, ++k) {
        if (std::min(j, 2 * n - 1) - n < k) {
            if (j > 2 * n - 1) {
                j = 2 * n - 1;
            }
            
            i = j - k + 1;
        }
        
        assert(j - i + 1 == k);

        lli max{};
        for (int l{}; l <= k && i - l >= 0; ++l) {
            max = std::max(max, get(i - l, j - l));
        }

        result ^= max;
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<lli> g(n);
    for (lli& x : g) {
        std::cin >> x;
    }

    std::vector<lli> h(n);
    for (lli& x : h) {
        std::cin >> x;
    }

    std::cout << solve(n, g, h) << '\n';
}
