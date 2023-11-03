#include "duplicates.h"

boolean hasDuplicate(int n, int *nums, int k){
    //declare hashmap
    HashMap M;
    CreateEmpty(&M);
    //tranverse nums
    int i;
    for(i=0; i<n; i++){
        //check duplicate nums value
        if (Value(M, nums[i]) != Undefined){
            //find the difference
            if (i - Value(M, nums[i]) <= k){
                return true;
            }
        }
        //if not duplicate, insert to hashmap
        else Insert(&M, nums[i], i); //input val from num as key and i as value
    }
    return false;
}