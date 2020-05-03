#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int num_words, num_letters, num_sentences;
    num_words = num_letters = num_sentences = 0;
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            num_letters++;      //add one to num_letters if is a alphabet
        }
            
        if ((i == 0 && text[i] != ' ') || (i != len - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            num_words++;        //add one to num_words if a sequence of letters is separated by spaces
        }
            
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            num_sentences++;        //add one to num_sentences if encounters one of '.', '?', or '!'
        }
    }
    float L = ((float) num_letters / (float) num_words) * 100;
    float S = ((float) num_sentences / (float) num_words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);              
    
    if (index < 1)
    {
        printf("Before Grade 1\n");        //returns "Before Grade 1" if index is less than 1
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");            //returns "Grade 16+" if index is greater or equal to 16
    }
    else
    {
        printf("Grade %i\n", index);      //returns returns "Grade %i" where %i is the place holder for index
    }
}