#include "swap.h"

address AddressAtIndex(List L, infotype X){
    address P = First(L);
    int i;
    for(i=0; i<X-1; i++){
        P = Next(P);
    }
    return P;
}

void Swap(List *L1){
    //input
    infotype Elmt1, Elmt2;
    address P1, P2;
    scanf("%d %d", &Elmt1, &Elmt2);
    //check jika swap node yang sama
    if (Elmt1 == Elmt2) return;
    //get address
    P1 = AddressAtIndex(*L1, Elmt1);
    P2 = AddressAtIndex(*L1, Elmt2);
    //swap
    address temp;
    //check bersebelahan
    if (Next(P1) == P2 || Next(P2) == P1){
        //bersebelahan
        if (Next(P1) == P2){
            Next(Prev(P1)) = P2;
            Prev(Next(P2)) = P1;
            Next(P1) = Next(P2);
            Prev(P2) = Prev(P1);
            Next(P2) = P1;
            Prev(P1) = P2;
        }else{
            Next(Prev(P2)) = P1;
            Prev(Next(P1)) = P2;
            Next(P2) = Next(P1);
            Prev(P1) = Prev(P2);
            Next(P1) = P2;
            Prev(P2) = P1;
        }
    }else{
        //tidak bersebelahan
        Next(Prev(P1)) = P2;
        Next(Prev(P2)) = P1;
        Prev(Next(P1)) = P2;
        Prev(Next(P2)) = P1;
        temp = Next(P1);
        Next(P1) = Next(P2);
        Next(P2) = temp;
        temp = Prev(P1);
        Prev(P1) = Prev(P2);
        Prev(P2) = temp;
    }
}

// int main(){
//     return 0;
// }