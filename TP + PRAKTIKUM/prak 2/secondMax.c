#include <stdio.h>

int main()
{
    int n, max, secondMax, num;

    scanf("%d", &n);
    scanf("%d", &max);
    secondMax = max;

    int i;
    for(i = 2; i <= n; i++)
    {
        scanf("%d", &num);

        if(num > max)
        {
            secondMax = max;
            max = num;
        }
        else if(num > secondMax && num != max || secondMax == max)
        {
            secondMax = num;
        }
    }

    printf("%d\n", secondMax);

    return 0;
}