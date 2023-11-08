#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
    //create empty list
    CreateEmpty(Odd);
    CreateEmpty(Even);
    //declare temp
    address P = First(L);
    address prec;
    address Oddtemp = First(*Odd);
    address Eventemp = First(*Even);
    //transverse L
    while (P != Nil){
        //check if info(P) is odd
        if (Info(P) % 2 == 1){
            //check if Odd is empty
            if (Oddtemp == Nil){
                //if yes, insert info(P) to Odd
                InsVFirst(Odd, Info(P));
            }
            else{
                //transverse Odd, find higher value than info(P) or Nil
                while (Oddtemp != Nil && Info(Oddtemp) < Info(P)){
                    prec = Oddtemp;
                    Oddtemp = Next(Oddtemp);
                }
                //insert info(P) to Odd
                InsertAfter(Odd, Alokasi(Info(P)), prec); 
            }
            //move to next node
            P = Next(P);
        }
        //if no, insert info(P) to Even
        else{
            //check if Even is empty
            if (Eventemp == Nil){
                //if yes, insert info(P) to Even
                InsVFirst(Even, Info(P));
            }
            else{
                //transverse Even, find higher value than info(P) or Nil
                while (Eventemp != Nil && Info(Eventemp) < Info(P)){
                    prec = Eventemp;
                    Eventemp = Next(Eventemp);
                }
                //insert info(P) to Even
                InsertAfter(Even, Alokasi(Info(P)), prec);   
            }
            //move to next node
            P = Next(P);
        }
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