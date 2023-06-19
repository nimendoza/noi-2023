#include <bits/stdc++.h>
using lli = long long int;

struct data {
    lli sum;
    lli max;

    data(lli s, lli m) : sum{s}, max{m} {}

    friend bool operator <(data a, data b) {
        return a.sum - a.max < b.sum - b.max;
    }
};

auto solve(const int& n, const std::vector<lli>& v) {
    if (std::all_of(begin(v), end(v), [](lli x) {
        return x <= 0;
    })) {
        return 0LL;
    }

    std::priority_queue<data> collection{};
    for (lli i{}, max{}, max_{}, current_max{}; i <= n; ++i) {
        if (i < n) {
            max_ += v[i];
            current_max = std::max(current_max, v[i]);
        }

        if (max < max_) {
            max = max_;
            collection.push(data(max, current_max));
        }

        if (max_ < 0 || i == n) {
            current_max = 0;
            max_ = 0;
        }
    }

    auto result{collection.top()};

    return result.sum - result.max;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<lli> v(n);
        for (lli& x : v) {
            std::cin >> x;
        }

        std::cout << solve(n, v) << '\n';
    }
}
