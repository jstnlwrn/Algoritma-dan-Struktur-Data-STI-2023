#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void PrintInfo(List L){
    int i;
    for (i=FirstIdx(L); i<=LastIdx(L); i++){
        printf("%d", Get(L, i));
        if (i != LastIdx(L)) printf(" ");
    }
    printf("\n");
}

int MaxProfit(List L){
    int i;
    int max=0;
    for (i=FirstIdx(L); i<=LastIdx(L); i++){
        //check if max + get(L, i) < 0
        if (max + Get(L, i) < 0){
            //set max to 0
            max = 0;
        } else {
            //add max with get(L, i)
            max += Get(L, i);
        }
    }
    return max;
}

int main(){
    //input N, Q value as int
    int N, Q;
    scanf("%d %d\n", &N, &Q);
    //input val to list
    List L = MakeList();
    int i;
    int val;
    for (i=0; i<N; i++){
        scanf("%d", &val);
        InsertLast(&L, val);
    }
    //get query
    int query;
    int P, X;
    for (i=0; i<Q; i++){
        scanf("%d", &query);
        //check if query 0 to 4
        if(query == 0){
            //get P, X
            scanf("%d %d\n", &P, &X);
            //check if P is valid
            if (IsIdxValid(L, P)){
                //change value with index P to X
                Set(&L, P, X);
            }
        } else if (query == 1){
            //check if list not empty
            if (!IsEmpty(L)){
                //print list
                PrintInfo(L);
            }
        } else if (query == 2){
            //get P, X
            scanf("%d %d\n", &P, &X);
            //check if P is valid
            if (IsIdxValid(L, P)){
                //add value X to index P
                InsertAt(&L, X, P);
            }
        } else if (query == 3){
            //get P
            scanf("%d\n", &P);
            //check if P is valid
            if (IsIdxValid(L, P)){
                //delete value with index P
                DeleteAt(&L, P);
            }
        } else if (query == 4){
            //get max profit
            printf("%d\n", MaxProfit(L));
        }
    }
    return 0;
}