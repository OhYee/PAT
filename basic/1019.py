s = int(input())


while 1:
    s = [i for i in str(s)]
    while len(s) != 4:
        s.append('0')
    s.sort()
    a = int("".join(s))
    s.sort(reverse=True)
    b = int("".join(s))
    s = b - a
    print("%04d - %04d = %04d" % (b, a, s))
    if s == 0 or s == 6174:
        break
