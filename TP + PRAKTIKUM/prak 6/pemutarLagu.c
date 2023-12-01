#include "circular_queue.h"
#include <stdio.h>

void play(Queue *Q, boolean loop){
    //check if queue is empty
    if(IsEmpty(*Q)){
        printf("Tidak ada lagu\n");
    }
    else{
        //check if loop is true
        if(loop){
            //play song
            ElType song = dequeue(Q);
            printf("Play lagu %d\n", song);
            //enqueue song
            enqueue(Q, song);
        }
        else{
            //play song
            ElType song = dequeue(Q);
            printf("Play lagu %d\n", song);
        }
    }
}

void loopSwitch(boolean *loop){
    *loop = !(*loop);
    if(*loop){
        printf("Looping lagu\n");
    }
    else{
        printf("Tidak looping lagu\n");
    }
}

void queueSong(Queue *Q, int N){
    //check if queue is full
    if(IsFull(*Q)){
        printf("Queue penuh\n");
    }
    else{
        //input song
        ElType song;
        scanf("%d", &song);
        //enqueue song
        if(song >= 0 && song <= N - 1) enqueue(Q, song);
    }
}

void queuePlaylist(Queue *Q, Queue playlist){
    //check if queue is full
    if(IsFull(*Q)){
        printf("Queue penuh\n");
    }
    else{
        //get playlist ID
        int ID;
        scanf("%d", &ID);
        ID = 3 + 3*ID; //lagu index ke ID-3 sampai ID-1
        //check if playlist ID is valid
        if(ID <= Length(playlist) && ID-3 >= 0){
            //get song
            ElType song;
            int i, j;
            for(i = ID-3; i<= ID-1; i++){
                j = (IDX_HEAD(playlist) + i) % (IDX_MAX + 1);
                song = playlist.Tab[j];
                //enqueue song
                enqueue(Q, song);
                if(IsFull(*Q)){
                    printf("Queue penuh\n");
                    break;
                }
            }
        }
    }
}

int main(){
    //get N, M value
    int N, M;
    scanf("%d %d\n", &N, &M);
    if (N < 1 || M < 0 || M > 100){
        printf("Input tidak valid\n");
        return 0;
    } 
    //create playlist
    Queue playlist;
    CreateQueue(&playlist);
    //input song
    ElType song;
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &song);
            //check if song is valid
            if(song < 0 || song > N - 1){
                printf("Playlist tidak valid\n");
                return 0;
            }
            enqueue(&playlist, song);
        }
    }
    //create queue
    Queue Q;
    CreateQueue(&Q);
    //create loop
    boolean loop = false;
    //create command
    int command;
    //input command
    scanf("%d", &command);
    while(command != 0){
        switch(command){
            case 1:
                play(&Q, loop);
                break;
            case 2:
                loopSwitch(&loop);
                break;
            case 3:
                queueSong(&Q, N);
                break;
            case 4:
                queuePlaylist(&Q, playlist);
                break;
        }
        scanf("%d", &command);
    }
    return 0;
}