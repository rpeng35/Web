from cs50 import SQL
import csv
from sys import argv, exit

house_name = argv[1]
db = SQL("sqlite:///students.db")

rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first",
        house_name)

for i in rows:
    if i["middle"] != None:
        print(i["first"], i["middle"], i["last"] + ",", i["birth"])
    else:
        print(i["first"], i["last"] + ",", i["birth"])submit50 cs50/problems/2020/x/houses