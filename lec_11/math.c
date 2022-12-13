#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);

    double x_ceil = ceil(x);   // round up
    double x_floor = floor(x); // round down
    double x_round = round(x); // round to nearest integer
    double x_abs = fabs(x);    // absolute value
    double x_sqrt = sqrt(x);   // square root
    double x_cbrt = cbrt(x);   // cube root
    double x_exp = exp(x);     // e^x
    double x_log = log(x);     // natural log
    double x_log10 = log10(x); // log base 10
    double x_sin = sin(x);     // sine
    double x_cos = cos(x);     // cosine
    double x_tan = tan(x);     // tangent

    printf("Ceil: %lf\n", x_ceil);
    printf("Floor: %lf\n", x_floor);
    printf("Square root: %lf\n", x_sqrt);
    printf("Cube root: %lf\n", x_cbrt);
    printf("Exponential: %lf\n", x_exp);
    printf("Natural log: %lf\n", x_log);
    printf("Base 10 log: %lf\n", x_log10);
    printf("Sine: %lf\n", x_sin);
    printf("Cosine: %lf\n", x_cos);
    printf("Tangent: %lf\n", x_tan);

    return 0;
}