#include <stdio.h>
#include "mesinkarakter.h"
#include "boolean.h"

boolean isVocal;

int main(){

    int count=0;
    char ban;
    scanf("%c\n", &ban);

    START();
    while (!IsEOP()) {
        isVocal = ( (GetCC() == 'a' || GetCC() == 'A') || (GetCC() == 'i' || GetCC() == 'I') || (GetCC() == 'u' || GetCC() == 'U') || (GetCC() == 'e' || GetCC() == 'E') || (GetCC() == 'o' || GetCC() == 'O') );
        if (isVocal && GetCC() != ban){
            printf("%c", GetCC());
            count++;
        }
        ADV();
    }
    if (count > 0) printf(" ");
    printf("%d\n", count);
    return 0;
}
