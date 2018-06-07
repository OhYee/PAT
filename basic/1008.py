(n, m) = input().split()
a = input().split(' ')
n = int(n)
m = int(m) % n
print(" ".join([a[i - m] for i in range(n)]))
