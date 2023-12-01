#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    //create songHist
    Stack songHist;
    CreateEmpty(&songHist);
    //get number of songs
    int n;
    scanf("%d", &n);
    //get song names
    char lagu[10][20];
    int i;
    for (i=0; i<n; i++){
        scanf("%s", lagu[i]);
    }
    //get number of operations
    int query;
    scanf("%d", &query);
    //loop
    int op;
    int songId;
    for (i=0; i<query; i++){
        scanf("%d", &op);
        if (op==1){
            scanf("%d", &songId);
            Push(&songHist, songId);
            printf("Playing: %s\n", lagu[songId]);
        }
        else if (op==2){
            if (IsEmpty(songHist)){
                printf("No music is played\n");
            }
            else{
                Pop(&songHist, &songId);
                if (IsEmpty(songHist)){
                    printf("No music is played\n");
                }
                else{
                    printf("Playing: %s\n", lagu[Top(songHist)]);
                }
            }
        }
    }
    return 0;
}