n = int(input())

minS = []
maxS = []

for i in range(n):
    s = input().split(' ')
    if not minS or int(minS[2]) > int(s[2]):
        minS = s
    if not maxS or int(maxS[2]) < int(s[2]):
        maxS = s
    # print(s,minS,maxS)

print(maxS[0],maxS[1])
print(minS[0],minS[1])
