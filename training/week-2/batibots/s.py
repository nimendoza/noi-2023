MAX = int(1e11)
MOD = int(1e9) + 7

def get_strong_bots():
	strong_bots = set()
	for i in range(2, MAX):
		if pow(i, 3) * 4 > MAX:
			break
		for j in range(2, MAX):
			if pow(i, 3) * pow(j, 2) > MAX:
				break
			strong_bots.add(pow(i, 3) * pow(j, 2))
	for i in range(2, MAX):
		if pow(i, 2) > MAX:
			break
		for j in range(i, MAX, i):
			if i * j > MAX:
				break
			if i * j in strong_bots:
				strong_bots.remove(i * j)

	return strong_bots

STRONG_BOTS = get_strong_bots()

def solve(h, w, mactan):
	rows = list()
	cols = list()
	prefix_sums = list(list(0 for _ in range(w + 1)) for _ in range(h + 1))
	for r in range(h):
		for c in range(w):
			prefix_sums[r + 1][c + 1] = (
				prefix_sums[r][c + 1]
				+ prefix_sums[r + 1][c]
				- prefix_sums[r][c]
			)

			if mactan[r][c] in STRONG_BOTS:
				rows.append(r)
				cols.append(c)
				prefix_sums[r + 1][c + 1] += 1

	rows.sort()
	cols.sort()

	answer = 0
	total = prefix_sums[h][w]
	for row_divisor in range(1, total):
		if total % row_divisor:
			continue

		current = 1
		for i in range(row_divisor, total, row_divisor):
			if not current:
				break
			current = (current * (rows[i] - rows[i - 1])) % MOD
		
		col_divisor = total // row_divisor
		for i in range(col_divisor, total, col_divisor):
			if not current:
				break
			current = (current * (cols[i] - cols[i - 1])) % MOD
		for r in range(1, row_divisor + 1):
			if not current:
				break
			for c in range(1, col_divisor + 1):
				if not current:
					break
				current = (
					current * (
						prefix_sums[
							rows[c * row_divisor - 1] + 1
						][
							cols[r * col_divisor - 1] + 1
						] == r * c
					)
				) % MOD
		answer = (answer + current) % MOD

	return answer

if __name__ == '__main__':
	for _ in range(int(input())):
		h, w = map(int, input().split())
		mactan = list(list(map(int, input().split())) for _ in range(h))
		print(solve(h, w, mactan))