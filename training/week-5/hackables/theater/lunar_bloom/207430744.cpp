#include <bits/stdc++.h>
using lli = long long int;

struct job {
    lli begin;
    lli end;

    job() : begin{}, end{} {}
    job(lli i, lli j) : begin{i}, end{j} {}

    friend bool operator <(job a, job b) {
        return a.end < b.end;
    }
};

auto binary_search(const std::vector<job>& jobs, const int& index) {
    int low{};
    int top{index - 1};
    while (low <= top) {
        int mid{(low + top) >> 1};
        if (jobs[mid].end < jobs[index].begin) {
            if (jobs[mid + 1].end < jobs[index].begin) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            top = mid - 1;
        }
    }

    return -1;
}

auto solve(const int& n, const std::vector<lli>& l, const std::vector<lli>& r) {
    std::vector<job> jobs(n);
    for (int i{}; i < n; ++i) {
        jobs[i] = job(l[i], r[i]);
    }

    std::sort(begin(jobs), end(jobs));

    int* matrix{new int[n]}; matrix[0] = 1;
    for (int i{1}; i < n; ++i) {
        int current{1};

        int result{binary_search(jobs, i)};
        if (result != -1) {
            current += matrix[result];
        }

        matrix[i] = std::max(current, matrix[i - 1]);
    }

    int result{matrix[n - 1]};

    delete matrix;

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<lli> l(n);
        std::vector<lli> r(n);
        for (int i{}; i < n; ++i) {
            std::cin >> l[i] >> r[i];
        }

        std::cout << solve(n, l, r) << '\n';
    }
}
