import sys, csv
# Get input from user and verify, use print to satisfy cs50x pset6 dna
if len(sys.argv) != 3:
    print("ERROR: Usage...")
    sys.exit("dna.py [database.csv] [sequence.txt]")
# Load sequence into string
with open(sys.argv[2], 'r') as txtfile:
    test_sequence = csv.reader(txtfile)
    for row in test_sequence:
        test_sequence = row
dna = test_sequence[0]
# Load database into dictionary
sequences = {}
with open(sys.argv[1], 'r') as csvfile:
    people = csv.reader(csvfile)
    for row in people:
        dna_seq = row
        dna_seq.pop(0)
        break
for item in dna_seq:
    sequences[item] = 1
# Find values from dictionary in sequence and count
for key in sequences:
    l = len(key)
    temp_max = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l
            if temp > temp_max:
                temp_max = temp
    sequences[key] += temp_max
# Search for sequence match in database
with open(sys.argv[1], newline='') as peoplefile:
    people = csv.DictReader(peoplefile)
    for person in people:
        match = 0
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            sys.exit(person['name'])
    sys.exit("No match")