#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the 5-point weighted moving average
void weightedMovingAverage(int *arr, int n)
{
    if (n < 5)
    {
        printf("Not enough elements for a 5-point window\n");
        return;
    }

    int weights[] = {1, 2, 3, 2, 1};
    int weightSum = 1 + 2 + 3 + 2 + 1;

    printf("Weighted Moving Averages: ");
    for (int i = 2; i < n - 2; i++)
    {
        int sum = 0;
        for (int j = -2; j <= 2; j++)
        {
            sum += arr[i + j] * weights[j + 2];
        }
        printf("%d ", sum / weightSum);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of random numbers (n): ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    printf("Random Numbers: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1; // Generate random numbers between 1 and 100
        printf("%d ", arr[i]);
    }
    printf("\n");

    weightedMovingAverage(arr, n);

    return 0;
}
