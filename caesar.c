#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


bool check_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char c1 = 'A';
            if (islower(c))
            {
                c1 = 'a';
            }
            printf("%c", (c - c1 +key) % 26 + c1);
        }
        else 
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool check_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}