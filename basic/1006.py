n = int(input())
print(('B' * ((n // 100) % 10)) + ('S' * ((n // 10) % 10)) +
      "".join([str(i) for i in range(1, (n % 10) + 1)]))
