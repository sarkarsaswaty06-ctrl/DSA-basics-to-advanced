
#include <stdio.h>

int main() {
    // a) Declare an array of 10 integers
    int arr[10];
    int i, sum = 0;
    float average;

    // b) Accept 10 integer values from the user
    printf("Enter 10 integer values:\n");

    for (i = 0; i < 10; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // c) Display all the elements of the array
    printf("\nElements of the array are:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // d) Calculate the sum of all elements
    for (i = 0; i < 10; i++) {
        sum = sum + arr[i];
    }

    printf("\n\nSum of all elements = %d", sum);

    // e) Calculate and display the average
    average = (float)sum / 10;

    printf("\nAverage of array elements = %.2f\n", average);

    return 0;
}

