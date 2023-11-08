#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
    //create empty list
    CreateEmpty(Odd);
    CreateEmpty(Even);
    //declare temp
    address P = First(L);
    address prec;
    address temp;
    //transverse list
    while(P != Nil){
        //check odd or even
        if(Info(P) % 2 == 0){
            temp = First(*Even);
            //check if list empty or first node is higher than current node
            if(temp == Nil || Info(temp) > Info(P)){
                InsVFirst(Even, Info(P));
            //else, find value higher than info(P)
            }else{
                while(Info(Next(temp)) <= Info(P) || Next(temp) != Nil){
                    temp = Next(temp);
                }
                InsertAfter(Even, Alokasi(Info(P)), prec);
            }
        }else{
            temp = First(*Odd);
            //check if list empty or first node is higher than current node
            if(temp == Nil || Info(temp) > Info(P)){
                InsVFirst(Odd, Info(P));
            //else, find value higher than info(P)
            }else{
                while(true){
                    //if next node is higher than info(P)
                    if(Info(Next(temp)) > Info(P) || Next(temp) == Nil){
                        //insert after temp
                        InsertAfter(Odd, Alokasi(Info(P)), temp);
                        break;
                    }
                    temp = Next(temp);
                }
            }
        }
        //move to next element
        P = Next(P);
    }
}

int main(){
    //declare list
    List L;
    List Odd;
    List Even;
    //create empty list
    CreateEmpty(&L);
    //insert L with random number
    InsVLast(&L, 0);
    InsVLast(&L, 5);
    InsVLast(&L, 1);
    InsVLast(&L, 4);
    InsVLast(&L, 5);
    InsVLast(&L, 2);
    InsVLast(&L, 4);
    InsVLast(&L, 7);
    //odd even list
    OddEvenList(L, &Odd, &Even);
    //print list
    PrintInfo(L);
    PrintInfo(Odd);
    PrintInfo(Even);
    return 0;
}