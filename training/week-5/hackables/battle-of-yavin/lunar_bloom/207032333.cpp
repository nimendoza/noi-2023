#include <bits/stdc++.h>

struct fraction {
    int numerator;
    int denominator;

    fraction(int n, int d) : numerator{n}, denominator{d} {}

    friend bool operator <(fraction a, fraction b) {
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }
};

auto solve(int& n, int& d, std::vector<int>& v, std::vector<int>& c) {
    std::priority_queue<fraction> fighters{};
    for (int i{}; i < n; ++i) {
        fighters.push(fraction(v[i], c[i]));
    }

    int result{};
    while (d && fighters.size()) {
        auto top{fighters.top()}; fighters.pop();
        result += d / top.denominator * top.numerator;
        d %= top.denominator;
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int d; std::cin >> d;
        std::vector<int> v(n);
        std::vector<int> c(n);
        for (int i{}; i < n; ++i) {
            std::cin >> v[i];
            std::cin >> c[i];
        }

        std::cout << solve(n, d, v, c) << '\n';
    }
}
