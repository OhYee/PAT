import re
read = ""
try:
    while 1:
        read += " " + input()
except:
    pass
read = [int(i) for i in re.findall(r"[\-0-9]+", read)]

ans = []
for i in range(1, len(read), 2):
    a = read[i - 1]
    n = read[i]
    # print(a, n)
    if n != 0:
        ans += [a * n, n - 1]
if len(ans) == 0:
    ans = [0, 0]
print(" ".join([str(i) for i in ans]))
