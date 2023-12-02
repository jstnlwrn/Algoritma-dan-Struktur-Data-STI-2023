#include "circular_queue.h"
#include <stdio.h>

void play(Queue *Q, boolean loop){
    //check if queue is empty
    if(IsEmpty(*Q)){
        printf("Tidak ada lagu\n");
    }
    else{
        //play song
        if(loop && !IsFull(*Q)){
            enqueue(Q, HEAD(*Q));
        }
        printf("Play lagu %d\n", dequeue(Q));
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
    //input song
        ElType song;
        scanf("%d", &song);
    //check if queue is full
    if(IsFull(*Q)){
        printf("Queue penuh\n");
    }else{
        //enqueue song
        if(song >= 0 && song <= N - 1) enqueue(Q, song);
    }
}

void queuePlaylist(Queue *Q, int playlist[][3]){
    int playlist_id;
    scanf("%d", &playlist_id);
    int i;
    for (int i = 0; i < 3; i++) {
        if (!IsFull(*Q)) {
            enqueue(Q, playlist[playlist_id][i]);
        } else {
            printf("Queue penuh\n");
            break;
        }
    }    
}

int main(){
    //get N, M value
    int N, M;
    scanf("%d %d\n", &N, &M);

    //input playlist
    int i, j;
    int playlist[M][3];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &playlist[i][j]);
            if (playlist[i][j] < 0 || playlist[i][j] > N - 1) {
                printf("Playlist tidak valid\n");
                return 0;
            }
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

