#include"arraydin.h"
#include<stdio.h>
#include<stdlib.h>


/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    ArrayDin Array;
    Array.A = (ElType *)malloc(sizeof(ElType) * InitialSize);
    Array.Capacity = InitialSize;
    Array.Neff = 0;
    return Array;
}
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    int j;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			temp[j] = (*array).A[j];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			(*array).A[j] = temp[j];
		}
		free(temp);
	}
	for (j = Length(*array); j > i; j--)
	{
		(*array).A[j] = (*array).A[j - 1];
	}
	(*array).A[i] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	(*array).A[Length(*array)] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	for (i = Length(*array); i > 0; i--)
	{
		(*array).A[i] = (*array).A[i - 1];
	}
	(*array).A[0] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
	int j;
	for (j = i; j < Length(*array); j++)
	{
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}
/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
    (*array).Neff--;
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    int i;
	for (i = 0; i < Length(*array); i++)
	{
		(*array).A[i] = (*array).A[i + 1];
	}
	(*array).Neff--;
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
	int i;
	printf("[");
	if (Length(array) > 0)
	{
		for (i = 0; i < Length(array); i++)
		{
			printf("%d", array.A[i]);
			if (i < Length(array) - 1) printf(", ");
		}
	}
	printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
	int i;
	ElType *temp = (ElType *)malloc(sizeof(ElType) * Length(*array));
	for (i = 0; i < Length(*array); i++)
	{
		temp[i] = (*array).A[i];
	}
	for (i = Length(*array) - 1; i >= 0; i--)
	{
		(*array).A[i] = temp[Length(*array) - i - 1];
	}
	free(temp);
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
	int i;
	ArrayDin temp;
	temp.A = (ElType *)malloc(sizeof(ElType) * GetCapacity(array));
	temp.Neff = Length(array);
	temp.Capacity = GetCapacity(array);
	for (i = 0; i < Length(array); i++)
	{
		temp.A[i] = array.A[i];
	}
	return temp;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
	int i;
	for (i = 0; i < Length(array); i++)
	{
		if (array.A[i] == el) return i;
	}
	return -1;
}
