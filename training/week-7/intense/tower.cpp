#include <bits/stdc++.h>

auto solve(const int& n, const std::string& s) {
    auto check{[&](const int& x) {
        std::array<int, 3> joi{0, 0, 0};
        for (int i{n - 1}; i >= 0; --i) {
            if (s[i] == 'J' && joi[1]) {
                joi[0]++;
                joi[1]--;
            } else if (s[i] == 'O' && joi[2]) {
                joi[1]++;
                joi[2]--;
            } else if (s[i] == 'I') {
                if (std::accumulate(begin(joi), end(joi), 0) < x) {
                    joi[2]++;
                } else if (joi[1]) {
                    joi[0]++;
                    joi[1]--;
                }
            }
        }

        return joi[0] >= x;
    }};

    int l{};
    int r{n - 3};
    while (l < r) {
        int m{(l + r + 1) >> 1};
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::string s; std::cin >> s;

    std::cout << solve(n, s) << '\n';
}
