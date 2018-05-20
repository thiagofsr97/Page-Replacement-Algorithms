/**
 *  @file    StackList.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    05/20/2018
 *  @version 1.0
 *
 *  @brief Implementation of a static Stack List using circular indexing.
 *
 */

#include <iostream>
#include "StackList.h"

/***
  * Decrements the current index, respecting the limits of the array and its circular indexing property.
  * @param [in,out] currentIndex Pointer to index.
  * @param [in] table Size of Stack.
  * @return none
  */
void reduceIndex(int *currentIndex,int tableSize){
    if(*currentIndex <= 0)
        *currentIndex = tableSize -1;
    else
        (*currentIndex)--;

}

/***
  * Increments the current index, respecting the limits of the array and its circular indexing property.
  * @param [in,out] currentIndex Pointer to index.
  * @param [in] table Size of Stack.
  * @return none
  */
void incrementIndex(int *currentIndex,int tableSize){
    if(*currentIndex == tableSize-1 ){
        *currentIndex = ++(*currentIndex) % tableSize;
    }
    else
        (*currentIndex)++;
}

/***
  * StackList constructor. Allocates an array represeting the stack.
  * @param [in] size Size of the stack.
  * @return StackList object.
  */
StackList::StackList(int size) {
    this->tableSize = size;
    this->currentSize = 0;
    this->table = new value_index[size];
    this->top = 0;
    this->back = 0;

}

/***
  * StackList destructor, deallocates dynamic memory.
  * @param none
  * @return none
  */
StackList::~StackList() {
    delete[]this->table;
}

/***
  * Push a new value to the stack, this value shall be the top of it.
  * @param [in] value first argument of a pair representing the value.
  * @param [in] index second argument of a pair representing the index of the value in the frame table.
  * @return true if pair was successfully pushed, false if was not.
  */
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

/***
  * It gets the back of the stack list, representing the least recent used page.
  * @param [in] none
  * @return pair representing the lru page if it is there, pair with two negative values if it's not there.
  */
value_index StackList::getBack() {
    if(currentSize > 0)
        return this->table[back];
    return value_index(-1,-1);
}

/***
  * It pops the back from the stack list, representing the least recent used page.
  * @param [in] none
  * @return true if was sucessfully removed,false if was not.
  */
bool StackList::popBack() {
    if(currentSize <=0)
        return false;
    incrementIndex(&this->back,tableSize);
    this->currentSize--;
    return true;
}

/***
  * Removes a value from the stack, here behaving as a list.
  * @param [in] value first argument of a pair representing the value to be removed.
  * @param [out] get Pointer to a pair <value,index>, storing the pair to be removed from stack
  * @return true if pair was successfully removed, false if was not.
  */
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

/***
  * Prints the whole stack to the console.
  * @param none
  * @return none
  */

void StackList::show() {
    for(int i  = top,j = 0; j++<currentSize; reduceIndex(&i,tableSize)){
        std::cout<< table[i].first <<" " <<  i <<  std::endl;
    }

}



