#include <iostream>
#include "PageReplacement.h"

int main() {
    PageReplacement pageReplacement("test.txt");
   // std::cout << "Fifo "<< pageReplacement.fifo() << std::endl;
    std::cout << "OTM "<< pageReplacement.lru()<< std::endl;

    return 0;
}