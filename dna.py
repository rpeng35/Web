from sys import argv
import cs50
import csv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
        
    csv_file = argv[1]
    with open(csv_file) as csvfile:
        read = csv.reader(csvfile)
        all_seq = next(read)[1:]

        sequence = argv[2]
        with open(sequence) as txtfile:
            str = txtfile.read()
            actual = [get_max(str, seq) for seq in all_seq]
    
        #helper -> determines if our calculated value matches actual
        print_match(read, actual)
    
    

def get_max(str, sub):
    #get max length of repeated sequence
    repeat = [0] * len(str)
    for i in range(len(str) - len(sub), -1, -1):
        if str[i : i + len(sub)] == sub:
            if i + len(sub) > len(str) - 1:
                repeat[i] = 1
            else:
                repeat[i] = 1 + repeat[i + len(sub)]
    return max(repeat)
                

def print_match(read, actual):
    for line in read:
        person = line[0]
        values = [ int(val) for val in line[1:] ]
        if values == actual:
            print(person)
            return
    print("No match")


if __name__ == "__main__":
    main()