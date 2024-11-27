#include <stdio.h>
#include <string.h>

void reverse(char *str, int i, int len) // function to reverse the word
{
    while (i < len)
    {
        char temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
}
void reverse_word(char *str)
{
    int start = 0;
    int len = strlen(str); // length of the string
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ') // checking for a space
        {
            reverse(str, start, i - 1); // calling a function to revese the word
            start = i + 1;
        }
    }
    reverse(str, start, len - 1); // calling a function to revese the last word
}
int main()
{
    char str[50] = "hello world"; // string
    reverse_word(str);

    printf("%s", str);
}