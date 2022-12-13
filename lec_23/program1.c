// https://www.includehelp.com/c-programs/c-pointer-program-to-create-initialize-assign-and-access-a-pointer-variable.aspx
/*C program to create, initialize, assign and access a pointer variable.*/

#include <stdio.h>

int main()
{
    int num;   /*declaration of integer variable*/
    int *pNum; /*declaration of integer pointer*/

    pNum = &num; /*assigning address of num*/
    num = 100;   /*assigning 100 to variable num*/

    // access value and address using variable num
    printf("Using variable num:\n");
    printf("value of num: %d\naddress of num: %p\n", num, &num);
    // access value and address using pointer variable num
    printf("Using pointer variable:\n");
    printf("value of num: %d\naddress of num: %p\n", *pNum, pNum);

    return 0;
}