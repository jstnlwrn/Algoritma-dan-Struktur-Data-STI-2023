#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
    //create empty list
    CreateEmpty(Odd);
    CreateEmpty(Even);
    //declare temp
    address P = First(L);
    address temp;
    //transverse list
    while(P != Nil){
        //check odd
        if(Info(P) % 2 == 1){
            temp = First(*Odd);
            //check if list is empty
            if(temp == Nil || Info(P) < Info(temp)){
                //insert to first
                InsVFirst(Odd, Info(P));
            }
            else{
                //find info(next(temp)) > info(P)
                while(Next(temp) != Nil && Info(Next(temp)) < Info(P)){
                    temp = Next(temp);
                }
                //insert after temp
                InsertAfter(Odd, Alokasi(Info(P)), temp);
            }
        }else{
            temp = First(*Even);
            //check if list is empty
            if(temp == Nil || Info(P) < Info(temp)){
                //insert to first
                InsVFirst(Even, Info(P));
            }
            else{
                //find info(next(temp)) > info(P)
                while(Next(temp) != Nil && Info(Next(temp)) < Info(P)){
                    temp = Next(temp);
                }
                //insert after temp
                InsertAfter(Even, Alokasi(Info(P)), temp);
            }
        }
        //move to next element
        P = Next(P);
    }
}

// int main(){
//     //declare list
//     List L;
//     List Odd;
//     List Even;
//     //create empty list
//     CreateEmpty(&L);
//     //insert L with random number
//     InsVLast(&L, 0);
//     InsVLast(&L, 5);
//     InsVLast(&L, 1);
//     InsVLast(&L, 4);
//     InsVLast(&L, 5);
//     InsVLast(&L, 2);
//     InsVLast(&L, 4);
//     InsVLast(&L, 7);
//     //odd even list
//     OddEvenList(L, &Odd, &Even);
//     //print list
//     PrintInfo(L);
//     PrintInfo(Odd);
//     PrintInfo(Even);
//     return 0;
// }