import csv, sys, cs50
# Get user input from cli argument and error check
if len(sys.argv) != 2:
    print("ERROR.USAGE: import.py [file.csv]")
    sys.exit(1)
if (sys.argv[1])[-4: len(sys.argv[1]): 1] != ".csv":
    print("ERROR.USAGE: import.py [file.csv]")
    sys.exit(1)
# Initialize database using cs50 resources
db = cs50.SQL("sqlite:///students.db")
# Open and read .csv file into dictionary
with open(sys.argv[1], 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
# Split name into first name[0], middle name[1], and last name[2]
# adding None (NULL object) for any missing middle name[1]
        split_name = (row["name"]).split(' ')
        if (row["name"]).count(' ') == 1:
            split_name.append(None)
            temp = split_name[1]
            split_name[1] = split_name[2]
            split_name[2] = temp
# Write dictionary into db
        db.execute("INSERT INTO students (first, middle, last, house, birth) \
        VALUES(?, ?, ?, ?, ?)", split_name[0],split_name[1], split_name[2], row["house"], row["birth"])
