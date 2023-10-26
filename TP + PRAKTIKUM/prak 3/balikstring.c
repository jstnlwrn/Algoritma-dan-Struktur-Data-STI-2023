// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch)
{
    int count = 0;
    while (*ch != '\0')
    {
        count += 1;
        ch += 1;
    }
    return count;
}
// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str){
    int count =panjangString(str), i;
    char temp[count];
    for (i=0; i<count; i++){
        temp[i]=str[count-i-1];
    }
    for (i=0; i<count; i++){
        str[i] = temp[i];
    }
}