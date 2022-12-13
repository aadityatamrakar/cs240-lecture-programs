// https://www.programiz.com/c-programming/c-preprocessor-macros

#include <stdio.h>

// A macro is a fragment of code that is given a name. You can define a macro in C using the #define preprocessor directive.
#define PI 3.1415
#define circleArea(r) (PI * r * r)

int main()
{
    float radius, area;

    printf("Enter the radius: ");
    scanf("%f", &radius);
    area = circleArea(radius);
    printf("Area = %.2f\n", area);

    return 0;
}