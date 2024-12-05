#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift, char *ciphertext);
void decrypt(char *ciphertext, int shift, char *decryptedtext);

void encrypt(char *plaintext, int shift, char *ciphertext)
{
    int i = 0;
    while (plaintext[i])
    {
        if (plaintext[i] == ' ' || isalpha(plaintext[i]))
        {
            if (plaintext[i] == ' ')
            {
                // Preserve spaces
                ciphertext[i] = plaintext[i];
            }
            else
            {
                // Encrypt the character with the shift
                ciphertext[i] = plaintext[i] + shift;
            }
            i++;
        }
    }
    // Add the null terminator to the ciphertext
    ciphertext[i] = '\0';

    printf("Encrypted message: %s\n", ciphertext);
}
void decrypt(char *ciphertext, int shift, char *decryptedtext)
{
    int i = 0;
    while (ciphertext[i])
    {
        if (ciphertext[i] == ' ')
        {
            // Preserve spaces
            decryptedtext[i] = ciphertext[i];
        }
        else
        {
            // Encrypt the character with the shift
            decryptedtext[i] = ciphertext[i] - shift;
        }
        i++;
    }
    // Add the null terminator to the ciphertext
    decryptedtext[i] = '\0';

    printf("Decrypted message: %s\n", decryptedtext);
}

int main()
{
    int shift;
    printf("Enter shift value:");
    scanf("%d", &shift);

    if (shift >= 1 && shift <= 25)
    {
        char plaintext[100];
        char ciphertext[100];
        char decryptedtext[100];
        printf("Enter the plaintext message:");
        __fpurge(stdin);
        scanf("%[^\n]", plaintext);

        encrypt(plaintext, shift, ciphertext);
        decrypt(ciphertext, shift, decryptedtext);
    }
    else
    {
        printf("Enter the shifts in the range of (1 - 25)\n");
    }
}