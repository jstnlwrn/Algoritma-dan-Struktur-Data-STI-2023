/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "boolean.h"
#include "point.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X,Y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    return (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
    
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
    if(Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2)){
        return false;
    }
    return true;
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    if(Absis(P)==0 && Ordinat(P)==0){return true;}
    return false;
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
    return(Absis(P)==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
    return(Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
    if(Absis(P)>0 && Ordinat(P)>0){
        return 1;
    }
    else if(Absis(P)<0 && Ordinat(P)>0){
        return 2;
    }
    else if(Absis(P)<0 && Ordinat(P)<0){
        return 3;
    }
    else if(Absis(P)>0 && Ordinat(P)>0){
        return 4;
    }    
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) = Absis(P)+deltaX;
    Ordinat(P) = Ordinat(P)+deltaY;
    return P;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void Geser (POINT *P, float deltaX, float deltaY){
    *P = PlusDelta(*P, deltaX, deltaY );
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
float Jarak0 (POINT P){
    return sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
    return sqrt(abs((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)))+abs((Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2))));

}
/* Menghitung panjang garis yang dibentuk P1 dan P2. */

