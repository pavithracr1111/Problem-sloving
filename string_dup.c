#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str)
{
    int length = strlen(str);

    if (length < 2)
    {
        return; // If string is empty or has only one character
    }

    int index = 1; // To track the position of the next unique character

    for (int i = 1; i < length; i++)
    {
        int j;
        // Check if the character str[i] is already present in the unique part
        for (j = 0; j < index; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        // If not found, add str[i] to the unique part
        if (j == index)
        {
            str[index] = str[i];
            index++;
        }
    }

    // Null terminate the result
    str[index] = '\0';
}

int main()
{
    char str[150];
    scanf("%[^\n]", str);
    removeDuplicates(str);
    printf("%s\n", str);
}
