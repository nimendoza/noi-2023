#include <bits/stdc++.h>

void move(int n, char destination_rod, std::vector<char>& in) {
    std::cout << "Move from " << in[n] << " to " << (in[n] = destination_rod) << ".\n";
}

char remaining(char x, char y) {
    std::set<char> remains{'A', 'B', 'C'};
    remains.erase(x);
    remains.erase(y);

    return *begin(remains);
}

void solve_toh(int n, char destination_rod, std::vector<char>& in) {
    if (n == 0) {
        return move(n, destination_rod, in);
    }

    solve_toh(n - 1, remaining(destination_rod, in[n - 1]), in);
    move(n, destination_rod, in);
    solve_toh(n - 1, destination_rod, in);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        char s; std::cin >> s;
        char d; std::cin >> d;

        std::vector<char> in(n, s);
        solve_toh(n - 1, d, in);
        std::cout << "Done!\n";
    }
}