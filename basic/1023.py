cnt = [int(i) for i in input().split(" ")]
ans = "0"
for i in range(1, 10):
    if cnt[i] > 0:
        cnt[i] -= 1
        ans = str(i)
        break
for i in range(10):
    ans += str(i) * cnt[i]

print(ans)
