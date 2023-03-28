#include <stdio.h>

extern int func();

int main()
{
    printf("%d\n", func());
    return func();
}