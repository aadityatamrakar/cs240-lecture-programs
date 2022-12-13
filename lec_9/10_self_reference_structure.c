#include <stdio.h>

struct user
{
    char name[30];
    struct user *friend;
};

int main()
{
    struct user u1 = {"A", NULL};
    struct user u2 = {"B", NULL};
    
    u1.friend = &u2;
    u2.friend = &u1;

    printf("Name: %s\n", u1.name);
    printf("Friend: %s\n", u1.friend->name);
    
    printf("Name: %s\n", u2.name);
    printf("Friend: %s\n", u2.friend->name);

    return 0;
}