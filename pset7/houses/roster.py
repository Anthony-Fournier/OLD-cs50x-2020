# Anthony Fournier for cs50x pset7 houses roster.py
import sys, cs50
# Get user input from cli argument and error check
if len(sys.argv) != 2:
    print("ERROR.USAGE: roster.py [house]")
    sys.exit(1)
if (sys.argv[1]).lower() not in ["gryffindor", "hufflepuff", "ravenclaw", "slytherin"]:
    print("ERROR.USAGE: roster.py [Gryffindor, Hufflefuff, Ravenclaw, Slytherin]")
    sys.exit(1)
# Initialize database connection using cs50 resources
db = cs50.SQL("sqlite:///students.db")
# Query database db by sys.argv[1] or "house" into list students
students = db.execute("SELECT first, middle, last, birth from students WHERE \
house = ? GROUP by first ORDER by last;", sys.argv[1])
# Return requested data, in assignment requested format
for row in students:
    if row["middle"] == None:
        print(row["first"], row["last"] + ", born", row["birth"])
    else:
        print(row["first"], row["middle"], row["last"] + ", born", row["birth"])
