#include <stdio.h>

#define Max 10

int main(int argc, char *argv[])
{
    int i, j, target, arr[Max], n, found = 0;

    // Input the size of the array
    printf("Enter size: ");
    scanf("%d", &n);

    // Check if the size is within valid limits
    if (n > Max || n <= 0) {
        printf("Invalid size. Size must be between 1 and %d.\n", Max);
        return 1;
    }

    // Input the elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Input the target value
    printf("Enter target value: ");
    scanf("%d", &target);

    // Find two indices whose values sum up to target
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) == target) {
                printf("Indices %d and %d have values %d and %d which sum up to %d\n", i, j, arr[i], arr[j], target);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    // If no such indices are found
    if (!found) {
        printf("No two indices found with the given sum.\n");
    }

    return 0;
}
