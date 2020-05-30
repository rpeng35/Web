import cs50

def main():
    while True:
        """ 
        get user input
        """
        dollars = cs50.get_float("Change owed: ")
        """
        ensure positive input only
        """
        if dollars >= 0:
            break

    cents = int(dollars * 100)
    num_coins = 0
    print(coins(cents, num_coins))

def coins(cents, num_coins):
    while (cents > 0):
        """
        greedy algorithm
        """
        if cents >= 25:
            cents -= 25
            num_coins += 1
        elif cents >= 10:
            cents -= 10
            num_coins += 1
        elif cents >= 5:
            cents -= 5
            num_coins += 1
        else:
            cents -= 1
            num_coins += 1
    
    return num_coins

"""
run main function first
"""
if __name__ == "__main__":
    main()