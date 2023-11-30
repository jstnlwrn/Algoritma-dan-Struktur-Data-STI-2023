#include "RepeatElem.h"


List RepeatElem(List *L){
    List temp, Ans;
    temp = MakeList();
    Ans = MakeList();
    //check if L is empty
    if (IsEmpty(*L)){
        return Ans;
    }
    //traverse L    
    int i=0;
    for (i=FirstIdx(*L); i<=LastIdx(*L); i++){
        //check if get(L, i) is in temp
        if (Search(temp, Get(*L, i))){
            //check if get(L, i) is not in Ans
            if (!Search(Ans, Get(*L, i))){
                //add get(L, i) to Ans
                InsertLast(&Ans, Get(*L, i));
            }
            //delete get(L, i) from L
            DeleteAt(L, i);
            i--; //so it doesn't skip the next element
        } else {
            //check if get(L, i) is in temp
            if (!Search(temp, Get(*L, i))){
                //add get(L, i) to temp
                InsertLast(&temp, Get(*L, i));
            }
        }
    }
    return Ans;
}

// #include <stdio.h>
// void PrintInfo(List L){
//     int i;
//     for (i=FirstIdx(L); i<=LastIdx(L); i++){
//         printf("%d", Get(L, i));
//         if (i != LastIdx(L)) printf(" ");
//     }
//     printf("\n");
// }

// int main(){
//     List L, Ans;
//     L = MakeList();
//     Ans = MakeList();
//     //insert random to L
//     InsertLast(&L, 1);
//     InsertLast(&L, 4);
//     InsertLast(&L, 4);
//     InsertLast(&L, 4);
//     InsertLast(&L, 5);
//     InsertLast(&L, 6);
//     InsertLast(&L, 6);
//     InsertLast(&L, 8);
//     InsertLast(&L, 1);
//     InsertLast(&L, 10);
//     //print L
//     PrintInfo(L);
//     //repeat elem
//     Ans = RepeatElem(&L);
//     //print Ans
//     PrintInfo(Ans);
//     //print L
//     PrintInfo(L);
//     return 0;
// }
