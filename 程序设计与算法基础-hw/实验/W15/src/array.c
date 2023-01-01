#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array array_create(){
    Array a;
    int *p=(int *)malloc(sizeof(int)*BLOCK_SIZE);
    a.content=p;
    a.size=BLOCK_SIZE;
    return a;
}
void array_free(Array* array){
    free(array->content);
    array->content=NULL;
    array->size=0;
}

int array_size(const Array *array){
    return array->size;
}
void array_inflate(Array *array){
    int nsize=array->size+BLOCK_SIZE;
    int *p=(int *)malloc(sizeof(int)*nsize);
    for(int i=0;i<array->size;i++){
        p[i]=array->content[i];
    }
    free(array->content);
    array->content=p;
    array->size=nsize;
}

int array_get(const Array *array, int index){
    return array->content[index];
}
void array_set(Array *array, int index, int value){
    array->content[index]=value;
}

Array array_clone(const Array *array){
    Array b;
    b.size=array->size;
    int *p=(int *)malloc(sizeof(int)*array->size);
    for(int i=0;i<array->size;i++){
        p[i]=array->content[i];
    }
    b.content=p;
    return b;
}
