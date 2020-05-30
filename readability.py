import cs50

def main():
    text = cs50.get_string("Text: ")
    num_letters = 0
    num_words = 0
    num_sentences = 0
    
    """
    Coleman-Liau index
    """
    L = (float(count_letters(text, num_letters)) / float(count_words(text, num_words))) * 100.0;
    S = (float(count_sentences(text, num_sentences)) / float(count_words(text, num_words))) * 100.0;
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index >= 16:
        print("Geade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade " + str(index))


def count_letters(text, num_letters):
    """
    helper function for total number of letters
    """
    for char in text:
        if char.isalpha():
            num_letters += 1
    return num_letters
    
def count_words(text, num_words):
    """"
    helper function for total number of words
    """
    for i in range(len(text)):
        if text[i] == " ":
            num_words += 1
    return num_words + 1
    
def count_sentences(text, num_sentences):
    """
    helper function for total number of sentences
    """
    for i in range(len(text)):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            num_sentences += 1
    return num_sentences
    


if __name__ == "__main__":
    main()