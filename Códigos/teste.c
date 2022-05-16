#include <stdio.h>

int main()
{
    char *s = "Turing";
    char *p = s + 5;
    printf("%c\t%c", *p, s[1]);
}
