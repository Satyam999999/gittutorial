#include <stdio.h>
int main()
{
    int n = 6;
    char a[n];
    int count = 0;
    // option 1
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &a[i]);
    }
    //option 2
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u')
        {
            count++;
        }
    }
    printf("NUMBER OF CONSONANTS ARE %d",count);
}