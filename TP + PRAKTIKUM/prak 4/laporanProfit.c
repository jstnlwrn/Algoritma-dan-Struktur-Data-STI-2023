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

int tempProfit(List L){
    int i;
    int temp=0;
    int max=0;
    for (i=FirstIdx(L); i<=LastIdx(L); i++){
        //check if temp + get(L, i) < 0
        if (temp + Get(L, i) < 0){
            //set temp to 0
            temp = 0;
        } else {
            //add temp with get(L, i)
            temp += Get(L, i);
        }
        //check if temp > max
        if (temp > max){
            //set max to temp
            max = temp;
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
            //change value with index P to X
            Set(&L, P, X);
        } else if (query == 1){
            //check if list not empty
            if (!IsEmpty(L)){
                //print list
                PrintInfo(L);
            }
        } else if (query == 2){
            //get P, X
            scanf("%d %d\n", &P, &X);
            //add value X to index P
            InsertAt(&L, X, P);
            
        } else if (query == 3){
            //get P
            scanf("%d\n", &P);
            //delete value with index P
            DeleteAt(&L, P);
            
        } else if (query == 4){
            //get temp profit
            printf("%d\n", tempProfit(L));
        }
    }
    return 0;
}