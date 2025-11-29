#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp;

    printf("Enter the number of applicants: ");
    scanf("%d", &n);

    int age[n];

    // Input ages
    for(i = 0; i < n; i++) {
        printf("Enter age of applicant %d: ", i + 1);
        scanf("%d", &age[i]);
    }

    // Bubble Sort in ascending order
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(age[j] > age[j + 1]) {
                temp = age[j];
                age[j] = age[j + 1];
                age[j + 1] = temp;
            }
        }
    }

    // Display sorted ages
    printf("\nAges in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", age[i]);
    }
    printf("\n");

    system("pause"); // Pause before closing
    return 0;
}
