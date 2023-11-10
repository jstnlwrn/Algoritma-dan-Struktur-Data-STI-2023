#include "twoSum.h"
#include <stdlib.h>

int twoSum(List L1, List L2){
    //declare var to store total value
    int val1=0, val2=0;
    //declare X to store temp val
    int X;
    //count for digit
    int count;
    //transverse L1
    address P = First(L1);
    count = 0;
    int i;
    while (P!=Nil){
        //get val
        DelVFirst(&L1, &X);
        //x10 agar sesuai digit
        for(i=0; i<count; i++){
            X = X*10;
        }
        //insert to total value
        val1 += X;
        //add count
        count++;
        P=Next(P);
    }
    //transverse L2
    P = First(L2);
    count = 0;
    while (P!=Nil){
        //get val
        DelVFirst(&L2, &X);
        //x10 agar sesuai digit
        for(i=0; i<count; i++){
            X = X*10;
        }
        //insert to total value
        val2 += X;
        //add count
        count++;
        P=Next(P);
    }
    return (val1+val2);    
}