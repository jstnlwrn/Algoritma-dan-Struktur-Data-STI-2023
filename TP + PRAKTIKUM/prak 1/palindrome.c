#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int n) {
    int reversed = 0, remainder, original = n;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    int count = 0, N;
    scanf("%d\n", &N);
    for (int i = 2; ; i++) {
        if (isPrime(i) && isPalindrome(i)) {
            count++;
            if (count == N){
                printf("%d\n", i);
                break;
            } 
        }
    }
    return 0;
}