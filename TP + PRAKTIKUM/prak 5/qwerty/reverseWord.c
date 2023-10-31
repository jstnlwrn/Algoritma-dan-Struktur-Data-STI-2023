#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

boolean isQwerty(char currentChar){
    return (currentChar == 'q' || currentChar == 'Q'
    || currentChar == 'w'|| currentChar == 'W'
    || currentChar == 'e'|| currentChar == 'E'
    || currentChar == 'r'|| currentChar == 'R'
    || currentChar == 't'|| currentChar == 'T'
    || currentChar == 'y'|| currentChar == 'Y');
}

void reverse(Word *kata){
    Word temp;
    int i;
    if (kata->Length > 1) {
        //reverse kata to temp
        for(i = 0; i < kata->Length; i++){
            temp.TabWord[i] = kata->TabWord[kata->Length - i - 1];
        }
        temp.Length = kata->Length;
        //copy temp to kata
        for(i = 0; i < kata->Length; i++){
            kata->TabWord[i] = temp.TabWord[i];
        }
    }
}

void printWord(Word kata, char currentChar){
    int i;
    for(i = 0; i < kata.Length; i++){
        printf("%c", kata.TabWord[i]);
    }
    if (currentChar == MARK){
        printf("%c", MARK);  
        printf("\n");
    } 
    else printf(" ");
}

int main(){
    STARTWORD();
    Word temp;
    int i;
    while (true){
        //reset temp
        temp.Length = 0;
        //copy currentWord to temp
        for(i=0; i<currentWord.Length; i++){
            //reverse if qwerty
            if (isQwerty(currentWord.TabWord[i])){
                reverse(&temp);
                //insert tabword to temp
                temp.TabWord[temp.Length] = currentWord.TabWord[i];
                temp.Length++;
            }
            //else insert tabword to temp
            else{
                temp.TabWord[temp.Length] = currentWord.TabWord[i];
                temp.Length++;
            }
        }
        //print temp
        printWord(temp, currentChar);

        //if currentChar == MARK, break
        if (currentChar == MARK) break;
        //get next word
        ADVWORD();
    }
    return 0; //dont forget to return 0. i fuckin waste my time because of this.
}