#include <stdio.h>
#include <limits.h>

int max = INT_MIN;
int min = INT_MAX;

void scanArr(int arr[], int n)
{
    // get array elements from the user
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element: %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void findMinAndMax(int arr[], int low, int high)
{
    // if the array contains only one element

    if (low == high) // common comparison
    {
        if (max < arr[low])
        { // comparison 1
            max = arr[low];
        }

        if (min > arr[high])
        { // comparison 2
            min = arr[high];
        }

        return;
    }

    // if the array contains only two elements

    if (high - low == 1) // common comparison
    {
        if (arr[low] < arr[high]) // comparison 1
        {
            if (min > arr[low])
            { // comparison 2
                min = arr[low];
            }

            if (max < arr[high])
            { // comparison 3
                max = arr[high];
            }
        }
        else
        {
            if (min > arr[high])
            { // comparison 2
                min = arr[high];
            }

            if (max < arr[low])
            { // comparison 3
                max = arr[low];
            }
        }
        return;
    }

    // find the middle element
    int mid = (low + high) / 2;

    // recursively do the same for the left subarray
    findMinAndMax(arr, low, mid);

    // recursively do the same for the right subarray
    findMinAndMax(arr, mid + 1, high);
}

int main()
{
    int n;
    int arr[100];
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    scanArr(arr, n);
    findMinAndMax(arr, 0, n - 1);
    printf("\nMaximum = %d\nMinimum = %d\n", max, min);
    return 0;
}
