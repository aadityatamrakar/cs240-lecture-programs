#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct assignments
{
    char name[30];
    int marks_obtained;
    int total_marks;
    int weightage;
};

void print_grade(float weighted_average);

int main()
{
    struct assignments *pointer;
    int total_assignments = 10;

    // Taking each student detail as input
    // and Memory allocation for noOfRecords structures
    // pointer = (struct assignments *)malloc(total_assignments * sizeof(struct assignments));
    // for (int i = 0; i < total_assignments; ++i)
    // {
    //     printf("Enter the name of the assignment: ");
    //     scanf("%s", (pointer + i)->name);
    //     printf("Enter the marks obtained: ");
    //     scanf("%d", &(pointer + i)->marks_obtained);
    //     printf("Enter the total marks: ");
    //     scanf("%d", &(pointer + i)->total_marks);
    //     printf("Enter the weightage: ");
    //     scanf("%d", &(pointer + i)->weightage);
    // }

    // manually assigning values
    struct assignments assignments[10] = {
        // {"name", marks_obtained, total_marks, weightage}
        {"Quiz 1", 9, 10, 5},
        {"Quiz 2", 8, 10, 5},
        {"Quiz 3", 7, 10, 5},
        {"HW 01", 45, 55, 10},
        {"HW 02", 45, 55, 10},
        {"HW 03", 45, 55, 10},
        {"HW 04", 45, 55, 10},
        {"HW 05", 45, 55, 10},
        {"HW 06", 45, 55, 10},
        {"Final Exam", 25, 30, 25},
    };
    pointer = assignments;

    int verify_weightage = 0;

    // calculate the weighted average
    // weighted_average = (marks_obtained / total_marks) * weightage
    float weighted_average = 0;
    for (int i = 0; i < total_assignments; ++i)
    {
        weighted_average += ((float)(pointer + i)->marks_obtained / (pointer + i)->total_marks) * (pointer + i)->weightage;

        verify_weightage += (pointer + i)->weightage;
    }

    if (verify_weightage)
    {
        printf("Weightage is not 100%%\n");
        exit(1);
    }

    printf("The weighted average is: %.2f%%\n", weighted_average);
    print_grade(weighted_average);

    return 0;
}

void print_grade(float weighted_average)
{
    if (weighted_average >= 90)
        printf("Grade: A\n");
    else if (weighted_average >= 87)
        printf("Grade: A-\n");
    else if (weighted_average >= 83)
        printf("Grade: B+\n");
    else if (weighted_average >= 80)
        printf("Grade: B\n");
    else if (weighted_average >= 77)
        printf("Grade: B-\n");
    else if (weighted_average >= 70)
        printf("Grade: C\n");
    else
        printf("Grade: F\n");
}