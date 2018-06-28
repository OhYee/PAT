def toD(num, D):
    ans = ""
    while 1:
        ans = str(num % D) + ans
        num //= D
        if num==0:
            break
    return ans


(A, B, D) = [int(i)for i in input().split(" ")]
print(toD(A + B, D))
