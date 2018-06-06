def Callatz(n):
    global keyNum
    isFirst = True
    while n > 1:
        if isFirst:
            isFirst = False
        else:
            if n in keyNum:
                keyNum.remove(n)
        if n % 2 == 1:
            n = (3 * n + 1) / 2
        else:
            n /= 2


n = int(input())
lst = [int(i) for i in input().split(' ')]
lst.sort(reverse=True)
keyNum = lst.copy()
for i in range(n):
    Callatz(lst[i])
print(" ".join([str(i) for i in keyNum]))
