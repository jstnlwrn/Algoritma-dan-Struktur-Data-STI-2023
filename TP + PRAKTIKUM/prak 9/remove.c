#include "remove.h"

void RemoveDuplicates (List*L){
    //declare temp list
    List temp;
    //create empty list
    CreateEmpty(&temp);
    //transverse L
    address P = First(*L);
    address Prec;
    address trash;
    while (P != Nil){
        //check if info(P) is not in temp
        if (Search(temp, Info(P)) == Nil){
            //if not, insert info(P) to temp
            InsVLast(&temp, Info(P));
            //move to next node
            Prec = P;
            P = Next(P);            
        }
        //if yes, delete P
        else{
            DelAfter(L, &trash, Prec);
            Dealokasi(&trash);
            //move to next node
            P = Next(Prec);
        }
    }
}