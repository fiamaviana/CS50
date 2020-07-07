from cs50 import get_int

while True:
    n = get_int("Height\n")
    if n >= 1 and n <= 8:
        for i in range(n):
            for j in range(n - i - 1):
                print(" ",end = "")
            for k in range(i + 1):
                print("#",end ="")
            print()
        break
