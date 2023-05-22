#include <bits/stdc++.h>

int main() {
    int n; std::cin >> n;

    int** array = new int*[n];
    for (int i{1}; i <= n; ++i) {
        array[i] = new int[i];
    }
}
