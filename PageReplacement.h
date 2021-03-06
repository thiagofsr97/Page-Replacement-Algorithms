/**
 *  @file    PageReplacement.h
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    05/20/2018
 *  @version 1.0
 *
 *  @brief PageReplacement Header File.
 *
 */
#ifndef UNTITLED_PAGEREPLACEMENT_H
#define UNTITLED_PAGEREPLACEMENT_H


#include <string>
#include <vector>

class PageReplacement {
private:
    int *frames;
    int frames_size;
    std::vector<int>references;
    bool *is_page_allocated;
    int allocationSize;
public:

    PageReplacement(std::string input_path);
    ~PageReplacement();
    int fifo();
    int otm();
    int lru();



};


#endif //UNTITLED_PAGEREPLACEMENT_H
