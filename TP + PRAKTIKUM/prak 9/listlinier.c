#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    //alocate node(ElmtList), put address in P
    address P = (address) malloc (sizeof(ElmtList));
    //check if allocation success
    if (P != Nil){
        //if success, put X in info(P)
        Info(P) = X;
        Next(P) = Nil;
    }
    //return address of P
    return P;
}

void Dealokasi (address *P){
    //free to deallocate memory
    free(*P);
}

address Search (List L, infotype X){
    //declare temp to store address
    address temp = First(L);
    //transverse to find X
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

void DelVFirst (List *L, infotype *X){
    //can use DelFirst() but will cause 1 extra step
    //declare temp to store address
    address temp = First(*L);
    //check if list is empty
    if (temp != Nil){
        //if not empty, put info(temp) in X
        *X = Info(temp);
        //connect First(L) to Next(temp)
        First(*L) = Next(temp);
        //deallocate memory
        Dealokasi(&temp);
    }
}

void DelVLast (List *L, infotype *X){
    //declare P to store last node's address
    address P;
    //disconnect last node from list and put address in P
    DelLast(L, &P);
    //put last node's info() in X
    *X = Info(P);
    //deallocate last node's memory
    Dealokasi(&P);
    
}

void InsertFirst (List *L, address P){
    //connect Next(P) to first node
    Next(P) = First(*L);
    //connect First(L) to P
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
    //connect Next(P) to Next(Prec)
    Next(P) = Next(Prec);
    //connect Next(Prec) to P
    Next(Prec) = P;
}

void InsertLast(List *L, address P){
    //declare temp to store address
    address temp = First(*L);
    //check if list is empty
    if (temp == Nil){
        //if empty, connect First(L) to P
        First(*L) = P;
        //Next(P) already Nil, refer to Alokasi()
    } else {
        //if not empty, transverse to find last node
        while (Next(temp) != Nil){
            temp = Next(temp);
        }
        //connect Next(temp) to P
        Next(temp) = P;
    }
}

void DelFirst (List *L, address *P){
    //assign first node's address to P
    *P = First(*L);
    //connect First(L) to 2nd node
    First(*L) = Next(*P);
    //disconnect P from list
    Next(*P) = Nil;
}

void DelP (List *L, infotype X){
    //declare temp to store address
    address temp = First(*L);
    //look for node before info(P) = X
    while (Next(temp) != Nil && Info(Next(temp)) != X){
        temp = Next(temp);
    }
    //can use DelAfter() but will cause 1 extra step
    //check if node is found
    if (Next(temp) != Nil){
        //if found, assign next node's address to P
        address P = Next(temp);
        //connect Next(temp) to Next(P)
        Next(temp) = Next(P);
        //deallocate memory
        Dealokasi(&P);
    }
}

void DelLast (List *L, address *P){
    //declare temp to store address
    address temp = First(*L);
    //check if list is empty
    if (temp != Nil){
        //if not empty, transverse to find 2nd last node
        while (Next(Next(temp)) != Nil){
            temp = Next(temp);
        }
        //assign last node's address to P
        *P = Next(temp);
        //connect Next(temp) to Nil
        Next(temp) = Next(*P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    //assign next node's address to Pdel
    *Pdel = Next(Prec);
    //connect Next(Prec) to Next(Pdel)
    Next(Prec) = Next(*Pdel);
    //disconnect Pdel from list
    Next(*Pdel) = Nil;
}

void PrintInfo (List L){
    //declare temp to store address
    address temp = First(L);
    //check if list is empty
    if (temp != Nil){
        //if not empty, transverse to print info()
        printf("[");
        while (temp != Nil){
            printf("%d", Info(temp));
            //if next not Nil, print ","
            if (Next(temp) != Nil)printf(",");
            temp = Next(temp);
        }
        printf("]\n");
    }
    //if empty, print []
    else printf("[]\n");
}

int NbElmt (List L){
    //declare temp to store address
    address temp = First(L);
    //declare counter
    int count = 0;
    //transverse to count nodes
    while (temp != Nil){
        count++;
        temp = Next(temp);
    }
    return count;
}

infotype Max (List L){
    //declare temp to store address
    address temp = First(L);
    //declare max to store max value
    infotype max = Info(temp);
    //transverse to find max value
    while (temp != Nil){
        if (Info(temp) > max) max = Info(temp);
        temp = Next(temp);
    }
    return max;
}

address AdrMax (List L){
    //can use Max() but will cause 2 transverses
    //declare temp to store address
    address temp = First(L);
    //declare max to store max value
    infotype max = Info(temp);
    //declare maxadr to store address of max value
    address maxadr = temp;
    //transverse to find max value
    while (temp != Nil){
        if (Info(temp) > max){
            max = Info(temp);
            maxadr = temp;
        }
        temp = Next(temp);
    }
    return maxadr;
}

infotype Min (List L){
    //declare temp to store address
    address temp = First(L);
    //declare min to store min value
    infotype min = Info(temp);
    //transverse to find min value
    while (temp != Nil){
        if (Info(temp) < min) min = Info(temp);
        temp = Next(temp);
    }
    return min;
}

address AdrMin (List L){
    //can use Min() but will cause 2 transverses
    //declare temp to store address
    address temp = First(L);
    //declare min to store min value
    infotype min = Info(temp);
    //declare minadr to store address of min value
    address minadr = temp;
    //transverse to find min value
    while (temp != Nil){
        if (Info(temp) < min){
            min = Info(temp);
            minadr = temp;
        }
        temp = Next(temp);
    }
    return minadr;
}

float Average (List L){
    //declare temp to store address
    address temp = First(L);
    //declare sum to store sum of values
    float sum = 0;
    //declare count to store number of nodes
    int count = 0;
    //transverse to find sum of values and number of nodes
    while (temp != Nil){
        sum += Info(temp);
        count++;
        temp = Next(temp);
    }
    return (sum/count);
}

void InversList (List *L){
    //store 1st, 2nd node
    address P = First(*L);
    address a = P;
    address b = Next(a);
    //move shift a and b to right once then insert first a.
    while(b != Nil){
        a = b;
        b = Next(b);
        InsertFirst(L, a);
    }
    //assign ex-first node's next to Nil
    Next(P) = b;
}

void Konkat1 (List *L1, List *L2, List *L3){
    //empty L3
    CreateEmpty(L3);
    //check if L1 is empty
    if(IsEmpty(*L1)){
        //if empty, connect First(L3) to First(L2)
        First(*L3) = First(*L2);
    } else {
        //if not empty, connect First(L3) to First(L1)
        First(*L3) = First(*L1);
        //declare temp to store address
        address temp = First(*L3);
        //transverse to find last node
        while (Next(temp) != Nil){
            temp = Next(temp);
        }
        //connect Next(temp) to First(L2)
        Next(temp) = First(*L2);
    }
    //empty L1 and L2
    CreateEmpty(L1);
    CreateEmpty(L2);
}