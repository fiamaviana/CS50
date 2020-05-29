#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 2 && isdigit(*argv[1]))
    {
        int k = atoi(argv[1]);
        
        string p = get_string("plaintext: ");
        printf("ciphertext: ");
    
        for(int i = 0, n = strlen(p); i < n; i++)
        {
        if (p[i] >= 'a' && p[i] <= 'z')
            printf("%c", (((p[i] - 'a') + k) % 26) + 'a');
            
        else if (p[i] >= 'A' && p[i] <= 'Z')
            printf("%c", (((p[i] - 'A') + k) % 26) + 'A');
        
        else
            printf("%c", p[i]);
    }

        printf("\n");
        return 0;
    
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}