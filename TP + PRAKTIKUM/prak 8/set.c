#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    S->Elements[S->Count] = Elmt;
    S->Count++;
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = S->Elements[iterator];
    }
    S->Count--;
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

Set SetUnion(Set s1, Set s2){
    Set U;
    CreateEmpty(&U);
    int i;
    //insert s1
    for(i=0; i<s1.Count; i++){
        Insert(&U, s1.Elements[i]);
    }
    //insert s2
    for(i=0; i<s2.Count; i++){
        Insert(&U, s2.Elements[i]);
    }
    return U;
}

Set SetIntersection(Set s1, Set s2){
    Set U;
    CreateEmpty(&U);
    int i;    
    //transverse 1 set
    for(i=0; i<s1.Count; i++){
        //if intersect, insert to U
        if(IsMember(s2, s1.Elements[i]))Insert(&U, s1.Elements[i]);
    }
    return U;
}

Set SetSymmetricDifference(Set s1, Set s2){
    Set U;
    CreateEmpty(&U);
    int i;    
    //transverse 1 set
    for(i=0; i<s1.Count; i++){
        //if not intersect, insert to U
        if(!IsMember(s2, s1.Elements[i]))Insert(&U, s1.Elements[i]);
    }
    for(i=0; i<s2.Count; i++){
        //if not intersect, insert to U
        if(!IsMember(s1, s2.Elements[i]))Insert(&U, s2.Elements[i]);
    }
    return U;    
}    

Set SetSubtract(Set s1, Set s2){
    Set U;
    CreateEmpty(&U);
    int i;    
    //transverse 1 set
    for(i=0; i<s1.Count; i++){
        //if not intersect, insert to U
        if(!IsMember(s2, s1.Elements[i]))Insert(&U, s1.Elements[i]);
    }
    return U;        
}