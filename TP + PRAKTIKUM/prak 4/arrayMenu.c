#include "arrayMenu.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMenu *T){
    (*T).Neff = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMenu T){
    return T.Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabMenu T){
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabMenu T){
    return IdxMin;
}

IdxType GetLastIdx (TabMenu T){ 
    return T.Neff;
}
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabMenu T, IdxType i){
    return T.TI[i];
}
/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMenu Tin, TabMenu *Tout){
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++){
        (*Tout).TI[i] = Tin.TI[i];
    }
}
void SetEl (TabMenu *T, IdxType i, ElType v){
    (*T).TI[i] = v;
    if ((*T).Neff < i){
        (*T).Neff = i;
    }
}
void SetNeff (TabMenu *T, IdxType N){
    (*T).Neff = N;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMenu T, IdxType i){
    return ((i >= IdxMin) && (i <= IdxMax));
}
boolean IsIdxEff (TabMenu T, IdxType i){
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMenu T){
    return (T.Neff == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabMenu T){
    return (T.Neff == IdxMax);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMenu T){
    //check if empty
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    } else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%s - %s - Rp.%d\n", i, T.TI[i].nama, T.TI[i].tipe, T.TI[i].harga);
        }
    }
}
/* ********** KONSTRUKTUR MENU ********** */
ElType MakeMenu (char *nama, char *tipe, int harga){
    ElType temp;
    temp.nama = nama;
    temp.tipe = tipe;
    temp.harga = harga;
    return temp;
}

/* ********** NILAI EKSTREM ********** */
int MenuMax (TabMenu T){
    int max = T.TI[GetFirstIdx(T)].harga;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].harga > max){
            max = T.TI[i].harga;
        }
    }
    return max;
}
int MenuMin (TabMenu T){
    int min = T.TI[GetFirstIdx(T)].harga;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].harga < min){
            min = T.TI[i].harga;
        }
    }
    return min;
}

int MakananCount (TabMenu T){
    int count = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].tipe[1] == 'a'){
            count++;
        }
    }
    return count;
}

int MinumanCount (TabMenu T){
    int count = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i].tipe[1] == 'i'){
            count++;
        }
    }
    return count;
}

void MenuData (TabMenu T){
    //get makanan count
    int makananCount = MakananCount(T);
    //get minuman count
    int minumanCount = MinumanCount(T);
    //get max price
    int maxPrice = MenuMax(T);
    //get min price
    int minPrice = MenuMin(T);
    //print
    printf("Jumlah Menu Makanan: %d\n", makananCount);
    printf("Jumlah Menu Minuman: %d\n", minumanCount);
    printf("Harga Menu Termahal: Rp.%d\n", maxPrice);
    printf("Harga Menu Termurah: Rp.%d\n", minPrice);
}