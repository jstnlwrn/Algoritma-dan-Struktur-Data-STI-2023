#include <stdio.h>

int main (){
    int a, b, c, max;
    scanf("%d %d %d\n", &a, &b, &c);
    if (a >= b && a>= c)max = a;
    if (b >= a && b>= c)max = b;
    if (c >= b && c>= a)max = c; 
    printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n", a, b, c, max);
    return 0;
}