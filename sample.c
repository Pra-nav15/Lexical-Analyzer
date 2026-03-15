#include <stdio.h>
void print(void);
void print(void)
{
    int n, i;
    float marks[100], sum = 0, avg;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        printf("Enter marks of student %d: ", i+1);
        scanf("%f", &marks[i]);
        sum = sum + marks[i];
    }

    avg = sum / n;

    printf("Average Marks = %.2f\n", avg);

    if(avg >= 50)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }
}