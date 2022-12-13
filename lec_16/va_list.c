// https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm

// Sometimes, you may come across a situation, when you want to have a function, which can take variable number of arguments, i.e., parameters, instead of predefined number of parameters. The C programming language provides a solution for this situation and you are allowed to define a function which can accept variable number of parameters based on your requirement. The following example shows the definition of such a function.

#include <stdio.h>
#include <stdarg.h>

// It should be noted that the function func() has its last argument as ellipses, i.e. three dotes (...) and the one just before the ellipses is always an int which will represent the total number variable arguments passed. To use such functionality, you need to make use of stdarg.h header file which provides the functions and macros to implement the functionality of variable arguments and follow the given steps −
//  1. Define a function with its last parameter as ellipses and the one just before the ellipses is always an int which will represent the number of arguments.
//  2. Create a va_list type variable in the function definition. This type is defined in stdarg.h header file.
//  3. Use int parameter and va_start macro to initialize the va_list variable to an argument list. The macro va_start is defined in stdarg.h header file.
//  4. Use va_arg macro and va_list variable to access each item in argument list.
//  5. Use a macro va_end to clean up the memory assigned to va_list variable.
double average(int num, ...)
{

    va_list valist;
    double sum = 0.0;
    
    /* initialize valist for num number of arguments */
    va_start(valist, num);

    /* access all the arguments assigned to valist */
    for (int i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }

    /* clean memory reserved for valist */
    va_end(valist);

    return sum / num;
}

int main()
{
    printf("Average of 2, 3, 4, 5 = %.1f\n", average(4, 2, 3, 4, 5));
    printf("Average of 10, 10, 10, 10, 10 = %.1f\n", average(5, 10, 10, 10, 10, 10));
}