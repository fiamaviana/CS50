from cs50 import get_float
from sys import exit

def main():
    while True:
        dollars = get_float("Cash owed: ")
        if dollars >= 0:
            break
    cents = int(dollars * 100)
    print(change(cents))

def change(cents):
    return cents//25 +  (cents%25)//10 + (cents%25%10)//5 + cents%25%10%5

if __name__ == "__main__":
    main()