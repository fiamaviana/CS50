#include <cs50.h>
#include <stdio.h>

int main(void)
{
   string answer = get_string("what is your name?\n");
    printf("hello, %s\n", answer);
}