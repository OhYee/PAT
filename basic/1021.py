s = input()
cnt = [0 for i in range(10)]
for i in s:
    cnt[ord(i) - ord('0')] += 1
for i in range(10):
    if cnt[i] != 0:
        print("%d:%d" % (i, cnt[i]))
