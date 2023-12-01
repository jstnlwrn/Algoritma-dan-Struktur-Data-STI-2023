#include "dividequeue.h"

void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue){
    Queue temp;
    CreateQueue(&temp);
    ElType val;
    while(true){
        //break
        if(isEmpty(*queue)) break;
        //ambil value
        dequeue(queue, &val);
        enqueue(&temp, val);
        //even
        if(TAIL(temp)%2 == 0){    
            enqueue(evenQueue, val);
        }
        //odd
        else{
            enqueue(oddQueue, val);
        }
    }
    while(true){
        if(isEmpty(temp)) break;
        dequeue(&temp, &val);
        enqueue(queue, val);
    }
}

// int main(){
//     return 0;
// }