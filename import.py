from cs50 import SQL
from sys import argv, exit
import csv

db = SQL("sqlite:///students.db")

def split_name(full_name):
    names = full_name.split()
    if len(names) == 3:
        return names
    else:
        return [names[0], None, names[1]]

csv_path = argv[1]
with open(csv_path) as csv_file:
    reader = csv.DictReader(csv_file)
    for row in reader:
        names = split_name(row["name"])
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
        names[0], names[1], names[2], row["house"], row["birth"])