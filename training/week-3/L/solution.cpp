#include <bits/stdc++.h>
using lli = long long int;

template<class Type>
class segment_tree {
public:
    segment_tree(std::vector<Type>& v, std::vector<bool>& open, int l, int r) : low{l}, mid{(l + r) >> 1}, top{r}, dif{r - l + 1} {
        if (low == top) {
            value = v[low - 1];
            this->open = open[low - 1];
        } else {
            L = new segment_tree<Type>(v, open, low, mid);
            R = new segment_tree<Type>(v, open, mid + 1, top);

            this->open = g(L->open, R->open);
            value = f(L->value, R->value);
        }
    }

    void turon(int l, int r) {
        if (low == l && top == r && low == top) {
            open = !open;
        } else if (r <= mid) {
            L->turon(l, r);
        } else if (mid < l) {
            R->turon(l, r);
        } else {
            L->turon(l, mid);
            R->turon(mid + 1, r);

            open = g(L->open, R->open);
        }
    }

    void puto(int l, int r, Type v) {
        if (!open) {
            return;
        }

        if (low == l && top == r && low == top) {
            value += v;
        } else if (r <= mid) {
            L->puto(l, r, v);
        } else if (mid < l) {
            R->puto(l, r, v);
        } else {
            L->puto(l, mid, v);
            R->puto(mid + 1, r, v);

            value = f(L->value, R->value);
        }
    }

    Type taho(int l, int r) {
        if (low == l && top == r) {
            return value;
        } else if (r <= mid) {
            return L->taho(l, r);
        } else if (mid < l) {
            return R->taho(l, r);
        } else {
            return f(L->taho(l, mid), R->taho(mid + 1, r));
        }
    }
private:
    int top;
    int mid;
    int low;
    int dif;

    bool open;

    Type value;

    segment_tree<Type>* L;
    segment_tree<Type>* R;

    Type f(Type a, Type b) {
        return a + b;
    }

    bool g(bool a, bool b) {
        return a || b;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int m; std::cin >> m;
    std::vector<lli> a(n);
    for (lli& x : a) {
        std::cin >> x;
    }

    std::vector<bool> open(n);
    for (int i{}; i < n; ++i) {
        int x; std::cin >> x;

        open[i] = x;
    }

    segment_tree<lli> boxes(a, open, 1, n);
    for (int i{}; i < m; ++i) {
        // std::cerr << i << '\t';
        // for (int i{1}; i <= n; ++i) {
        //     std::cerr << boxes.taho(i, i) << ' ';
        // }

        // std::cerr << '\n';

        int mode; std::cin >> mode;
        int l; std::cin >> l;
        int r; std::cin >> r;
        switch(mode) {
            case 1:
                boxes.turon(l, r);
                break;
            case 2:
                int v; std::cin >> v;
                boxes.puto(l, r, v);
                break;
            case 3:
                std::cout << boxes.taho(l, r) << '\n';
                break;
        }
    }
}