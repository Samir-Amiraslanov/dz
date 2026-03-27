f = open("text.txt", "r") 

total = 0
count = 0
mn = float("inf")
mx = float("-inf")

for x in f.read().split():
    num = float(x)

    total += num
    count += 1

    if num < mn:
        mn = num
    if num > mx:
        mx = num

print("Сумма:", total)
print("Кол-во:", count)
print("Макс:", mx)
print("Мин:", mn)
print("Сред:", total/count)

            
f.close()
