//
// Created by thiagofsr on 19/05/18.
//

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
