#include <stdio.h>

int countDigits (int n){
    int count = 0;
    while (n!=0){
        count++;
        n /= 10;
    }
    return count;
}

int powerof (int val, int n){
    long long pow = 1;
    for (int i = 0; i < n; i++) {
        pow = pow * val;
    }
    return pow;
}

int nthDigit (int val, int n){
    return (val / (powerof(10, (n-1)))) % 10;
}

int main(){
    int minVal, maxVal;
    scanf("%d %d\n", &minVal, &maxVal);
    int i, j, calcVal;
    for(j=minVal; j<=maxVal; j++){
        calcVal=0;
        for(i=1; i<=countDigits(j); i++){
            calcVal += powerof(nthDigit(j, i), countDigits(j));
        }
        if (calcVal == j)printf("%d\n", j);
    }
    return 0;
}