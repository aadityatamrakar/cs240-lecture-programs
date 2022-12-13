#include<stdio.h>
#include<ctype.h>

int main()
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    char c_lower = tolower(c);
    char c_upper = toupper(c);
    
    printf("Lower case: %c\n", c_lower);
    printf("Upper case: %c\n", c_upper);
    
    if(isalpha(c))
        printf("The character is an alphabet\n");
    if(isdigit(c))
        printf("The character is a digit\n");
    if(islower(c))
        printf("The character is a lowercase letter\n");
    if(isupper(c))
        printf("The character is an uppercase letter\n");
    if(ispunct(c))
        printf("The character is a punctuation mark\n");
    if(isspace(c))
        printf("The character is a whitespace character\n");
    if(isxdigit(c))
        printf("The character is a hexadecimal digit\n");
    if(isalnum(c))
        printf("The character is an alphanumeric character\n");
    if(isprint(c))
        printf("The character is a printable character\n");
    
    return 0;   
}
