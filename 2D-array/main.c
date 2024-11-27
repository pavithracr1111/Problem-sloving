/* Take a 2D array int a[m][n], write a function to replace each element of the array with the 5th prime number
starting from the corresponding array element. */

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num)
{
    if (num <= 1)
        return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0; // Not a prime number
    }
    return 1; // Prime number
}

// Function to find the 5th prime number starting from a given number
int findfithPrime(int num)
{
    int count = 0;
    while (1)
    {
        if (isPrime(num))
        {
            count++;
            if (count == 5)
                return num;
        }
        num++;
    }
}

// Function to replace each element in the 2D array with the 5th prime number
void replaceWithfithPrime(int rows, int cols, int array[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = findfithPrime(array[i][j]); // Replace with 5th prime
        }
    }
}

// Function to print the 2D array
void printArray(int rows, int cols, int array[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Example dimensions and initialization of the 2D array
    int rows, cols;
    printf("Enter the rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int array[rows][cols];

    // Input the array elements
    printf("Enter elements of the array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Original array:\n");
    printArray(rows, cols, array);

    // Replace each element with the 5th prime number
    replaceWithfithPrime(rows, cols, array);

    printf("\nModified array:\n");
    printArray(rows, cols, array);

    return 0;
}
