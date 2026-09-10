//Quicksort


#include <stdio.h>
#include <stdlib.h>

int count = 0;

int partition(int A[10], int l, int r)
{
    int i, j, pivot, temp;

    pivot = A[l];
    i = l + 1;
    j = r;

    while(1)
    {
        while(i <= r && A[i] <= pivot)
        {
            count++;
            i++;
        }

        while(j >= 1 && A[j] > pivot)
        {
            count++;
            j--;
        }

        if(i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else
        {
            temp = A[l];
            A[l] = A[j];
            A[j] = temp;

            return j;
        }
    }
}

void quicksort(int A[10], int l, int r)
{
    int s;

    if(l < r)
    {
        s = partition(A, l, r);

        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

int main()
{
    int A[10], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements : \n");

    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quicksort(A, 0, n - 1);

    printf("Sorted elements are:\n");

    for(i = 0; i < n; i++)
        printf("%d \t", A[i]);

    printf("\nTotal number of comparisons: %d\n", count);

    return 0;
}

