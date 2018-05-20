
/**
 *  @file    PageReplacement.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    05/20/2018
 *  @version 1.0
 *
 *  @brief Implementation of the Page Replacement Algorithms.
 *
 */

#include <fstream>
#include <iostream>
#include <climits>
#include "PageReplacement.h"
#include "StackList.h"

/***
  * Sets the variables to default states to be ready to next algorithm.
  * @param [in] frame Pointer to an array of frames.
  * @param [in] frameSize Size of the array of frames.
  * @param [in] allocated Pointer to an array of allocated frames, either a frame is allocated or not.
  * @param [in] allocatedSize Size of the array of allocated frames.
  * @return none
  */
void reset(int *frame, int frameSize, bool* allocated, int allocatedSize){
    for(int i = 0; i < frameSize;++i)
        frame[i] = -1;

    for(int i = 0; i < allocatedSize;++i)
        allocated[i] = false;
}

/***
  * Class constructor, initiliazed with the path containing the input.
  * @param [in] input_path Path to source file.
  * @return PageReplacement object.
  */
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

/***
  * Class destructor, used to deallocated dynamic memory.
  * @param none
  * @return none.
  */
PageReplacement::~PageReplacement() {
    delete []this->is_page_allocated;
    delete []this->frames;
}


/***
  * Page Replacement algorithm using FIFO.
  * When a page fault happens, the frame selected to be replaced will be the one, among all of the frames,
  * that first received a page.
  * @param none
  * @return the number of page faults that happened during the references.
  */

int PageReplacement::fifo() {
    reset(this->frames,frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;
    int fifo = 0; //circular counter that resets when the frame size is reached

    for(int i = 0; i < references.size(); ++i){

        if(is_page_allocated[references[i]]) {
            // no page fault has happened
            continue;
        }
        page_fault++; // if referenced is not allocated, then a page fault has happeneds
        is_page_allocated[frames[fifo]] = false; // deallocating selected frame
        frames[fifo] =  references[i]; // allocating current page referenced.
        is_page_allocated[references[i]] =  true; //page is now allocated
        fifo = (fifo + 1) % frames_size; // the first frame amongst the other, is the next one.
    }

    return page_fault;


}

/***
  * Page Replacement algorithm using Optimal Algorithm.
  * When a page fault happens,the algorithm shall look into the future page references, searching
  * for the one that won't be used for the longest period of time among the pages allocated in the frames.
  * If none of the currently allocated pages in the frames will be referenced in the future, then the first frame
  * will be chosed to be replaced.
  * If one of them won't be referenced again, this is the one chosen to be replaced.
  * If two or more won't be referenced again, the first one in increasing order (by index) shall be selected.
  * @param none
  * @return the number of page faults that happened during the references.
  */
int PageReplacement::otm() {
    reset(this->frames,this->frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;
    int number_of_allocated = 0; // count to check either the frame table is full or not

    int biggest; // index indicating the frame containg the page that won't be referenced for the longest period of time.

    // Checking all the references, except for the last one, that will be insert or not using fifo algorithm.
    for(int i = 0; i < references.size() -1; ++i){
        if(is_page_allocated[references[i]]) {
            //no page fault has happened
            continue;
        }
        page_fault++; //page fault has happened

        //while there's space in the frame table, keep inserting sequentially
        if(number_of_allocated++ < frames_size){
            biggest = number_of_allocated-1;
        }
        //at this point optimal algorithm is put into work
        else{
            int to_compare[frames_size]; // keeps info of each allocated frame, cointaing the first next index in the references vector
            std::fill_n(to_compare, frames_size, INT_MAX); // initially all the values are set to infinity, assuming no reference to the current frames will be made
            biggest = 0; // for default, the first frame will be selected to be replaced

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
                    //here it means the page currently in the frame will no longer be used
                    if(j == references.size()-1){
                        if(to_compare[z]>to_compare[biggest]){
                            biggest = z;
                        }
                    }

                }
            }

        }

        is_page_allocated[frames[biggest]] = false; //deallocating the selected frame
        frames[biggest] = references[i]; // allocating the new page
        is_page_allocated[references[i]] = true; // page is now allocated

    }

    //checks if the last reference is present in the frame table
    if(!is_page_allocated[references[references.size()-1]]){
        page_fault++;
    }
    return page_fault;

}

/***
  * Page Replacement algorithm using Least Recent Used Algorithm.
  * When a page fault happens,the algorithm shall look into the past page references, searching
  * for the one that was last referenced.
  * The least recented used page is found with the support of a Stack List structured, whose implementation 
  * was made for this algorithm.
  * The top of the stack will contain the most recent page used, whereas the back will hold the least recent one.
  * @param none
  * @return the number of page faults that happened during the references.
  */
int PageReplacement::lru() {
    reset(this->frames,this->frames_size,this->is_page_allocated,this->allocationSize+1);
    int page_fault = 0;
    int number_of_allocated = 0; // count to check either the frame table is full or not
    int index = 0; // selected index in the frame table to replace with new page
    StackList stackList(frames_size); //stack list strucuture to hold the referenced pages
    
    //checking all the references
    for(int i = 0; i < references.size();i++){
        if(is_page_allocated[references[i]]){
            //no page fault has happened
            //needs to update the stack, putting the current reference at the top of it
            value_index get;
            stackList.remove(references[i],&get);
            stackList.push(get.first,get.second);
            continue;
        }
        page_fault++; //page fault has happened

        //while there's space in the frame table, keep inserting sequentially
        if(number_of_allocated++ < frames_size){
            index = number_of_allocated-1;
            stackList.push(references[i],index);
        }
        //if it get to this point, then the frame table is full, needing to replace the least recent used by the new page.
        else{            
            index = stackList.getBack().second; // index where the page will be inserted.
            stackList.popBack(); //the least recent used is poped from the stack
            stackList.push(references[i],index); //pushing the current reference to the stack and its index in the frame table
        }
        is_page_allocated[frames[index]] = false; //deallocating the selected frame
        frames[index] = references[i]; // allocating the new page
        is_page_allocated[references[i]] = true; // new page is now allocated
    }

    return page_fault;

}
