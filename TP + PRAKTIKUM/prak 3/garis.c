#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"boolean.h"
#include"garis.h"
#include"point.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
	POINT P1, P2;
	while (true)
	{
		BacaPOINT(&P1);
		BacaPOINT(&P2);
		if (EQ(P1, P2)) printf("Garis tidak valid\n");
		else break;
	}
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

void TulisGARIS (GARIS L){
    POINT P1, P2;
    P1 = PAwal(L);
    P2 = PAkhir(L);
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(P1), Ordinat(P1), Absis(P2), Ordinat(P2));
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
/* Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
    POINT P1, P2;
    P1 = PAwal(L);
    P2 = PAkhir(L);
    return sqrt(abs((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)))+abs((Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2))));
}
/* Menghitung panjang garis L : berikan rumusnya */
// sqrt [(x2-x1)^2 + (y2-y1)^2] //

float Gradien (GARIS L){
    POINT P1, P2;
    P1 = PAwal(L);
    P2 = PAkhir(L);
    return((Ordinat(P2)-Ordinat(P1))/(Absis(P2)-Absis(P1)));   
}
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
    float grad1, grad2;
    grad1 = Gradien(L1);
    grad2 = Gradien(L2);
    return (grad1*grad2 == -1);
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

boolean IsSejajar (GARIS L1, GARIS L2){
    float grad1, grad2;
    grad1 = Gradien(L1);
    grad2 = Gradien(L2);
    return (grad1==grad2);    
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
