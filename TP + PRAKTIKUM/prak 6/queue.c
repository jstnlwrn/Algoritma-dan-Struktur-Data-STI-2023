#include "boolean.h"
#include "queue.h"
#include <stdio.h>

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull (Queue q){
    return IDX_HEAD(q)==0 && IDX_TAIL(q)==CAPACITY-1;
}

int length(Queue q){
    if (isEmpty(q)) {
        return 0;
    }
    return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void enqueue(Queue *q, ElType val){
    //check if full
    if (IDX_TAIL(*q)==CAPACITY-1){
        //shift
        int i;
        int distance = IDX_HEAD(*q);
        for (i = 0; i < length(*q); i++){
            q->buffer[i] = q->buffer[(i + distance)];
        }
        IDX_HEAD(*q) -= distance;
        IDX_TAIL(*q) -= distance;
    }
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)++;
    }
}

void displayQueue(Queue q){
    int i;
    printf("[");
    for (i = 0; i < length(q); i++)
    {
        printf("%d", q.buffer[(i + IDX_HEAD(q))]);
        if (i < (length(q) - 1)) printf(",");
    }
    printf("]\n");
}

// int main(){
//     return 0;
// }