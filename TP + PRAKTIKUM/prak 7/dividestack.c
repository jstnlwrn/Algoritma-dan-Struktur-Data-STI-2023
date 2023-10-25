#include "dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    Stack temp;
    CreateEmpty(&temp);
    infotype val;
    //reverse stack
    while(!IsEmpty(*s)){
        Pop(s, &val);
        Push(&temp, val);
    }
    //check odd or even
    while(!IsEmpty(temp)){
        Pop(&temp, &val);
        if(val % 2 == 0){
            Push(evenS, val);
        }else{
            Push(oddS, val);
        }
    }
}