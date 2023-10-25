#include <stdio.h>
#include <math.h>

int main(){
    int a,b;
    scanf("%d %d\n", &a, &b);
    if (((a+b)%4 == 0) || ((a*b)%4 == 0))printf("Y\n");
    else printf("N\n");
    return 0;
}