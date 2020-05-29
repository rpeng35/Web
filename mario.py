import cs50

h = cs50.get_int("Height: ")
if h >= 1 and h <= 8:
    for i in range(h):
        print(' ' * (h - i - 1), end = "")
        print("#" * (i + 1))