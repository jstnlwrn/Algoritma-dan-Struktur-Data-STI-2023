#include "setlist.h"

/* *** IMPLEMENTASI *** */
address Alokasi (infotype Elmt) {
    address P = (address)malloc(sizeof(ElmtSet));
    if (P != Nil) {
        Info(P) = Elmt;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P) {
    free(*P);
}

void CreateEmpty(Set *S) {
    First(*S) = Nil;
}

boolean IsEmpty(Set S) {
    return First(S) == Nil;
}

void Insert(Set *S, infotype Elmt) {
    if (!IsMember(*S, Elmt)) {
        address P = Alokasi(Elmt);
        if (P != Nil) {
            address Last = First(*S);
            if (IsEmpty(*S)) {
                First(*S) = P;
            } else {
                while (Next(Last) != Nil) {
                    Last = Next(Last);
                }
                Next(Last) = P;
            }
        }
    }
}

void Delete(Set *S, infotype Elmt) {
    if (!IsEmpty(*S)) {
        address Prec = Nil;
        address P = First(*S);

        while (P != Nil && Info(P) != Elmt) {
            Prec = P;
            P = Next(P);
        }

        if (P != Nil) {
            if (Prec == Nil) {
                First(*S) = Next(P);
            } else {
                Next(Prec) = Next(P);
            }
            Dealokasi(&P);
        }
    }
}

boolean IsMember(Set S, infotype Elmt) {
    address P = First(S);
    while (P != Nil && Info(P) != Elmt) {
        P = Next(P);
    }
    return P != Nil;
}

int Count(Set S) {
    int count = 0;
    address P = First(S);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}
