def listPrime(MAX):
    isPrime = [True for i in range(MAX + 1)]
    isPrime[0] = isPrime[1] = False
    prime = []
    for i in range(2, MAX + 1):
        if isPrime[i]:
            prime.append(i)
        for j in range(0, len(prime)):
            if i * prime[j] > MAX:
                break
            isPrime[i * prime[j]] = False
            if not (i % prime[j]):
                break
    return prime


prime = listPrime(110000)
(n, m) = [int(i)for i in input().split(" ")]

isFirst = True
cnt = 0
for i in range(n, m + 1):
    if cnt == 10:
        print("\n", end="")
        cnt = 0
        isFirst = True
    if isFirst:
        isFirst = False
    else:
        print(" ", end="")
    cnt += 1
    print(prime[i - 1], end="")
print("\n", end="")
