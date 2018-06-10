read = []
try:
    while 1:
        s = input()
        if len(s) > 0:
            read.append(s)
except:
    pass

(a, b, c, d) = read

weekday = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]

A = -1
B = -1
C = -1


def checkChar(c, a, b):
    if ord(c) >= ord(a) and ord(c) <= ord(b):
        return True
    else:
        return False


length = min(len(a), len(b))
for i in range(length):
    if A == -1:
        if a[i] == b[i] and checkChar(a[i], 'A', 'G'):
            A = i
    else:
        if a[i] == b[i] and (checkChar(a[i], 'A', 'N') or a[i].isdigit()):
            B = i
            break

length = min(len(c), len(d))
for i in range(length):
    if c[i] == d[i] and c[i].isalpha():
        C = i


print("%s %02d:%02d" % (
    weekday[ord(a[A]) - ord('A')], ord(a[B]) -
    ord('0') if a[B].isdigit() else ord(a[B]) - ord('A') + 10,
    C))
