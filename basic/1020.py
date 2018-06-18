(n, D) = [int(i) for i in input().split(" ")]
w = [float(i) for i in input().split(" ")]
p = [float(i) for i in input().split(" ")]
node = [(w[i], p[i]) for i in range(n)]
node.sort(key=lambda x: x[1] / x[0], reverse=True)
ans = 0.0
for i in range(n):
    if D >= node[i][0]:
        ans += node[i][1]
        D -= node[i][0]
    else:
        ans += D * node[i][1] / node[i][0]
        D = 0
    if D == 0:
        break
print("%.2f" % (round(ans * 100) / 100))
