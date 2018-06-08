n = int(input())
for i in range(n):
    read = [int(i) for i in input().split(" ")]

    print("Case #%d: %s" %
          (i + 1, "true"if read[0] + read[1] > read[2] else"false"))
