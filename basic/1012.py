read = [int(i) for i in input().split(" ")]
n = read[0]
del read[0]

calc = [[], [], [], [], []]
for i in read:
    calc[i % 5].append(i)

ans = []
calc[0] = [i for i in calc[0] if i % 2 == 0]
calc[1] = [i * (-((idx % 2) * 2 - 1)) for (idx, i) in enumerate(calc[1])]

ans.append(str(sum(calc[0])) if len(calc[0]) > 0 else "N")
ans.append(str(sum(calc[1])) if len(calc[1]) > 0 else "N")
ans.append(str(len(calc[2])) if len(calc[2]) > 0 else "N")
ans.append(str(round(sum(calc[3]) / len(calc[3])*10)/10) if len(calc[3]) > 0 else "N")
ans.append(str(max(calc[4])) if len(calc[4]) > 0 else "N")

print(" ".join(ans))
