#include "palindromeListLinier.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean isPalindromeList (List l){
    //create temp list
    List temp;
    CreateEmpty(&temp);
    //copy list l to temp
    //transverse l
    address P = First(l);
    while (P != Nil){
        //insert info(P) to temp
        InsVLast(&temp, Info(P));
        //move to next address
        P = Next(P);
    }
    //inverse temp
    InversList(&temp);
    //check palindrome, transverse l and temp
    P = First(l);
    address Q = First(temp);
    while (P!=Nil){
        //check if info(P) != info(temp)
        if (Info(P) != Info(Q)){
            //if not, return false
            return false;
        }
        //move to next address
        P = Next(P);
        Q = Next(Q);
    }
    return true;
}