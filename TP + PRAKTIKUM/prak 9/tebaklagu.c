#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

int main(){
    //create list
    List L;
    CreateEmpty(&L);
    //ask for input
    int X;
    while(true){
        scanf("%d", &X);
        //check if mark
        if (X==-99) break;
        //ins to list
        InsVLast(&L, X);
    }
    //number of songs in list
    int n = NbElmt(L);
    //create new list in case of duplicate guess
    List dupe;
    CreateEmpty(&dupe);
    //ask for guess
    while(IsEmpty(L)==false){
        scanf("%d", &X);
        //check if duplicate
        if (Search(dupe, X)==Nil){
            //check if correct
            if (Search(L, X)!=Nil){
                //ins to dupe
                InsVLast(&dupe, X);
                //delete from list
                DelP(&L, X);
            }
            //if false
            else{
                printf("Poser! %d tidak ada di dalam album\n", X);
                break;
            }
        }
    }
    //if all guessed, List should be empty
    if (IsEmpty(L)==true){
        printf("Berhasil menebak %d lagu\n", n);
    }
    return 0;
}