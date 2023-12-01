#include "asteroid.h"
#include <stdio.h>
#include <stdlib.h>

boolean isCollision(infotype a, infotype b){
    return (a>0 && b<0);
}

void collision(int n, infotype *asteroids, Stack *remaining){
    //push first asteroid
    Push(remaining, asteroids[0]);
    //loop
    int i;
    int trash;
    for(i=1; i<n; i++){
        //check if collided
        if(isCollision(InfoTop(*remaining), asteroids[i])){
            //collided
            while(true){
                //check which one is bigger
                if(abs(asteroids[i])>abs(InfoTop(*remaining))){ //condition 1
                    //top destroyed
                    Pop(remaining, &trash);
                }else if(abs(asteroids[i])==abs(InfoTop(*remaining))){
                    //both destroyed
                    Pop(remaining, &trash);
                    //skip to next asteroid
                    break;
                }else{ 
                    //asteroid destroyed, go to next asteroid
                    break;
                }
                //exit loop for condition 1
                if(IsEmpty(*remaining) || !isCollision(InfoTop(*remaining), asteroids[i])){
                    //push asteroid
                    Push(remaining, asteroids[i]);
                    break;
                }
            }
        }else{
            //push asteroid
            Push(remaining, asteroids[i]);
        }
    }
}

void displayAsteroids(Stack S){
    printf("[");
    if(!IsEmpty(S)){
        Stack temp;
        CreateEmpty(&temp);
        infotype tempAsteroid;
        while(!IsEmpty(S)){
            Pop(&S, &tempAsteroid);
            Push(&temp, tempAsteroid);
        }
        while(!IsEmpty(temp)){
            Pop(&temp, &tempAsteroid);
            printf("%d", tempAsteroid);
            if(!IsEmpty(temp)){
                printf(",");
            }
            Push(&S, tempAsteroid);
        }
    }
    printf("]\n");
}

// int main(){
//     int asteroids[] = {1, 2, -3, 4, 5, -5, 6, -4, -10, 11, 12, 13};
//     int n = sizeof(asteroids)/sizeof(asteroids[0]);
//     Stack remaining;
//     collision(n, asteroids, &remaining);
//     displayAsteroids(remaining);
//     return 0;
// }