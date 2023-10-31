#include<stdio.h>
#include"boolean.h"
#include"mesinkarakter.h"
#include"mesinkata.h"

boolean endWord;
Word currentWord;

int main(){
    STARTWORD();
    int count = 0, i;
    for (i = 0; i<= currentWord.Length - 1; i++){
        count++;
    }
    while(!endWord)ADVWORD();
    for (i = 0; i<= currentWord.Length - 1; i++){
        count++;
    }    
    printf("%d\n", count);
    return 0;
}