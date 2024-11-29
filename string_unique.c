#include <stdio.h>
#include <string.h>

// Function to check if a string has all unique characters
int fun_to_find_UniqueCharacters(char *str)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
            {
                return 0; // Duplicate character found
            }
        }
    }
    return 1; // All characters are unique
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (fun_to_find_UniqueCharacters(str))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
