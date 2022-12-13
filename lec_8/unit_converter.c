/**
 * Project: Unit Converter
 * Name   : Aaditya Tamrakar
 * Date   : 09/29/2022
 * File   : unit_converter.c
 * Notes  : simple unit converter
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double convert_units(double input, char *from_unit, char *to_unit)
{
    if (strcmp(from_unit, to_unit) == 0)
        return input;
    else if (strcmp(from_unit, "miles") == 0 && strcmp(to_unit, "kilometers") == 0)
        input *= 1.60934;
    else if (strcmp(from_unit, "kilometers") == 0 && strcmp(to_unit, "miles") == 0)
        input /= 1.60934;
    else if (strcmp(from_unit, "f") == 0 && strcmp(to_unit, "c") == 0)
        input = (input - 32) * 5 / 9;
    else if (strcmp(from_unit, "c") == 0 && strcmp(to_unit, "f") == 0)
        input = input * 9 / 5 + 32;
    else if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "kg") == 0)
        input *= 0.453592;
    else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "lb") == 0)
        input /= 0.453592;
    else
        return -1;

    return input;
}

int main()
{
    int MAX = 50;
    char line[MAX];
    printf("Enter the value and units to convert from and to: ");
    // example command: 
    // 10 km to mi
    // 70 f to c
    // 20 c to f
    fgets(line, MAX, stdin);
    char *input = strtok(line, " ");
    char *from_unit = strtok(NULL, " ");
    char *to = strtok(NULL, " ");
    char *to_unit = strtok(NULL, " ");

    printf("%s %s %s %s\n", input, from_unit, to, to_unit);

    // remove the newline character from the end of the string
    to_unit[strlen(to_unit) - 1] = '\0';

    // convert the input to double
    // atof - Parses the C string str, interpreting its content as a
    //        floating point number and returns its value as a double.
    double input_d = atof(input);

    // convert the units
    double result = convert_units(input_d, from_unit, to_unit);

    // print the result
    if (result == -1)
        printf("Invalid input\n");
    else
        printf("%.2f %s = %.2f %s\n", input_d, from_unit, result, to_unit);

    return 0;
}
