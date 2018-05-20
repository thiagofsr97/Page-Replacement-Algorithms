/**
 *  @file    main.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    05/20/2018
 *  @version 1.0
 *
 *  @brief Main
 *
 */
#include <iostream>
#include "PageReplacement.h"

int main() {
    PageReplacement pageReplacement("input.txt");
    std::cout << "FIFO "<< pageReplacement.fifo()<< std::endl;
    std::cout << "OTM "<< pageReplacement.otm()<< std::endl;
    std::cout << "LRU "<< pageReplacement.lru()<< std::endl;
    return 0;
}