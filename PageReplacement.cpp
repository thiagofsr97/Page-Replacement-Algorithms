//
// Created by thiagofsr on 18/05/18.
//

#include <fstream>
#include <iostream>
#include <climits>
#include "PageReplacement.h"
#include "StackList.h"

void reset(int *frame, int frameSize, bool* allocated, int size){
    for(int i = 0; i < frameSize;++i)
        frame[i] = -1;

    for(int i = 0; i < size;++i)
        allocated[i] = false;
}

PageReplacement::PageReplacement(std::string input_path) {
    std::fstream file(input_path,std::ios::in);
    if(!file.is_open()){
        std::cout<<"Error opening file, check out path" << std::endl;
        exit(1);
    }
    file >> this->frames_size;

    this->frames = new int[this->frames_size];
    int reference;
    this->allocationSize = -1;
    while(file >> reference){
        if(reference > this->allocationSize)
            this->allocationSize = reference;
        this->references.push_back(reference);

    }

    this->is_page_allocated = new bool[this->allocationSize + 1];

}

int PageReplacement::fifo() {
    reset(this->frames,frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;


    int fifo = 0;
    // the left references must follow the fifo algorithm in order to be allocated in each frame
    for(int i = 0; i < references.size(); ++i){

        if(is_page_allocated[references[i]]) {
            continue;
        }
        is_page_allocated[frames[fifo]] = false;
        frames[fifo] =  references[i];

        is_page_allocated[references[i]] =  true;
        page_fault++;
        fifo = (fifo + 1) % frames_size;

    }

    return page_fault;


}

PageReplacement::~PageReplacement() {
    delete []this->is_page_allocated;
    delete []this->frames;

}

int PageReplacement::otm() {
    reset(this->frames,this->frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;
    int number_of_allocated = 0;

    int biggest;

    // the left references except for the last must follow the otm algorithm in order to be allocated in each frame
    for(int i = 0; i < references.size() -1; ++i){
        if(is_page_allocated[references[i]]) {
            continue;
        }
        page_fault++;
        if(number_of_allocated++ < frames_size){
            biggest = number_of_allocated-1;
        }else{
            int to_compare[frames_size];
            std::fill_n(to_compare, frames_size, INT_MAX);
            biggest = 0;
            //looking for the page which is not going to be used for a long time
            for(int z =0;z < frames_size;z++){
                for(int j =i+1;j<references.size();j++){
                    if(frames[z]==references[j]){
                        to_compare[z] = j;
                        if(to_compare[z] > to_compare[biggest]){
                            biggest = z;
                        }
                        break;
                    }
                    //here it means the reference will no longer be used, so it must be the one to be removed from the frame table
                    if(j == references.size()-1){
                        biggest = z;
                    }

                }
            }

        }

        is_page_allocated[frames[biggest]] = false;
        frames[biggest] = references[i];
        is_page_allocated[references[i]] = true;


    }

    //checks if the last reference is present in the frame table
    if(!is_page_allocated[references[references.size()-1]]){
        page_fault++;

    }
    return page_fault;

}

int PageReplacement::lru() {
    reset(this->frames,this->frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;
    int number_of_allocated = 0;
    int index = 0;
    StackList stackList(frames_size);
    for(int i = 0; i < references.size();i++){
        if(is_page_allocated[references[i]]){
            //needs to update the stack, putting the value at the top of it
            value_index get;
            stackList.remove(references[i],&get);
            stackList.push(get.first,get.second);
            continue;
        }
        page_fault++;
        if(number_of_allocated++ < frames_size){
            index = number_of_allocated-1;
            stackList.push(references[i],index);
        }
        else{
            //if it get to this point, then the frame table is full, needing to replace the least recent used by the new page.
            index = stackList.getBack().second; // index where the page will be inserted.
            stackList.popBack();
            stackList.push(references[i],index);
        }
        is_page_allocated[frames[index]] = false;
        frames[index] = references[i];
        is_page_allocated[references[i]] = true;
    }

    return page_fault;

}
