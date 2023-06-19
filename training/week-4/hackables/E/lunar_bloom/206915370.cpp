#include <bits/stdc++.h>
using lli = long long int;

struct bot {
    lli value;
    bot* counterpart;

    bot(lli value) : value{value}, counterpart{nullptr} {}
    bot(lli value, lli counterpart_value) : value{value}, counterpart{new bot(counterpart_value)} {}

    bool swap() {
        if (counterpart) {
            value = counterpart->value;

            delete counterpart;
            counterpart = nullptr;
            
            return true;
        }

        return false;
    }

    friend bool operator <(bot a, bot b) {
        if (a.value == b.value) {
            if (a.counterpart && b.counterpart) {
                return a.counterpart < b.counterpart;
            } else if (a.counterpart) {
                return a.counterpart->value / 2 < b.value;
            } else if (b.counterpart) {
                return a.value < b.counterpart->value / 2;
            } else {
                return true;
            }
        }

        return a.value < b.value;
    }
};

auto solve(int& n, int& k, std::vector<lli>& b, std::vector<lli>& d) {
    std::priority_queue<bot> pq{};
    for (int i{}; i < n; ++i) {
        pq.push(bot(b[i], d[i]));
    }

    lli result{};
    for (int i{}; i < k; ++i) {
        auto top{pq.top()}; pq.pop();
        result += top.value;

        if (top.swap()) {
            pq.push(top);
        }
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int k; std::cin >> k;
        std::vector<lli> b(n);
        for (lli& x : b) {
            std::cin >> x;
        }

        std::vector<lli> d(n);
        for (lli& x : d) {
            std::cin >> x;
        }

        std::cout << solve(n, k, b, d) << '\n';
    }
}
