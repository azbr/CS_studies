from random import randint

n = 10
numbers = []

for i in range(10):
    numbers.append(randint(0, 100))


print("Inserion-Sort algorithm implementation")
print("")

print("Original array")
print(numbers)

for j in range(1, n):
    key = numbers[j]
    i = j - 1
    while (i >= 0 and numbers[i] > key):
        numbers[i + 1] = numbers[i]
        i = i - 1

    numbers[i + 1] = key

print("")
print("Sorted numbers")
print(numbers)
