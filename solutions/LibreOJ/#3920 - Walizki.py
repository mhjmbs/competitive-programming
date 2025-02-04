import math
import string

n = int(input())

adjacencies = [[] for _ in range(n+1)]

for u in range(1,n+1):
    input_str = input()
    input_list = list(map(int, input_str.split()))

    for i in range(1,len(input_list)):
        adjacencies[u].append(input_list[i])

k = 1

for u in range(1, n+1):
    if len(adjacencies[u]) != 0:
        k *= len(adjacencies[u])

f = [0 for _ in range(n+1)]

f[1] = k

ans = 0

for u in range(1,n+1):
    for v in adjacencies[u]:
        f[v] += f[u]//len(adjacencies[u])
    ans = math.gcd(ans, f[u])

print(k//ans)