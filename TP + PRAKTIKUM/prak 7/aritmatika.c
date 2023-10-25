#include "aritmatika.h"

boolean IsOperator(char input){
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op){
    if (op == '+') return angka1 + angka2;
    else if (op == '-') return angka1 - angka2;
    else if (op == '*') return angka1 * angka2;
    else return angka1 / angka2;
}

int eval(char *input, int length){
    Stack S;
    CreateEmpty(&S);
    int angka1, angka2;
    int i;
    for(i=0; i<length; i++){
        if (IsOperator(input[i])){
            Pop(&S, &angka2);
            Pop(&S, &angka1);
            Push(&S, hitung(angka1, angka2, input[i]));
        } else {
            //convert val from char to int
            Push(&S, input[i] - '0'); 
            //int operation on char operate the ascii value of the char e.g. '5' - '0' = 5 in ascii 53 - 48 = 5
        }
    }
    return InfoTop(S);
}