#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n<1 || n>50){
        printf("%d\n", -1);
    }
    else{
        long long i, currentInt, previousInt1=1, previousInt2=1, sum=0;
        for(i=3; i<=n; i++){
            currentInt = previousInt1 + previousInt2;
            previousInt2 = previousInt1;
            previousInt1 = currentInt;
            if(i%3 == 0){
                sum += currentInt;
            }
        }
        printf("%d\n", sum);
    }
    
    return 0;
}