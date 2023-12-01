#include "krabbypatty.h"

void krabbyPatty (Stack *ingredients, Stack *burger){
    boolean topbun=false, botbun=false;
    Stack tempIngredients;
    CreateEmpty(&tempIngredients);
    infotype tempval;
    while(!IsEmpty(*ingredients)){
        //ambil value
        Pop(ingredients, &tempval);
        //store value
        if (tempval == 0){
            if(botbun==false)botbun = true; //kondisi 5
        } 
        else if (tempval == 9){ 
            if(topbun==false)topbun = true; //kondisi 5
        }
        //disimpan terbalik agar saat disimpan ke burger tidak terbalik
        else Push(&tempIngredients, tempval);
        //jika ada topbun dan botbun buat burger
        if (topbun && botbun){ //kondisi 1, 2
            Push(burger, 0);
            while(!IsEmpty(tempIngredients)){
                Pop(&tempIngredients, &tempval);
                Push(burger, tempval);
            }
            Push(burger, 9);
            break; //kondisi 4
        }
    }
}