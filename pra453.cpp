#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Enter the number of students in your class: ");
    scanf("%d", &n);

    float cgpa[n];  // Array to store CGPA of students

    // Input CGPA
    for(i = 0; i < n; i++) {
        printf("Enter CGPA of student %d: ", i + 1);
        scanf("%f", &cgpa[i]);
    }

    // Display CGPA
    printf("\nCGPA of students:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %.2f\n", i + 1, cgpa[i]);
    }

    system("pause");  // Pause before closing
    return 0;
}
