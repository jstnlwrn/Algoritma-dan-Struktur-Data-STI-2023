#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
    ElType temp[IDX_MAX+1];
    int i=0;
    while(true){
        temp[i] = dequeue(q1);
        if (IsEmpty(*q1)) break;
        i++;
    }
    while(true){
        enqueue(q2, temp[i]);
        if(i<=0)break;
        i--;
    }
}