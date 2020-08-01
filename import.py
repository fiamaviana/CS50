import cs50
import sys
import csv

# check command line argument
if len(sys.argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)
# open csv file given by command-line argument
db = cs50.SQL("sqlite:///students.db")
with open(sys.argv[-1], "r") as csv_file:
    reader = csv.DictReader(csv_file)
# for each row, parse name
    for row in reader:
        full_name = row['name'].split()
        first = full_name[0]
        middle = full_name[1] if len(full_name) == 3 else None
        last = full_name[-1]
        house = row['house']
        birth = row['birth']
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",first, middle, last, house, birth)
