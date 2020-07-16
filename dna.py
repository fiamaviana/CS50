from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(0)

with open(argv[2]) as file:
    dreader = reader(file)
    for row in dreader:
        sequence = row
dna = sequence[0]
sequences = {}
with open(argv[1]) as databasefile:
    database = reader(databasefile)
    for row in database:
        dnaSequences = row
        dnaSequences.pop(0)
        break
for item in dnaSequences:
    sequences[item] = 1
for key in sequences:
    l = len(key)
    tMax = 0
    t = 0
    for i in range (len(dna)):
        while t > 0:
            t -= 1
            continue
        if dna[i : i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                t += 1
                i += l
            if t > tMax:
                tMax = t
    sequences[key] += tMax
with open(argv[1], newline = '') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()
    print("Not match")