#include "panjangstring.h"

int panjangString(char *x)
{
    int count = 0;
    while (*x != '\0')
    {
        count += 1;
        x += 1;
    }
    return count;
}