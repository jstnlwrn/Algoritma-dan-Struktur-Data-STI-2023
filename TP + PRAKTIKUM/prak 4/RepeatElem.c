#include "RepeatElem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List RepeatElem(List *L){
    List temp, Ans;
    temp = MakeList();
    Ans = MakeList();
    int i=0;
    for (i=FirstIdx(*L); i<=LastIdx(*L); i++){
        // check if L.A[i] is in temp
        if (Search(temp, Get(*L, i))){
            // check if L.A[i] not in Ans
            if(!Search(Ans, Get(*L, i))){
                // insert L.A[i] to Ans
                InsertLast(&Ans, Get(*L, i));
            }
            // delete from L
            DeleteAt(L, i);
        } else {
            // insert L to temp
            if(!Search(temp, Get(*L, i)))InsertLast(&temp, Get(*L, i));
        }
    }
    return Ans;
}
