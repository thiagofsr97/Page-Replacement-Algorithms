//
// Created by thiagofsr on 19/05/18.
//

#include <iostream>
#include "StackList.h"
void reduceIndex(int *currentIndex,int tableSize){
    if(*currentIndex <= 0)
        *currentIndex = tableSize -1;
    else
        (*currentIndex)--;

}
void incrementIndex(int *currentIndex,int tableSize){
    if(*currentIndex == tableSize-1 ){
        *currentIndex = ++(*currentIndex) % tableSize;
    }
    else
        (*currentIndex)++;
}

StackList::StackList(int size) {
    this->tableSize = size;
    this->currentSize = 0;
    this->table = new value_index[size];
    this->top = 0;
    this->back = 0;

}

StackList::~StackList() {
    delete[]this->table;
}

bool StackList::push(int value,int index) {
    if(this->currentSize >= tableSize)
        return false;

    if(!(currentSize == 0 && top == 0)) {
        incrementIndex(&this->top,tableSize);
    }
    this->table[this->top] = value_index(value,index);

    this->currentSize++;


    return true;
}

value_index StackList::getBack() {
    if(currentSize > 0)
        return this->table[back];
    return value_index(-1,-1);
}

bool StackList::popBack() {
    if(currentSize <=0)
        return false;
    incrementIndex(&this->back,tableSize);
    this->currentSize--;
    return true;
}

bool StackList::remove(int value,value_index* get) {
    if(currentSize <=0) {
        return false;
    }
    bool found = false;
    int indexToRemove;
    for(int i = back,j=0;j++<currentSize;incrementIndex(&i,tableSize)){
        if(table[i].first == value){
            indexToRemove = i;
            found = true;
            break;
        }
    }

    if(!found)
        return false;
    if(get!= nullptr){
        *get = table[indexToRemove];
    }
    if(indexToRemove == back){
        incrementIndex(&this->back,tableSize);
    }
    else if(indexToRemove == top) {
        reduceIndex(&top,tableSize);
    }

    else{
        int aux = top;
        int incremented_i;
        for(int i = indexToRemove; i!=aux;incrementIndex(&i,tableSize)){

            incremented_i = i;
            incrementIndex(&incremented_i,tableSize);

            table[i] = table[incremented_i];
        }
        reduceIndex(&this->top,tableSize);
    }
    this->currentSize--;
    return true;
}

void StackList::show() {
    for(int i  = top,j = 0; j++<currentSize; reduceIndex(&i,tableSize)){
        std::cout<< table[i].first <<" " <<  i <<  std::endl;
    }

}



