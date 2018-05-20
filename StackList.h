/**
 *  @file    StackList.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    05/20/2018
 *  @version 1.0
 *
 *  @brief StackList Header file.
 *
 */

#ifndef PAGE_REPLACEMENT_ALGORITHMS_STACKLIST_H
#define PAGE_REPLACEMENT_ALGORITHMS_STACKLIST_H
typedef std::pair<int,int> value_index;

class StackList {

private:
    value_index *table;
    int tableSize;
    int currentSize;
    int top;
    int back;
public:
    StackList(int size);
    ~StackList();
    bool push(int value,int index);
    value_index getBack();
    bool popBack();
    bool remove(int value,value_index* get);
    void show();


};


#endif //PAGE_REPLACEMENT_ALGORITHMS_STACKLIST_H
