num_a = 0
dp = {'a': 0, 'b': 0}
for c in input():
    if c == 'a':
        num_a += 1
        dp['a'] = max(dp.values()) + 1
    else:
        dp['b'] = max(num_a, dp['b']) + 1
print(max(dp['a'], dp['b']))