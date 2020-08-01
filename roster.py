import cs50
import sys
import csv

# check command line argument
if len(sys.argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

#query database for all students in the house
db = cs50.SQL("sqlite:///students.db")
rows = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', sys.argv[-1])
for row in rows:
    print(row['first'] + ' ' + (row['middle'] + ' ' if row['middle'] else '') + row['last'] + ', born' + str(row['birth']))
