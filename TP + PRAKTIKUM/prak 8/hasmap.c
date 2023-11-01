#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>

void CreateEmpty(HashMap *M){
    //empty key & value
    int i;
    for(i = 0; i < MaxEl; i++){
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
    //empty count
    (*M).Count = Nil;
}

address Hash(keytype K){
    return K % MaxEl;
}

valuetype Value(HashMap M, keytype k){
    int idx;
    for(idx = 0; idx < MaxEl; idx++){
        if(M.Elements[idx].Key == k){
            return M.Elements[idx].Value;
        }
    }
    return Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v){
    //check empty index and duplicate key
    address idx = Hash(k);
    boolean keyfound = false;
    // check if index hash k is occupied, if occupied, find the next empty index
    while((*M).Elements[idx].Key != Undefined){
        if ((*M).Elements[idx].Key == k){
            keyfound = true;
            break;
        }
        idx++;
        idx%=MaxEl;
    }
    if (!keyfound){
        //input key & value
        (*M).Elements[idx].Key = k;
        (*M).Elements[idx].Value = v;
        (*M).Count++;    
    }
}
