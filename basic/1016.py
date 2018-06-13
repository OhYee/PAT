read = input().split(" ")
num1 = 0
num2 = 0
for i in read[0]:
    if i == read[1]:
        num1 = num1 * 10 + ord(read[1]) - ord('0')
for i in read[2]:
    if i == read[3]:
        num2 = num2 * 10 + ord(read[3]) - ord('0')
print(num1 + num2)
