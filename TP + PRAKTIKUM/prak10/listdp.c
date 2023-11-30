#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L){
    /* List kosong : First(L) = Nil dan Last(L) = Nil */
    return (First(L) == Nil && Last(L) == Nil);
}

void CreateEmpty (List *L){
    /* List kosong : First(L) = Nil dan Last(L) = Nil */
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi (infotype X){
    //alokasi node(ElmtList), put address in P
    address P = (address) malloc (sizeof(ElmtList));
    //check if allocation success
    if (P != Nil){
        //if success, put X in info(P)
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
}

void Dealokasi (address P){
    //free to deallocate memory
    free(P);
}

address Search (List L, infotype X){
    //store first address on the list
    address temp = First(L);
    //transverse list
    while (temp != Nil && Info(temp) != X){ //stops at Nil or address containing X
        temp = Next(temp);
    }
    return temp;
}

void InsVFirst (List *L, infotype X){
    //alocate X, put address in P
    address P = Alokasi(X);
    //check if allocation success
    if (P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X){
    //alocate X, put address in P
    address P = Alokasi(X);
    //check if allocation success
    if (P != Nil){
        InsertLast(L, P);
    }
}

void InsertFirst (List *L, address P){
    //check if list is empty
    if (IsEmpty(*L)){
        //if empty, insert P as first node
        First(*L) = P;
        Last(*L) = P;
    } else {
        //connect Prev(First(L)) to P
        Prev(First(*L)) = P;
        //connect Next(P) to first node
        Next(P) = First(*L);
        //connect First(L) to P
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
    //check if list is empty
    if (IsEmpty(*L)){
        //if empty, insert P as first node
        InsertFirst(L, P);
    } else {
        //connect Next(Last(L)) to P
        Next(Last(*L)) = P;
        //connect Prev(P) to last node
        Prev(P) = Last(*L);
        //connect Last(L) to P
        Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    //connect Next(P) to Next(Prec)
    Next(P) = Next(Prec);
    //connect Prev(P) to Prec
    Prev(P) = Prec;
    //connect Next(Prec) to P
    Next(Prec) = P;
    //check if P is last node
    if (Next(P) == Nil){
        //if yes, change Last(L) to P
        Last(*L) = P;
    } else {
        //if no, connect Prev(Next(P)) to P
        Prev(Next(P)) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
    //connect Prev(P) to Prev(Succ)
    Prev(P) = Prev(Succ);
    //connect Next(P) to Succ
    Next(P) = Succ;
    //connect Prev(Succ) to P
    Prev(Succ) = P;
    //check if P is first node
    if (Prev(P) == Nil){
        //if yes, change First(L) to P
        First(*L) = P;
    } else {
        //if no, connect Next(Prev(P)) to P
        Next(Prev(P)) = P;
    }
}

void DelVFirst (List *L, infotype *X){
    //use DelFirst() store it in P
    address P;
    DelFirst(L, &P);
    //put info(P) in X
    *X = Info(P);
    //deallocate memory
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
    //use DelLast() store it in P
    address P;
    DelLast(L, &P);
    //put info(P) in X
    *X = Info(P);
    //deallocate memory
    Dealokasi(P);
}

void DelFirst (List *L, address *P){
    //put first node's address in P
    *P = First(*L);
    //move First(*L) to next node
    First(*L) = Next(First(*L));
    //change 2nd node prev to Nil
    Prev(First(*L)) = Nil;
    //disconnect P from list
    Next(*P) = Nil;    
}

void DelLast (List *L, address *P){
    //check if list only has 1 node
    if (First(*L)==Last(*L)){
        //if yes, use DelFirst()
        DelFirst(L, P);
    } else {
        //put last node's address in P
        *P = Last(*L);
        //move Last(*L) to prev node
        Last(*L) = Prev(Last(*L));
        //change 2nd last node next to Nil
        Next(Last(*L)) = Nil;
        //disconnect P from list
        Prev(*P) = Nil;
    }
}

void DelP (List *L, infotype X){
    //search for address containing X
    address P = Search(*L, X);
    //check if P first element
    if (P == First(*L)){
        //if yes, use DelFirst()
        infotype temp;
        DelVFirst(L, &temp);
    } 
    //check if P last element
    else if (P == Last(*L)){
        //if yes, use DelLast()
        infotype temp;
        DelVLast(L, &temp);
    } 
    //else connect Next(Prev(P)) to Next(P) and Prev(Next(P)) to Prev(P)
    else {
        //connect Next(Prev(P)) to Next(P)
        Next(Prev(P)) = Next(P);
        //connect Prev(Next(P)) to Prev(P)
        Prev(Next(P)) = Prev(P);
        //deallocate memory
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    //put address after Prec in Pdel
    *Pdel = Next(Prec);
    //connect Next(Prec) to Next(Pdel)
    Next(Prec) = Next(*Pdel);
    //connect Prev(Next(Pdel)) to Prec
    Prev(Next(*Pdel)) = Prec;
    //disconnect Pdel from list
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
    //check if Prec is last node
    if (Next(Prec) == Nil){
        //if yes, change Last(L) to Prec
        Last(*L) = Prec;
    }
}

void DelBefore (List *L, address *Pdel, address Succ){
    //put address before Succ in Pdel
    *Pdel = Prev(Succ);
    //connect Prev(Succ) to Prev(Pdel)
    Prev(Succ) = Prev(*Pdel);
    //connect Next(Prev(Pdel)) to Succ
    Next(Prev(*Pdel)) = Succ;
    //disconnect Pdel from list
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
    //check if Succ is first node
    if (Prev(Succ) == Nil){
        //if yes, change First(L) to Succ
        First(*L) = Succ;
    }
}

void PrintForward (List L){
    //declare temp to store address
    address temp = First(L);
    //output
    printf("[");
    //check if list is empty
    if (temp != Nil){
        //if not empty, transverse list
        while (temp != Nil){
            //print info(temp)
            printf("%d\n", Info(temp));
            //check if next node is not Nil
            if (Next(temp) != Nil){
                //print ","
                printf(",");
            }
            //move to next node
            temp = Next(temp);
        }
    }
    //ouput
    printf("]\n");
}

void PrintBackward (List L){
    //declare temp to store address
    address temp = Last(L);
    //output
    printf("[");
    //check if list is empty
    if (temp != Nil){
        //if not empty, transverse list backward
        while (temp != Nil){
            //print info(temp)
            printf("%d\n", Info(temp));
            //check if prev node is not Nil
            if (Prev(temp) != Nil){
                //print ","
                printf(",");
            }
            //move to prev node
            temp = Prev(temp);
        }
    }
    //ouput
    printf("]\n");
}
