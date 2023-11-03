#include "warehouse.h"
#include <stdio.h>

void manageWareHouse(Map *wareHouse){
    int n=0;
    while(true){
        //input n
        scanf("%d", &n);
        //EOP
        if(n==4)break;
        // n = 1
        else if(n==1){
            //print item
            int i;
            for(i=0; i<(*wareHouse).Count; i++){
                printf("Bahan %d: %d\n", (i+1), (*wareHouse).Elements[i].Value);
            }
        }
        // n = 2
        else if (n==2){
            //input n
            scanf("%d", &n);
            //tranverse n
            int val;
            while(n>0){
                //collect 1 digits of n
                val = n%10;
                //delete  1 digits of n
                n /= 10;
                //check stock
                if ((*wareHouse).Elements[val-1].Value==0){ //empty
                    //print habis
                    printf("Stok bahan %d sudah habis\n", val);
                }
                else{ //not empty
                    //barang ke-val --;    
                    (*wareHouse).Elements[val-1].Value --;                
                }
            }
        }
        // n = 3
        else if (n==3){
            //input n
            scanf("%d", &n);
            //tranverse n
            int val;
            while(n>0){
                //collect 1 digits of n
                val = n%10;
                //delete  1 digits of n
                n /= 10;
                //barang ke-val ++;
                (*wareHouse).Elements[val-1].Value ++;
            }            
        }
    }
}