#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string CLASS = get_string("WHAT CLASS IS THIS !\n");
    printf("Hello, %s!\n", CLASS);
}