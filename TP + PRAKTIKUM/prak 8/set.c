#include"set.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void CreateEmpty(Set *S){
    (*S).Count = 0;
}

boolean IsEmpty(Set S){
    return (S.Count == 0);
}

boolean IsFull(Set S){
    return (S.Count == MaxEl);
}

void Insert(Set *S, infotype Elmt){
    if(IsEmpty(*S)){
        (*S).Elements[0] = Elmt;
        (*S).Count++;
    }else{
        if(!IsMember(*S, Elmt)){
            (*S).Elements[(*S).Count] = Elmt;
            (*S).Count++;
        }
    }
}

void Delete(Set *S, infotype Elmt){
    int i;
    if(!IsEmpty(*S)){
        if(IsMember(*S, Elmt)){
            for(i = 0; i < (*S).Count; i++){
                if((*S).Elements[i] == Elmt){
                    (*S).Elements[i] = (*S).Elements[(*S).Count-1];
                    (*S).Count--;
                }
            }
        }
    }
}

boolean IsMember(Set S, infotype Elmt){
    int i;
    for(i = 0; i < S.Count; i++){
        if(S.Elements[i] == Elmt){
            return true;
        }
    }
    return false;
}