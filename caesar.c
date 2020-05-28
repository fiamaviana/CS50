#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("key must be positive\n");
        return 1;
    }
    
    string p = get_string("plaintext: ");
    
    printf("ciphertext: ");
    
    for(int i = 0, len = strlen(p); i < len; i++)
    {
        if(islower(p[i]))
            printf("%c", (p[i] - 'a' + k) % 26 + 'a');
            
        else if (isupper(p[i]))
            printf("%c", (p[i] - 'A' + k) % 26 + 'A');
            
        else
            printf("%c", p[i]);
    }

    printf("\n");
}