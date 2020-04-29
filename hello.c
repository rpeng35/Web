#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("hello, world\n");
    string name = get_string("What is your name?\n");   /*type: string, variable: name*/
    printf("hello, %s\n", name);                        /*%s is the place holder, name is the additional arugument*/
}

