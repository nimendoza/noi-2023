#include <bits/stdc++.h>
using lli = long long int;

const lli MAX(1e11);
const int MOD(1e9 + 7);

std::set<lli> strong_bots{1LL};

void get_strong_bots() {
	for (lli i(2); i * i * i * 4 <= MAX; ++i) {
		for (lli j(2); i * i * i * j * j <= MAX; ++j) {
			strong_bots.insert(i * i * i * j * j);
		}
	}

	for (lli i(2); i * i <= MAX; ++i) {
		for (lli j{i}; i * j <= MAX; j *= i) {
			if (strong_bots.find(i * j) != end(strong_bots)) {
				strong_bots.erase(i * j);
			}
		}
	}
}

int solve(int& h, int& w, std::vector<std::vector<lli>>& mactan) {
	std::vector<int> rows{};
	std::vector<int> cols{};
	std::vector<std::vector<int>> prefix_sums(h + 1, std::vector<int>(w + 1, 0));
	for (int r{}; r < h; ++r) {
		for (int c{}; c < w; ++c) {
			prefix_sums[r + 1][c + 1] = (
				prefix_sums[r][c + 1]
				+ prefix_sums[r + 1][c]
				- prefix_sums[r][c]
			);

			if (strong_bots.find(mactan[r][c]) != end(strong_bots)) {
				rows.push_back(r);
				cols.push_back(c);
				++prefix_sums[r + 1][c + 1];
			}
		}
	}

	std::sort(begin(rows), end(rows));
	std::sort(begin(cols), end(cols));

	int answer{};
	int total{prefix_sums[h][w]};
	for (int row_divisor{1}; row_divisor <= total; ++row_divisor) {
		if (total % row_divisor) {
			continue;
		}

		lli current(1);
		for (int i{row_divisor}; current && i < total; i += row_divisor) {
			current = (current * (rows[i] - rows[i - 1])) % MOD;
		}

		int col_divisor{total / row_divisor};
		for (int i{col_divisor}; current && i < total; i += col_divisor) {
			current = (current * (cols[i] - cols[i - 1])) % MOD;
		}

		for (int r{1}; current && r <= row_divisor; ++r) {
			for (int c{1}; current && c <= col_divisor; ++c) {
				current = (
					current * (
						prefix_sums[
							rows[c * row_divisor - 1] + 1
						][
							cols[r * col_divisor - 1] + 1
						] == r * c
					)
				) % MOD;
			}
		}

		answer = (answer + current) % MOD;
	}

	return ((answer % MOD) + MOD) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_strong_bots();

	int t; std::cin >> t;
	for (int _{}; _ < t; ++_) {
		int h; std::cin >> h;
		int w; std::cin >> w;
		std::vector<std::vector<lli>> mactan(h, std::vector<lli>(w));
		for (auto& row : mactan) {
			for (lli& cell : row) {
				std::cin >> cell;
			}
		}

		std::cout << solve(h, w, mactan) << '\n';
	}
}