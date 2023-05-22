#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m; std::cin >> m;
    int n; std::cin >> n;

    std::vector<int> p(n);
    for (int& x : p) {
        std::cout << 1 << std::endl;
        std::cin >> x;
        if (!x) {
            std::exit(EXIT_SUCCESS);
        }
    }

    for (int i{}, l{1}, r{m}; i < (60 - n); ++i) {
        int mid{((l + r + 1) / 2)};
        std::cout << mid << std::endl;

        int response; std::cin >> response;
        if (!response) {
            std::exit(EXIT_SUCCESS);
        } else {
            int actual{response * p[i % n]};
            if (actual == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
}
