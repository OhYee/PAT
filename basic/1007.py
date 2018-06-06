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


n = int(input())
prime = listPrime(n)

cnt = 0
i = 1
while 1:
    if i >= len(prime) or prime[i] > n:
        break
    if prime[i] - prime[i - 1] == 2:
        cnt += 1
    i += 1
print(cnt)
