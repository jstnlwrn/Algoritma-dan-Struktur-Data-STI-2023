#include "map.h"
#include <stdlib.h>
#include <stdio.h>

void CreateEmpty(Map *M){
    (*M).Count = Nil;
}

boolean IsEmpty(Map M){
    return (M.Count == Nil);
}

boolean IsFull(Map M){
    return (M.Count == MaxEl);
}

valuetype Value(Map M, keytype k){
    int i;
    for(i = 0; i < M.Count; i++){
        if(M.Elements[i].Key == k){
            return M.Elements[i].Value;
        }
    }
    return Undefined;
}

void Insert(Map *M, keytype k, valuetype v){
    if(IsEmpty(*M)){
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
        (*M).Count++;
    }else{
        if(!IsMember(*M, k)){
            (*M).Elements[(*M).Count].Key = k;
            (*M).Elements[(*M).Count].Value = v;
            (*M).Count++;
        }
    }
}

void Delete(Map *M, keytype k){
    int i;
    if(!IsEmpty(*M)){
        for(i = 0; i < (*M).Count; i++){
            if((*M).Elements[i].Key == k){
                (*M).Elements[i] = (*M).Elements[(*M).Count-1];
                (*M).Count--;
            }
        }
    }
}

boolean IsMember(Map M, keytype k){
    int i;
    for(i = 0; i < M.Count; i++){
        if(M.Elements[i].Key == k){
            return true;
        }
    }
    return false;
}