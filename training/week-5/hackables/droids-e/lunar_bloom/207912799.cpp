#include <bits/stdc++.h>
using lft = long double;
using lli = long long int;

auto minimize_difference(const int& n, const std::vector<lli>& v, const lli& k) {
    std::vector<lli> minsuffix(n + 1);
    minsuffix[n - 1] = v[n - 1];
    minsuffix[n] = lli(1e9);

    std::vector<lli> maxsuffix(n + 1);
    maxsuffix[n - 1] = v[n - 1];
    maxsuffix[n] = lli(-1e9);

    for (int i{n - 2}; i >= 0; --i) {
        maxsuffix[i] = std::max(maxsuffix[i + 1], v[i]);
        minsuffix[i] = std::min(minsuffix[i + 1], v[i]);
    }

    lli maxprefix{v[0]};
    lli minprefix{v[0]};
    lli mindiff{maxsuffix[k] - minsuffix[k]};
    for (int i{1}; i + k <= n; ++i) {
        lli max{std::max(maxsuffix[i + k], maxprefix)};
        lli min{std::min(minsuffix[i + k], minprefix)};
        mindiff = std::min(mindiff, max - min);
        maxprefix = std::max(maxprefix, v[i]);
        minprefix = std::min(minprefix, v[i]);
    }

    return mindiff;
}

auto solve(const int& n, const lli& d, const std::vector<lli>& h) {
    lli current{
        *std::max_element(begin(h), end(h)) 
        - *std::min_element(begin(h), end(h))
    }; if (current < d) {
        return current;
    }

    lli choose{};
    lli ceil(std::min(lli(std::ceil(lft(current) / d)), lli(n) - 1));
    for (lli k{1}; k <= ceil; ++k) {
        lli result{minimize_difference(n, h, k)};
        if (result + k * d < current + choose * d) {
            current = result;
            choose = k;
        }
    }

    return current + choose * d;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        lli d; std::cin >> d;
        std::vector<lli> h(n);
        for (lli& x : h) {
            std::cin >> x;
        }

        std::cout << solve(n, d, h) << '\n';
    } 
}
