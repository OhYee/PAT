from functools import cmp_to_key
import re

def compare(stu1, stu2):
    def getGrade(stu):
        if stu[1] >= c and stu[2] >= c:
            return 4
        elif stu[1] >= c and stu[2] < c:
            return 3
        elif stu[1] < c and stu[2] < c and stu[1] >= stu[2]:
            return 2
        else:
            return 1
    gstu1 = getGrade(stu1)
    gstu2 = getGrade(stu2)
    ret = 0
    if gstu1 == gstu2:
        if (stu1[1] + stu1[2]) == (stu2[1] + stu2[2]):
            if stu1[1] == stu2[1]:
                ret = stu2[0] - stu1[0]
            else:
                ret = stu1[1] - stu2[1]
        else:
            ret = (stu1[1] + stu1[2]) - (stu2[1] + stu2[2])
    else:
        ret = gstu1 - gstu2
    return ret

def inputInt():
    return [int(i) for i in re.findall(r"[0-9]+",input())]


(a, b, c) = inputInt()
lst = []
for i in range(a):
    stu = inputInt()
    if stu[1] >= b and stu[2] >= b:
        lst.append(stu)
lst.sort(key=cmp_to_key(compare), reverse=True)

print(len(lst))
for i in lst:
    print(" ".join([str(j) for j in i]))
