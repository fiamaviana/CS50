#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do 
    { 
        n = get_int("Height: ");
    
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        int s = (n - 1) - i;
        int h = i + 1;
        
        for (int j = 0; j < s; j++)
        {
            printf (" ");
        }
        for (int k = 0; k < h; k++)
        {
            printf("#");
        }
       
        printf("\n");
    }
}


