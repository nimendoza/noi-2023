#include <bits/stdc++.h>

void draw(int n, int* array) {
    for (int i{}; i < n; ++i) {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}

void fill(int n, int* array, int value) {
    for (int i{}; i < n; ++i) {
        array[i] = value;
    }
}

void reverse(int n, int* array) {
    auto swap = [](int& a, int& b) {
        int c(a);
        a = b;
        b = c;
    };

    for (int i{}; i < (n / 2); ++i) {
        swap(array[i], array[n - i - 1]);
    }
}

int* resize(int n, int* array, int k) {
    int* new_array = new int[n + k];
    for (int i{}; i < n; ++i) {
        new_array[i] = array[i];
    }

    return new_array;
}

void rotate(int n, int* array) {
    return reverse(n, array);
}

void rotate(int n, int* array, int k) {
    if (k & 1) {
        return reverse(n, array);
    }
}

int* insert(int n, int* array, int v, int i) {
    int* new_array = new int[n + 1];
    for (int j{}; j < i; ++i) {
        new_array[j] = array[j];
    }

    new_array[i] = v;
    for (int j{i + 1}; j <= n; ++j) {
        new_array[j] = array[j - 1];
    }

    return new_array;
}

int* histogram(int n, int* array) {
    auto max = [](int n, int* array) {
        int max{-1};
        for (int i{}; i < n; ++i) {
            max = max < array[i] ? array[i] : max;
        }

        return max;
    };

    int* count = new int[max(n, array) + 1];
    for (int i{}; i < n; ++i) {
        count[array[i]]++;
    }

    return count;
}
