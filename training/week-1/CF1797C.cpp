#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int m; std::cin >> m;
        std::cout << "? 1 1" << std::endl;

        int x; std::cin >> x;
        std::cout << "? " << std::min(x, n - 1) + 1 << " 1" << std::endl;

        int l; std::cin >> l;
        std::cout << "? 1 " << std::min(l, m - 1) + 1 << std::endl;

        int r; std::cin >> r;
        std::cout << "! " << r + 1 << ' ' << l + 1 << std::endl;
    }
}
