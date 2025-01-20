def xorOperation(n, start):
    result = 0
    for i in range(n):
        result ^= start + 2 * i
    return result
n, start = map(int, input("input n and start:").split())
print(xorOperation(n, start))