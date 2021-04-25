

#include "QP.hpp"
#include <iostream>

int main(){

    // just for testing purposes. Main will be a separate program for my final submission.
    QashTable table(10);
    table.insert(11);
    table.insert(1);
    table.insert(10);
    table.print();
    std::cout << table.search(1);

    return 0;
}