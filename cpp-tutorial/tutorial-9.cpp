#include <bits/stdc++.h>
using lli = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    lli n; std::cin >> n;
    for (lli i{}; i < n; ++i) {
        n -= i;
    }

    std::cout << n << '\n';
}
