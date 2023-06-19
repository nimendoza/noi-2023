#include <bits/stdc++.h>
using vint = std::vector<int>;

struct point {
    int x;
    int y;

    point() : x{}, y{} {}
    point(int x, int y) : x{x}, y{y} {}
};

auto match(
    const std::vector<std::vector<bool>>& grid,
    const std::vector<point>& points,
    const std::map<int, int>& xpos,
    const std::map<int, int>& ypos,
    const int& xsize,
    const int& ysize,
    const int& n,
    vint& height,
    vint& width
) {
    do {
        do {
            std::vector<std::vector<bool>> map(begin(grid), end(grid));
            for (int i{}; i < ysize; ++i) {
                if (height[i]) {
                    for (int x{}; x < xsize; ++x) {
                        map[x][i] = true;
                    }
                }
            }

            for (int i{}; i < xsize; ++i) {
                if (width[i]) {
                    for (int y{}; y < ysize; ++y) {
                        map[i][y] = true;
                    }
                }
            }

            if (std::all_of(begin(points), end(points), [&](const point& p) {
                return map[xpos.at(p.x)][ypos.at(p.y)];
            })) {
                return true;
            }
        } while (std::next_permutation(begin(height), end(height)));
    } while (std::next_permutation(begin(width), end(width)));

    return false;
}

auto solve(const int& n, const vint& x, const vint& y) {
    std::vector<point> points(n);
    for (int i{}; i < n; ++i) {
        points[i].x = x[i];
        points[i].y = y[i];
    }

    std::set<int> xs(begin(x), end(x));
    std::map<int, int> xpos{};

    int position{};
    for (auto i{begin(xs)}; i != end(xs); ++i) {
        xpos[*i] = position++;
    }

    std::set<int> ys(begin(y), end(y));
    std::map<int, int> ypos{};

    position = 0;
    for (auto i{begin(ys)}; i != end(ys); ++i) {
        ypos[*i] = position++;
    }

    int xcount(xs.size());
    int ycount(ys.size());

    std::vector<std::vector<bool>> grid(xcount, std::vector<bool>(ycount, false));

    int result{INT_MAX};
    for (int x{}; x <= xcount; ++x) {
        vint height(n, 0);
        for (int i{}; i < x; ++i) {
            height[i] = 1;
        }

        std::reverse(begin(height), end(height));

        for (int y{}; y <= ycount; ++y) {
            if (x || y) {
                vint width(n, 0);
                for (int i{}; i < y; ++i) {
                    width[i] = 1;
                }

                std::reverse(begin(width), end(width));

                if (match(grid, points, xpos, ypos, xcount, ycount, n, height, width)) {
                    result = std::min(result, x + y);
                }

                std::sort(begin(height), end(height));
            }
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<int> x(n);
        std::vector<int> y(n);
        for (int i{}; i < n; ++i) {
            std::cin >> x[i] >> y[i];
        }

        std::cout << solve(n, x, y) << '\n';
    }
}
